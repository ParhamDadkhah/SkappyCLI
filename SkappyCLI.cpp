#include <iostream>
#include <cryptopp/sha.h>
#include <fstream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/rijndael.h>
#include <cryptopp/modes.h>
#include <cryptopp/files.h>
#include <cryptopp/osrng.h>
#include <cryptopp/hex.h>
/*
void loadfile()
{
	std::string path;
	std::cout << "gib path: ";
	std::cin >> path;
	std::ifstream inputfile(path, std::ifstream::binary);
	while (inputfile.good())
	{
		char block[1024];
		std::streamsize length = 1024;
		inputfile.read(block, length);
		std::cout.write(block, inputfile.gcount());
	}
	inputfile.close();
}
*/

#define DEBUG
#ifdef DEBUG
std::string Path = "C:\\Users\\RSKALA\\Desktop\\salam.txt";
std::string Key = "THISISAKEY";
#endif // DEBUG

CryptoPP::SecByteBlock GenerateKey(std::string PassPhrase)
{
	using namespace CryptoPP;
	SHA256 HashObj;
	std::string Hash;
	StringSource(PassPhrase, true, new HashFilter(HashObj, new StringSink(Hash)));
	SecByteBlock KeyHashed(reinterpret_cast<const byte*>(&Hash[0]), Hash.size());
	return KeyHashed;
}

CryptoPP::SecByteBlock GenerateIv()
{
	using namespace CryptoPP;
	AutoSeededRandomPool prng;
	SecByteBlock Iv(AES::BLOCKSIZE);
	prng.GenerateBlock(Iv, Iv.size());
	return Iv;
}
void WriteIvToFileBeginning(CryptoPP::SecByteBlock* Iv, std::ofstream* OutputFile)
{
	using namespace CryptoPP;
	ArraySource(*Iv, Iv->size(), true, new FileSink(*OutputFile));
}
void BeginEncrypt()
{
	system("cls");
	
	#ifndef DEBUG
	std::string Path;
	std::cout << "gib path: ";
	std::cin >> Path;
	std::string Key;
	std::cout << "gib key: ";
	std::cin >> Key;
	#endif

	using namespace CryptoPP;
	SecByteBlock Iv = GenerateIv();
	SecByteBlock KeyHashed = GenerateKey(Key);
	
	CFB_Mode<AES>::Encryption EncryptObj;

	EncryptObj.SetKeyWithIV(KeyHashed, KeyHashed.size(), Iv);

	std::ifstream InputFile(Path, std::ios_base::binary);
	std::ofstream OutputFile(Path + ".skappy", std::ios_base::binary);
	WriteIvToFileBeginning(&Iv, &OutputFile);
	
	FileSource Encryption(InputFile, false, new StreamTransformationFilter(EncryptObj, new FileSink(OutputFile)));
	
	while (!InputFile.eof() && !Encryption.SourceExhausted())
	{
		Encryption.Pump(1024);
	}

	OutputFile.close();
	InputFile.close();

}
void BeginDecrypt();


void PrintWelcome()
{
	system("cls");
	using namespace std;
	cout << "Hello and welcome to Skappy. Skappy will encrypt whatever file you desire with AES-CFB-256 to make sure your file is secure." << endl;
	cout << "Please select an option:" << endl << "[1] Encrypt\n[2] Decrypt\n[3] Exit\n";
}

int main()
{
	/*
	int Option;
	do
	{
		PrintWelcome();
		std::cin >> Option;
	} while (Option > 3 && Option < 0);

	switch (Option)
	{
		case 1:
			BeginEncrypt();
			break;
		case 2:
			BeginDecrypt();
			break;
		case 3:
			return 0;
			break;
	}
	*/
	BeginEncrypt();
	
	return 0;
}