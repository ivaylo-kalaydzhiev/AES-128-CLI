#include <iostream>
#include <string>
#include <fstream>

class AESCryptographer {
private:
    static const int KEY_SIZE = 16;
    static const int ROUNDS = 9;
    static const int BLOCK_SIZE = 16;

    // I might want to change this
    static unsigned char weakHash(const std::string& input) {
        unsigned char hash = 0;
        for (char c : input) {
            hash ^= (unsigned char)(c);
        }
        return hash;
    }

    static void passwordToKey(const std::string& password, unsigned char* key) {
        unsigned char derivedKey[KEY_SIZE];
        for (int i = 0; i < KEY_SIZE; i++) {
            derivedKey[i] = weakHash(password + std::to_string(i));
        }
        std::memcpy(key, derivedKey, KEY_SIZE);
    }

public:
    static void encrypt(std::ifstream& src,
                        std::ofstream& dst,
                        const std::string& password) {
        // Transform user password to key
        // Assuming 16-byte key for AES-128
        unsigned char key[KEY_SIZE];
        passwordToKey(password, key);

        // Calculate file size in bytes
        src.seekg(0, std::ios::end);
        size_t fileSize = src.tellg();

        // Return pointer to beginning
        src.seekg(0, std::ios::beg);

        // Buffer to hold one block of data (16 bytes for AES-128)
        unsigned char block[BLOCK_SIZE];

        // Process file in blocks
        while (fileSize >= BLOCK_SIZE) {
            // Read a block of data from the file
            src.read(reinterpret_cast<char*>(block), BLOCK_SIZE);

            // Encrypt the block using AES
            // Implement AES encryption rounds here: AddRoundKey, SubBytes, ShiftRows, MixColumns (omit MixColumns in the last round)

            // Write the encrypted block to the destination file
            dst.write(reinterpret_cast<char*>(block), BLOCK_SIZE);

            fileSize -= BLOCK_SIZE;
        }
    }

    static void decrypt(std::ifstream& src,
                        std::ofstream& dst,
                        const std::string& password) {
        std::cout << "Decrypt not implemented" << std::endl;
    }
};

class FileManager {
public:
    static void printFileContents(const std::string& fileName) {
        std::ifstream file(fileName);

        if (!file.is_open()) {
            std::cout << "Unable to open file: " << fileName << std::endl;
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }

        file.close();
    }

    static void encryptFile(const std::string& srcFileName,
                            const std::string& dstFileName,
                            const std::string& password) {
        if (srcFileName == dstFileName) {
            std::cout << "Source file and destination file can not be the same" << std::endl;
            return;
        }

        std::ifstream srcFile(srcFileName);
        std::ofstream dstFile(dstFileName);

        if (!srcFile.is_open()) {
            std::cout << "Unable to open file: " << srcFileName << std::endl;
            return;
        } else if (!dstFile.is_open()) {
            std::cout << "Unable to open file: " << dstFileName << std::endl;
            return;
        }

        AESCryptographer::encrypt(srcFile, dstFile, password);

        srcFile.close();
        dstFile.close();
    }

    static void decryptFile(const std::string& srcFileName,
                            const std::string& dstFileName,
                            const std::string& password) {
        if (srcFileName == dstFileName) {
            std::cout << "Source file and destination file can not be the same" << std::endl;
            return;
        }

        std::ifstream srcFile(srcFileName);
        std::ofstream dstFile(dstFileName);

        if (!srcFile.is_open()) {
            std::cout << "Unable to open file: " << srcFileName << std::endl;
            return;
        } else if (!dstFile.is_open()) {
            std::cout << "Unable to open file: " << dstFileName << std::endl;
            return;
        }

        AESCryptographer::decrypt(srcFile, dstFile, password);

        srcFile.close();
        dstFile.close();
    }
};


class Program {
private:
    static void displayMainMenu() {
        std::cout << "Chose menu option:" << std::endl
                  << "(1) Print file contents" << std::endl
                  << "(2) Encrypt file contents" << std::endl
                  << "(3) Decrypt file contents" << std::endl
                  << "(4) Exit Command Line Tool" << std::endl;
    }

    static int readInt() {
        int n;
        std::cin >> n;
        return n;
    }

    static void enterPrintFileFlow() {
        std::cout << "Enter file name: ";
        std::string fileName;
        std::cin >> fileName;
        FileManager::printFileContents(fileName);
    }

    static void enterEncryptFileFlow() {
        // Ask for file name
        std::cout << "Enter file name: ";
        std::string srcFileName;
        std::cin >> srcFileName;

        // Ask for password
        std::cout << "Enter encryption password: ";
        std::string password;
        std::cin >> password;

        // Ask for destination file name
        std::cout << "Enter destination file name: ";
        std::string dstFileName;
        std::cin >> dstFileName;

        // Make the FileManger encrypt it
        FileManager::encryptFile(srcFileName, dstFileName, password);
    }

    static void enterDecryptFileFlow() {
        // Ask for file name
        std::cout << "Enter file name: ";
        std::string srcFileName;
        std::cin >> srcFileName;

        // Ask for password
        std::cout << "Enter encryption password: ";
        std::string password;
        std::cin >> password;

        // Ask for destination file name
        std::cout << "Enter destination file name: ";
        std::string dstFileName;
        std::cin >> dstFileName;

        // Make the FileManger encrypt it
        FileManager::decryptFile(srcFileName, dstFileName, password);
    }

    static void exitCLIFlow() {
        std::cout << "You chose to leave... sad!" << std::endl;
    }

public:
    static void enterMainMenuFlow() {
        displayMainMenu();

        int choice = readInt();
        switch (choice) {
            case 1:
                enterPrintFileFlow();
                enterMainMenuFlow();
                break;
            case 2:
                enterEncryptFileFlow();
                enterMainMenuFlow();
                break;
            case 3:
                enterDecryptFileFlow();
                enterMainMenuFlow();
                break;
            case 4:
                exitCLIFlow();
                return;
            default:
                enterMainMenuFlow();
        }
    }
};

int main() {
    Program::enterMainMenuFlow();

    return 0;
}