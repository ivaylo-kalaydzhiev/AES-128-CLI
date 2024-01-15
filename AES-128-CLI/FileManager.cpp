//
// Created by Ivaylo Kalaydzhiev on 19.12.23.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "AESCryptographer.cpp"

class FileManager {
public:
    static void printFileContents(const std::string &fileName) {
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

    static void printFileContentsHex(const std::string &fileName) {
        std::ifstream file(fileName, std::ios::binary);

        if (!file.is_open()) {
            std::cout << "Unable to open file: " << fileName << std::endl;
            return;
        }

        std::ostringstream oss;
        oss << std::hex << std::uppercase << std::setfill('0');

        char c;
        while (file.get(c)) {
            oss << std::setw(2) << (int)(unsigned char)(c) << ' ';
        }

        std::cout << oss.str() << std::endl;
        file.close();
    }

    static void encryptFile(const std::string &srcFileName,
                            const std::string &dstFileName,
                            const std::string &password) {
        if (srcFileName == dstFileName) {
            std::cout << "Source file and destination file can not be the same" << std::endl;
            return;
        }

        std::ifstream srcFile(srcFileName);
        std::ofstream dstFile(dstFileName);

        // Resource leak: These openings, need to be split, beacause this way it is posible that one file is opened, the
        // other is not, and then we return, without closing the opened file

        // DRY: Checking for successfull openinigs is repeated, extract to func
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

    static void decryptFile(const std::string &srcFileName,
                            const std::string &dstFileName,
                            const std::string &password) {
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