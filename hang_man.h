#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <cstring>
#include <stdlib.h>
#include <time.h>
using namespace std;

#ifndef HANG_MAN_H
#define HANG_MAN_H
class Hangman {
public:
  void fill_array(ifstream &inStream, string dictionary[]);
  int guess_away(string wrong_guesses, string all_guesses, string solution, string word_selected, char guess, int solution_length);
};
#endif
