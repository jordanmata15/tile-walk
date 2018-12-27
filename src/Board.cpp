/* Author: Jordan Mata
 * File: Board.cpp
 * Date: September 30, 2018
 */

#include "Board.hpp"

/* Constructor for the board object. 
 *
 * const int & - m -- number of rows in board
 * const int & - n -- number of cols in board
 * const char & - bChar -- char used for the border
 * const char & - fChar -- char used for the footprint (walked on)
 * const char & - eChar -- char used for the empty tiles (not walked on)
 */
Board::Board(const int & m, const int & n, const char & borderChar, 
                        const char & fprintChar, const char & emptyChar){
  bChar = borderChar;
  fpChar = fprintChar;
  eChar = emptyChar;
  boardArr = new TwoDArray<char>(m,n);
  currIdx = std::make_pair(0,0);
}

/* Default destructor
 */
Board::~Board(){
  delete boardArr;
}

/* Sets the current index to the ith row and jth column
 *
 * const char & - i -- current row
 * const char & - j -- current col
 */
void Board::setCurrIdx(const int & i, const int & j){
  currIdx.first = i;
  currIdx.second = j;
}
    
/* Clears the board by replacing all the chars with the empty char
 */
void Board::clearBoard(){
  for ( int i = 0; i < boardArr->getNumRows(); i++ ){
    for ( int j = 0; j < boardArr->getNumCols(); j++){
      boardArr->insert(i,j,eChar);
    }
  }
}

/* Reads a file and populates the board based on it
 *
 * return - 0 if loaded successfully, -1 otherwise
 */
int Board::loadBoard( std::string filename ){
  std::string currLine;
  std::ifstream readFile(filename);
  bool headerIsRead = false;
  if ( readFile.is_open() ){
    if (!headerIsRead){ // Parse the header to read size
      std::getline(readFile, currLine, 'x');
      int numRows = std::stoi(currLine);
      std::getline(readFile, currLine);
      int numCols = std::stoi(currLine);
      headerIsRead = true;
      // TODO Read the chars to use
    }
    while( getline(readFile,currLine) ){ // Read the table line by line
      // TODO read the table itself
    }
  }
  return 0;
}

/* Checks if there is a move to make from the current index
 * 
 * const char & - dir -- direction to check if valid from currIdx
 * return - returns true if valid move, false otherwise
 */
bool Board::isValidMove(const char & dir){ 
  switch(dir){
  
    // If on top border or top index occupied, return false
    case UP:
      if ( currIdx.first <= 0 ||
            boardArr->at(currIdx.first-1, currIdx.second) != eChar){
        return false;
      }
      break;
    
    // If on bottom border or bottom index occupied, return false
    case DOWN:
      if ( currIdx.first >= boardArr->getNumRows()-1 ||
            boardArr->at(currIdx.first+1, currIdx.second) != eChar){
        return false;
      }
      break;
    
    // If on left border or left index occupied, return false
    case LEFT:
      if ( currIdx.second <= 0 ||
            boardArr->at(currIdx.first, currIdx.second-1) != eChar){
        return false;
      }
      break;
    
    // If on right border or right index occupied, return false
    case RIGHT:
      if ( currIdx.second >= boardArr->getNumCols()-1 ||
            boardArr->at(currIdx.first, currIdx.second+1) != eChar){
        return false;
      }
      break;
  }

  // If move was valid, return true
  return true;
}

/* Makes the directional move based on the passed in char. 
 * Checks if valid move then updates currIndex and fills
 * that direction with fpChar
 *
 * const char & - dir -- checks if the char
 * return - TODO
 */
int Board::move(const char & dir){
  int newI = currIdx.first;
  int newJ = currIdx.second;
  
  if ( isValidMove(dir) ){
    switch(dir){
      case UP: newI = currIdx.first-1; break;   // If valid vertical move
      case DOWN: newI = currIdx.first+1;break;  // update I
      case LEFT: newJ = currIdx.second-1; break; // If valid horizontal move
      case RIGHT: newJ = currIdx.second+1;break; // update J
    }
    setCurrIdx(newI,newJ); // Set new curr index
    boardArr->insert(newI, newJ, fpChar); // place a footprint there
    return 0;
  }
  else return -1;
}

/* Prints the board to stdout
 */
void Board::displayBoard(){
  // print top border
  for ( int i = 0; i < boardArr->getNumRows(); i++ ){std::cout << bChar;}
  // print board
  for ( int i = 0; i < boardArr->getNumRows(); i++ ){
    std::cout << bChar;
    for ( int j = 0; j < boardArr->getNumCols(); j++ ){
      std::cout << boardArr->at(i,j);
    }
    std::cout << bChar << std::endl;
  }
  // print bottom border
  for ( int i = 0; i < boardArr->getNumRows(); i++ ){std::cout << bChar;}
}
