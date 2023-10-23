#include <iostream>
#include <cryptopp/sha.h>
#include <fstream>
std::string GenerateKey(std::string PassPhrase);
void BeginEncrypt();
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
	std::string path;
	std::cout << "gib path: ";
	std::cin >> path;
	char* contents;
	std::ifstream inputfile(path);
	char c;
	while (inputfile.good())
	{
		std::streambuf* bufferptr = inputfile.rdbuf();
		std::streamsize  buffersize = 1024;
		contents = new char[buffersize];
		int size = bufferptr->sgetn(contents, buffersize);
		//std::cout << size;
		std::cout.write(contents, buffersize);
		inputfile.get(c);
	}
	inputfile.close();
	return 0;
}