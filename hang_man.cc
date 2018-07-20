#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <cstring>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {

  //This section downloads the dictionary to the array of string called "dictionary"
  ifstream inStream;
  inStream.open("hang_man.txt");
	if (inStream.fail()) {
		cout << "Failure to open first data file." << endl;
		exit(1);
	}
  string dictionary[6];
  int i, j, k, l = 0;
  for (i = 0; i < 6; ++i) {
    inStream >> dictionary[i];
  }
  inStream.close();


  srand (time(NULL)); //allows for random word selection from hangmandict.txt


  bool replay = true;
  string reply;
  int win = 0, lose = 0;
  while (replay == true) {


    int random = rand() % 6;
    string word_selected = dictionary[random]; //sets selected word equal to a string
    int solution_length = word_selected.length(); //finds length of word selected for later use in number of hyphens



    string solution;
    for (j = 0; j < solution_length; ++j) { //initializes solution to hyphens
    solution += "-";
    cout << solution << endl;
    }


    char guess;
    string wrong_guesses = "", all_guesses = "";

    //Causes allowance of guesses to stop once you reach max fails or complete guesses
    while (wrong_guesses.length() != 6 && solution != word_selected) {


      cin >> guess;
      all_guesses += guess; //Will also keep track of repeat guess--change later?
      cout << "All Guesses: " << all_guesses << endl;

      //This section determines if a guess is right or wrong
      for (k = 0; k < solution_length; ++k) {
        if (guess == word_selected[k]) {
          solution[k] = guess;
        }
        if (guess != word_selected[k]) {
          ++l;
        }
        if (l == solution_length) {
          wrong_guesses += guess;
        }
      }


      l = 0;
      cout << "Wrong Guesses: " << wrong_guesses << endl; //Prints out the track of wrong guesses
      cout << solution << endl; //This is meant to update the answer as guesses are made
    }

    //This section announces if the player won or lost
    if (wrong_guesses.length() == 6) {
      cout << "The solution was " << solution << "."<< endl;
      cout << "Better luck next time!" << endl;
      ++lose;
    }
    else if (solution == word_selected) {
      cout << "Amazing! You won!" << endl;
      ++win;
    }

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
