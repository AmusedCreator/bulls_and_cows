#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int hp = 10;

void game();

void rules();

void compare(int secretNum[], int userNum[]);

void menu() {

    int choice = -1;
    while (choice != 0) {
        system("cls");

        cout << "|Bulld and cows|" << endl;
        cout << " 1. Play" << endl;
        cout << " 2. Rules" << endl;

        cout << " 0. Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                hp = 10;
                game();
                break;
            case 2:
                rules();
                break;
            default:
                cout << "Wrong choice" << endl;
                break;
        }
    }
}

void game() {
    system("cls");
    int secretNum[4];

    for (int i = 0; i < 4; i++) {
        secretNum[i] = 1 + rand() % (1 - 9 + 1);
        for (int j = 0; j < i; j++) {
            if (secretNum[i] == secretNum[j]) {
                i--;
            }
        }
    }

//    for (int i = 0; i < 4; i++) {
//        cout << secretNum[i];
//    }

    cout << "Computer guessed the number" << endl;
    while (hp != 0) {
        int userNum[4];
        cout << "\nHP: " << hp << endl;
        cout << "Enter your number: ";
        int num;
        cin >> num;
        for (int i = 3; i >= 0; i--) {
            userNum[i] = num % 10;
            num /= 10;
        }

        compare(secretNum, userNum);
    }
    cout << "You lose!" << endl;
    cout << "Secret number was: " << secretNum[0] << secretNum[1] << secretNum[2] << secretNum[3] << endl;
    system("pause");
}

void compare(int secretNum[], int userNum[]) {
    int bulls = 0;
    int cows = 0;
    for (int i = 0; i < 4; i++) {
        if (secretNum[i] == userNum[i]) {
            bulls++;
        } else {
            for (int j = 0; j < 4; j++) {
                if (secretNum[i] == userNum[j]) {
                    cows++;
                }
            }
        }
    }
    if (bulls == 4) {
        cout << "You win!" << endl;
        system("pause");
        menu();
    } else {
        cout << "Bulls: " << bulls << endl;
        cout << "Cows: " << cows << endl;
        hp--;
    }
}

void rules() {
    system("cls");
    cout << "Bulls and cows is a code-breaking game for two players." << endl;
    cout << "Computer generates a 4-digit number." << endl;
    cout << "Player tries to guess the number." << endl;
    cout << "For each digit that the player guessed correctly in the correct place, they have a bull." << endl;
    cout << "For each digit the player guessed correctly in the wrong place is a cow." << endl;
    cout << "The first number cannot be 0." << endl;
    cout << "If the player has 0 HP, he loses." << endl;
    system("pause");
}

int main() {
    srand(time(NULL));
    menu();
}
