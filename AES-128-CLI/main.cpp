#include <iostream>
#include <string>
#include <fstream>

// TODO
// Make classes that don't need to be classes into namespaces
// Make better hashing from password to key
// Remove STL functions/ classes
// Do I need to remove memcpy?

class AESCryptographer {
private:
    // AES Constants
    constexpr static unsigned char S_BOX[256] = {
         0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
         0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
         0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
         0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
         0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
         0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
         0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
         0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
         0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
         0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
         0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
         0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
         0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
         0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
         0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
         0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16
    };

private:
    static const int KEY_SIZE = 16;
    static const int ROUNDS = 10;
    static const int BLOCK_SIZE = 16;

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

    static size_t calcFileSize(std::ifstream& file) {
        file.seekg(0, std::ios::end);
        size_t fileSize = file.tellg();

        // Return pointer to beginning
        file.seekg(0, std::ios::beg);
    }

private:
    // AES STEPS
    static void expandKeys() {}

    static void subBytes(unsigned char* state) {
        for (int i = 0; i < BLOCK_SIZE; i++) {
            state[i] = S_BOX[state[i]];
        }
    }

    static void shiftRows(unsigned char* state) {
        unsigned char tmp[BLOCK_SIZE];

        tmp[0] = state[0];
        tmp[1] = state[5];
        tmp[2] = state[10];
        tmp[3] = state[15];

        tmp[4] = state[4];
        tmp[5] = state[9];
        tmp[6] = state[14];
        tmp[7] = state[3];

        tmp[8] = state[8];
        tmp[9] = state[13];
        tmp[10] = state[2];
        tmp[11] = state[7];

        tmp[12] = state[12];
        tmp[13] = state[1];
        tmp[14] = state[6];
        tmp[15] = state[11];

        std::memcpy(state, tmp, BLOCK_SIZE);
    }

    static void mixColumns() {}
    static void addRoundKey(unsigned char* state, unsigned char* roundKey) {}

public:
    static void encrypt(std::ifstream& src,
                        std::ofstream& dst,
                        const std::string& password) {
        unsigned char key[KEY_SIZE];
        passwordToKey(password, key);

        size_t fileSize = calcFileSize(src);

        // Buffer to hold one block of data (16 bytes for AES-128)
        unsigned char block[BLOCK_SIZE];

        // Process file in blocks
        while (fileSize >= BLOCK_SIZE) {
            src.read(reinterpret_cast<char*>(block), BLOCK_SIZE);

            // Process Block
            // Extract to func if possible
            expandKeys();
            addRoundKey(block, key);
            for (int i = 0; i < ROUNDS - 1; i++) {
                subBytes(block);
                shiftRows(block);
                mixColumns();
                addRoundKey(block, key);
            }
            subBytes(block);
            shiftRows(block);
            addRoundKey(block, key);

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

        std::ifstream srcFile(srcFileName, std::ios::binary);
        std::ofstream dstFile(dstFileName, std::ios::binary);

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