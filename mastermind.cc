#include "mastermind.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Mastermind::Mastermind(int seed, int codeLength, int guessLimit) :
               seed{seed}, codeLength{codeLength}, guessLimit{guessLimit} {
               srand(seed);
               code = new char[codeLength];
            } 

Mastermind::~Mastermind() {
             delete [] code;
           }

void Mastermind::setPasscode() {
               int randInt;
               for (int i = 0; i < codeLength; ++i) {

                randInt = rand() % 6;

                switch (randInt) {
                 case 0:
                      code[i] = 'A';
                      break;
                 case 1:
                      code[i] = 'B';
                      break;
                 case 2:
                      code[i] = 'C';
                      break;
                 case 3:
                      code[i] = 'D';
                      break;
                 case 4:
                      code[i] = 'E';
                      break;
                 case 5:
                      code[i] = 'F';
                      break;
                }
             }
            }

void Mastermind::playGame() {

 // Sets passcode
  setPasscode();

 // Prints welcome message
 cout << "Welcome to Mastermind! Please enter your first guess." << endl;

 // Creates dynamic aray to hold userCode and dupCode
 char *userCode = new char[codeLength];
 char *dupCode = new char[codeLength];

 // Initializes all variables needed in program
 char c;
 bool invalid;        
 int numBlack = 0;
 int numWhite = 0;
 int guessCount = 0;

 // While loops guessLimit times
 while (guessCount != guessLimit) {
  
  // resets dupCode to code
  for (int i = 0; i < codeLength; ++i)  
   dupCode[i] = code[i];

  // Reads in codeLength valid characters from the user
  for (int i = 0; i < codeLength; ++i) {
   
   invalid = true;
   while (invalid) {

    cin >> c;
    if (c == 'A' || c == 'a' || c == 'B' || c == 'b' ||
        c == 'C' || c == 'c' || c == 'D' || c == 'd' ||
        c == 'E' || c == 'e' || c == 'F' || c == 'f') {
     invalid = false;
     userCode[i] = c;
    } else {
     invalid = true;
     cin.ignore();
     cin.clear();
    }
   }
  }

  // finds number of black pegs
  for (int i = 0; i < codeLength; ++i) {
   if (userCode[i] == code[i] || userCode[i] == code[i] + 32) {
     ++numBlack;
     dupCode[i] = 32;
     userCode[i] = 32;
    }
  } 

 // Finds number of white pegs 
  for (int k = 0; k < codeLength; ++k) {

   if (userCode[k] != 32) {

    for (int i = 0; i < codeLength; ++i) {

     if (userCode[k] == dupCode[i] || userCode[k] == dupCode[i] + 32) {

      ++numWhite;
      userCode[k] = 32;
      dupCode[i] = 32;
      break;
     }
    }
   }
  }

 // Prints number of pegs
 cout << numBlack << "b," << numWhite << "w" << endl;

  // Prints output message according to guessCount
   if (guessCount == guessLimit-1 || numBlack == codeLength) {

   if (numBlack == codeLength) {
    ++guessCount;
    cout << "You won in " << guessCount << " guesses!" << endl;
   } else {
    cout << "You lost! The password was:" << endl;
    for (int i = 0; i < codeLength; ++i) {
     cout << code[i];
    }
    cout << "\n";
   }
   delete [] dupCode;
   delete [] userCode;
   cout << "Would you like to play again? (Y/N): ";
   cin >> c;
   if (c == 'Y' || c == 'y') {
    Mastermind mm {seed+10, codeLength, guessLimit};
    mm.playGame();
    return;
   } else {
    return;
   }
  
  } else {

   ++guessCount;
   cout << guessLimit - guessCount << " guesses left. Enter guess:" << endl;
   numBlack = 0;
   numWhite = 0;
  }

 } // while loop ends

} // playGame() ends
