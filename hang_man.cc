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

//This section downloads the dictionary to the array of string called "dictionary"
void Hangman::fill_array(ifstream &inStream, string dictionary[]) {
  inStream.open("hangmandict.txt");
   if (inStream.fail()) {
     cout << "Failure to open data file." << endl;
     exit(1);
   }
  for (int i = 0; i < 109582; ++i) {
    inStream >> dictionary[i];
  }
  inStream.close();
}



int Hangman::guess_away(string wrong_guesses, string all_guesses, string solution, string word_selected, char guess, int solution_length) {
  int l = 0;
  while (wrong_guesses.length() != 6 && solution != word_selected) {


    cin >> guess;
    all_guesses += guess; //Will also keep track of repeat guess--change later?
    cout << "All Guesses: " << all_guesses << endl;

    //This section determines if a guess is right or wrong
    for (int k = 0; k < solution_length; ++k) {
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
    cout << "The solution was " << word_selected << "."<< endl;
    cout << "Better luck next time!" << endl;
    return 1;
  }
  else if (solution == word_selected) {
    cout << "Amazing! You won!" << endl;
  }
  return 0;
}
