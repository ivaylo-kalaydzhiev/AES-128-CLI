#include <iostream>

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
        std::cout << "You chose option 1" << std::endl;
    }

    static void enterEncryptFileFlow() {
        std::cout << "You chose option 2" << std::endl;
    }

    static void enterDecryptFileFlow() {
        std::cout << "You chose option 3" << std::endl;
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