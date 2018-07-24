#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <cstring>
#include <stdlib.h>
#include <time.h>
#include "hang_man.h"
using namespace std;



int main() {
  Hangman game;
  ifstream inStream;
  string dictionary[109582], solution, word_selected, reply, wrong_guesses = "", all_guesses = "";
  bool replay = true;
  int random, solution_length = 0, win = 0, lose = 0, total;
  char guess = '\0';

  //This section downloads the dictionary to the array of string called "dictionary"
  game.fill_array(inStream, dictionary);


  while (replay == true) {

    solution = "";
    srand (time(NULL)); //allows for random word selection from hangmandict.txt
    random = rand() % 109582;
    word_selected = dictionary[random]; //sets selected word equal to a string
    solution_length = word_selected.length(); //finds length of word selected for later use in number of hyphens
    cout << "Solution length is " << solution_length << endl;


    for (int j = 0; j < solution_length; ++j) { //initializes solution to hyphens
      solution += "-";
    }
    cout << solution << endl;


    //Causes allowance of guesses to stop once you reach max fails or complete guesses
    total = game.guess_away(wrong_guesses, all_guesses, solution, word_selected, guess, solution_length);
    if (total == 1)
      ++lose;
    if (total == 0)
      ++win;


    //This section determines if the game will be played again
    cout << "Scoreboard:" << endl;
    cout << "# of Wins: " << win << "   # of Losses: " << lose << endl;
    cout << "Would you like to play again? (Yes or No)" << endl;
    cin >> reply;
    if (reply == "Yes" || reply == "yes" || reply == "y" || reply == "Y")
      replay = true;
    if (reply == "No" || reply == "no" || reply == "n" || reply == "N")
      replay = false;
  }

  return 0;
}
