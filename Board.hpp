#ifndef BOARD_HPP
#define BOARD_HPP

/* Author: Jordan Mata
 * File: Board.h
 * Date: September 30, 2018
 */

#include "TwoDArray.hpp"
#include <utility>

const char UP = 'w';
const char DOWN = 's';
const char LEFT = 'a';
const char RIGHT = 'd';

class Board{
 
  private:
    char borderChar;
    char fprintChar; // indicates which tiles have been walked on
    char emptyChar; // indicates which tiles have are free
    std::pair<int,int> currIdx;
    TwoDArray<char>* boardArr;
  
  public:
    Board( int m, int n, char bChar, char fpChar, char eChar );

    ~Board();

    void clearBoard();

    int loadBoard();

    void setCurrIdx(int i, int j);

    bool isValidMove( char dir );
    
    int move( char dir );

    void displayBoard();

};

#endif // BOARD_HPP
