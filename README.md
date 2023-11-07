# SkappyCLI 
## Skappy will encrypt whatever file you desire with AES-CFB-256 to make sure your file is secure.

If you have files where you want to make sure they are secure and cannot be accessed without your premission, Skappy can help you.
Skappy has the following features:
* It uses AES CFB with a 256 bit key to make sure its unbreakable.
* It's written in C++ which makes the encryption and decryption operation FAST.
* Its simple to use and straightforward.
* Uses the [CryptoPP](https://www.cryptopp.com/) library.

What i have in plan for future features:
* Running the program with cmd and input arguments.
* Mutli-threading for large files.
* Graphical interface.

## How to use the program:
You can either use the latest [release](https://github.com/ParhamDadkhah/SkappyCLI/releases) or compile your own.
To compile your own make sure you have both VS and vcpkg installed and configured, then do the following:
1. Clone the project in VS.
2. Install CryptoPP library with `vcpkg install CryptoPP`
3. Build the project.

The rest is pretty straight forward
