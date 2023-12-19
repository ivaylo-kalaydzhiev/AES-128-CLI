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