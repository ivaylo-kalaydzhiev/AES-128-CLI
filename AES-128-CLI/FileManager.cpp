//
// Created by Ivaylo Kalaydzhiev on 19.12.23.
//

#include <iostream>
#include <fstream>
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

    static void encryptFile(const std::string &srcFileName,
                            const std::string &dstFileName,
                            const std::string &password) {
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