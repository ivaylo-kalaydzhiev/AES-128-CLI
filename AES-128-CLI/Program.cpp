//
// Created by Ivaylo Kalaydzhiev on 19.12.23.
//

#include <iostream>
#include "FileManager.cpp"

class Program {
// Helpers
private:
    static std::string promptStringInputWithMessage(const char* message) {
        std::cout << message;
        std::string input;
        std::cin >> input;
        return input;
    }

// Flows
private:
    static void displayMainMenu() {
        std::cout << "Chose menu option:" << std::endl
                  << "(1) Print file contents" << std::endl
                  << "(2) Print file contents hexadecimal" << std::endl
                  << "(3) Encrypt file contents" << std::endl
                  << "(4) Decrypt file contents" << std::endl
                  << "(5) Exit Command Line Tool" << std::endl;
    }

    static void enterPrintFileFlow() {
        std::string fileName = promptStringInputWithMessage("Enter file name: ");
        FileManager::printFileContents(fileName);
    }

    static void enterPrintFileHexadecimalFlow() {
        std::string fileName = promptStringInputWithMessage("Enter file name: ");
        FileManager::printFileContentsHex(fileName);
    }

    static void enterEncryptFileFlow() {
        std::string srcFileName = promptStringInputWithMessage("Enter source file name: ");
        std::string password = promptStringInputWithMessage("Enter password: ");
        std::string dstFileName = promptStringInputWithMessage("Enter destination file name: ");

        FileManager::encryptFile(srcFileName, dstFileName, password);
    }

    static void enterDecryptFileFlow() {
        std::string srcFileName = promptStringInputWithMessage("Enter source file name: ");
        std::string password = promptStringInputWithMessage("Enter password: ");
        std::string dstFileName = promptStringInputWithMessage("Enter destination file name: ");

        FileManager::decryptFile(srcFileName, dstFileName, password);
    }

    static void exitCLIFlow() {
        std::cout << "You chose to leave... sad!" << std::endl;
    }

    static void invalidInputFlow() {
        std::cout << "ERROR: Only values 1 to 5 are allowed!" << std::endl
                  << "Exiting CLI..." << std::endl;
    }

public:
    static void enterMainMenuFlow() {
        displayMainMenu();

        int choice;
        std::cin >> choice;
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
                break;
            default:
                invalidInputFlow();
        }
    }
};