/* Author: Jordan Mata
 * File: Board.cpp
 * Date: September 30, 2018
 */

#include "Board.hpp"

Board::Board( int m, int n, char bChar, char fpChar, char eChar ){
  borderChar = bChar;
  fprintChar = fpChar;
  emptyChar = eChar;
  boardArr = new TwoDArray<char>(m,n);
  currIdx = std::make_pair(0,0);
}

Board::~Board(){
  delete boardArr;
}

void Board::clearBoard(){
  for ( int i = 0; i < boardArr->getNumRows(); i++ ){
    for ( int j = 0; j < boardArr->getNumCols(); j++){
      boardArr->insert(i,j,emptyChar);
    }
  }
}

int Board::loadBoard(){
  //TODO 

  return 0;
}

void Board::setCurrIdx(int i, int j){
  currIdx.first = i;
  currIdx.second = j;
}
    
bool Board::isValidMove( char dir ){
  
  switch(dir){
  
    // If on top border or top index occupied, return false
    case UP:
      if ( currIdx.first <= 0 ||
            boardArr->at(currIdx.first-1, currIdx.second) != emptyChar){
        return false;
      }
      break;
    
    // If on bottom border or bottom index occupied, return false
    case DOWN:
      if ( currIdx.first >= boardArr->getNumRows()-1 ||
            boardArr->at(currIdx.first+1, currIdx.second) != emptyChar){
        return false;
      }
      break;
    
    // If on left border or left index occupied, return false
    case LEFT:
      if ( currIdx.second <= 0 ||
            boardArr->at(currIdx.first, currIdx.second-1) != emptyChar){
        return false;
      }
      break;
    
    // If on right border or right index occupied, return false
    case RIGHT:
      if ( currIdx.second >= boardArr->getNumCols()-1 ||
            boardArr->at(currIdx.first, currIdx.second+1) != emptyChar){
        return false;
      }
      break;
  }

  // If move wasn't invalid, return true
  return true;
}
    
int Board::move( char dir ){
  int newI = currIdx.first;
  int newJ = currIdx.second;
  std::cout << newI << ", " << newJ << "\n";
  
  if ( isValidMove(dir) ){
    switch(dir){
      case UP: newI = currIdx.first-1; break;
      case DOWN: newI = currIdx.first+1;break;
      case LEFT: newJ = currIdx.second-1; break;
      case RIGHT: newJ = currIdx.second+1;break;
    }
    setCurrIdx(newI,newJ);
    boardArr->insert(newI, newJ, fprintChar);
    return 0;
  }
  else return -1;
}

void Board::displayBoard(){
  for ( int i = 0; i < boardArr->getNumRows(); i++ ){
    for ( int j = 0; j < boardArr->getNumCols(); j++ ){
      std::cout << boardArr->at(i,j);
    }
    std::cout << std::endl;
  }
}
