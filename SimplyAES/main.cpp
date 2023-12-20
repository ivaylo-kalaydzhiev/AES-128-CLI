#include <iostream>

void SubBytes();

void ShiftRows();

void MixColumns();

void KeyExpansion() {

}

void MixColumns() {

}

void ShiftRows() {

}

void SubBytes() {

}

void AddRoundKey() {}

void AES_Encrypt() {
    int numberOfRounds = 1;

    KeyExpansion();
    AddRoundKey();

    for (int i = 0; i < numberOfRounds; ++i) {
        SubBytes();
        ShiftRows();
        MixColumns();
        AddRoundKey();
    }

    SubBytes();
    ShiftRows();
    AddRoundKey();
}


int main() {
    char message[] = "This is a message we will encrypt with AES!";
    char key[16] = {
            1,2,3, 4,
            5,6,7, 8,
            9,10,11, 12,
            13,14,15, 16
    };

    AES_Encrypt();

    return 0;
}
