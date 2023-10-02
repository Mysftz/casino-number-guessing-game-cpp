//  main.cpp 
//  Casino Number Guessing Game.
//  Created by MysftCodes on 28/04/2021.

#include <iostream> // The C++ decleration.
#include <string> // Needed to use strings.
#include <cstdlib> // Needed to use random numbers.
#include <stdlib.h>
#include <ctime>

using namespace std;
void rules(); 
int main()
{
    string playerName; // Players name.
    int balance; // Stores players balance.
    int bettingAmount; // How much the player would like to bet.
    int guess; // What is the players bet.
    int dice; // Stores the random number.
    char choice;
    srand(time(0)); // "Seed" the random generator.
    
    cout << "\n\t\t====== Welcome to MysftCodes Casino ======\n\n";
    cout << "\n\t\t====== Casino Number Guessing Game ======\n\n";
    cout << "\n\nWhat's your name? ";
    getline(cin, playerName);
    cout << "\n\nEnter your starting balance: £ ";
    cin >> balance;
    do
    {
        system("cls");
        rules();
        cout << "\n\nYour current balance is: £ " << balance << "\n"; // Get the players betting balance.
        do
        {
            cout << "Hey, " << playerName <<", enter amount to bet: £";
            cin >> bettingAmount;
            if(bettingAmount > balance)
                cout << "Betting balance can't be more than current balance!\n"
                << "\nRe-enter balance\n";
        }while(bettingAmount > balance); // Gets players numbers.
        do
        {
            cout << "Guess a number between 1 and 10 to bet on : ";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout << "\nNumber should be between 1 and 10\n" << "Re-enter number:\n ";
        }while(guess <= 0 || guess > 10);
        dice = rand()%10 + 1;
        if(dice == guess)
        {
            cout << "\n\nWINNER! You have won: £" << bettingAmount * 10;
            balance = balance + bettingAmount * 10;
        }
        else
        {
            cout << "LOSER!, You have lost: £" << bettingAmount <<"\n";
            balance = balance - bettingAmount;
        }
        cout << "\nThe winning number was: " << dice << "\n";
        cout << "\n" <<playerName<<", You have a balance of £" << balance << "\n";
        if(balance == 0)
        {
            cout << "You have no money to play ";
            break;
        }
        cout << "\n\n-->Do you want to play again? (Y/N)? ";
        cin >> choice;
    }while(choice == 'Y'|| choice=='y');
    cout << "\n\n\n";
    cout << "\n\nThanks for playing the game. Your balance is: £" << balance << "\n\n";
    return 0;
}
void rules()
{
    system("cls");
    cout << "\t\t====== Casino Number Guessing Game Rules ======\n";
    cout << "\t1. Choose a number between 1 and 10.\n";
    cout << "\t2. Winner gets 10 times the amount they bet.\n";
    cout << "\t3. Wrong bet and you lose the amunt that was bet.\n";
    cout << "\t4. Have fun.\n\n";
}
