/*********************************
* Erica Buchanan    Allegro Demo *
* 28/04/2021                     *
*                                *
* This program draws prints a    *
* display of a house with grass  *
* and a window.                  *
*********************************/

#include <iostream>
#include <fstream>
#include <apmatrix.h>
#include <vector>
#include <string.h>

#define NUM_ROWS 11
#define NUM_COLS 11
#define NUM_WORDS 6

#define NORTH 1
#define NORTH_EAST 2
#define EAST 3
#define SOUTH_EAST 4
#define SOUTH 5
#define SOUTH_WEST 6
#define WEST 7
#define NORTH_WEST 8

using namespace std;

int read_crossword(ifstream &inputFile, apmatrix<char> &m);
int find_word(const apmatrix<char> &m, ifstream &inputFile, int word_row, int word_column, int word_direction);

int main(){
    ifstream inFile1("squareofletters.txt");
    ifstream inFile2("words.txt");

    apmatrix<char> m(NUM_ROWS,NUM_COLS, ' ');

    if (read_crossword(inFile1, m) == -1){
        return -1;
    }else{
        if (!inFile2.is_open()){
            cout << "Error opening word document." << endl;
            return -1;
        }else{
            for (int i = 0; i < NUM_WORDS; i++){
                int row = -1;
                int column = -1;
                int direction = -1;
                cout << endl;
                find_word(m, inFile2, row, column, direction);
            }
        }
    }

    return 0;
}

int read_crossword(ifstream &inputFile, apmatrix<char> &m){
    if (!inputFile.is_open()){
        cout << "Error opening crossword file." << endl;
        return -1;
    }else{
        for (int i = 0; i < NUM_ROWS; i++){
            for (int j = 0; j < NUM_COLS; j++){
                inputFile >> m[i][j];
                cout << m[i][j];
            }
            cout << endl;
        }
        return 0;
        inputFile.close();
    }
}

int find_word(const apmatrix<char> &m, ifstream &inputFile, int word_row, int word_column, int word_direction){
    //used array of characters here instead of using a vector bc i couldn't read it in one line at a time
    char str[NUM_COLS] = "";
    inputFile >> str;
    cout << str;
    //find where string is - look at battleship assignment maybe?
    cout << endl;
    return 1;
}



