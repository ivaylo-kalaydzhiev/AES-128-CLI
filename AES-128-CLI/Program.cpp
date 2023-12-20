//
// Created by Ivaylo Kalaydzhiev on 19.12.23.
//

#include <iostream>
#include "FileManager.cpp"

class Program {
private:
    static void displayMainMenu() {
        std::cout << "Chose menu option:" << std::endl
                  << "(1) Print file contents" << std::endl
                  << "(2) Print file contents hexadecimal" << std::endl
                  << "(3) Encrypt file contents" << std::endl
                  << "(4) Decrypt file contents" << std::endl
                  << "(5) Exit Command Line Tool" << std::endl;
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

    static void enterPrintFileHexadecimalFlow() {
        std::cout << "Enter file name: ";
        std::string fileName;
        std::cin >> fileName;
        FileManager::printFileContentsHex(fileName);
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
                enterPrintFileHexadecimalFlow();
                enterMainMenuFlow();
                break;
            case 3:
                enterEncryptFileFlow();
                enterMainMenuFlow();
                break;
            case 4:
                enterDecryptFileFlow();
                enterMainMenuFlow();
                break;
            case 5:
                exitCLIFlow();
                return;
            default:
                enterMainMenuFlow();
        }
    }
};