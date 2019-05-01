#ifndef BOARD_HPP
#define BOARD_HPP

/* Author: Jordan Mata
 * File: Board.hpp
 * Date: September 30, 2018
 */

#include "TwoDArray.hpp"
#include <utility>
#include <iostream>
#include <fstream>
#include <string>

const char UP = 'w';
const char DOWN = 's';
const char LEFT = 'a';
const char RIGHT = 'd';

const int DEF_ROWS = 10;
const int DEF_COLS = 10;

const char DEF_BORDER = '=';
const char DEF_FPRINT = '=';
const char DEF_EMPTY = '=';


/* Class used to simulate a 2D board using chars to indicate
 * which tiles (spaces) have been walked on (filled)
 */
class Board{
 
  private:
    char bChar; // border char
    char fpChar; // footprint tiles (have been walked on)
    char eChar; // empty tiles (not walked on)
    std::pair<int,int> currIdx;
    TwoDArray<char>* boardArr; 
  
  public:
    /* Default constructor for the board object. Initializes the following:
     *  
     * size: 10x10
     * border: '='
     * footprint: '#'
     * empty: ' '
     */
    Board();
    
    /* Constructor for the board object. 
     *
     * const int & - m -- number of rows in board
     * const int & - n -- number of cols in board
     * const char & - borderChar -- char used for the border
     * const char & - footprintChar -- char used for the footprint (walked on)
     * const char & - emptyChar -- char used for the empty tiles (not walked on)
     */
    Board(const int & m, const int & n, const char & borderChar, 
            const char & fprintChar, const char & emptyChar);

    /* Destructor for the board object.
     */
    ~Board();
    
    /* Sets the current index to the ith row and jth column
     *
     * const char & - i -- current row
     * const char & - j -- current col
     */
    void setCurrIdx(const int & i, const int & j);

    /* Clears the board by replacing all the chars with the empty char
     */
    void clearBoard();

    /* Reads a file and populates the board based on it
     *
     * return - 0 if loaded successfully, -1 otherwise
     */
    int loadBoard( std::string filename );

    /* Checks if there is a move to make from the current index
     * 
     * const char & - dir -- direction to check if valid from currIdx
     * return - returns true if valid move, false otherwise
     */
    bool isValidMove(const char & dir);
     
    /* Makes the directional move based on the passed in char. 
     * Checks if valid move then updates currIndex and fills
     * that direction with fpChar
     *
     * const char & - dir -- checks if the char
     * return - TODO
     */
    int move(const char & dir);

    /* Prints the board to stdout
     */
    void displayBoard();

};

#endif // BOARD_HPP
