#ifndef TWODARRAY_HPP
#define TWODARRAY_HPP

/* Author: Jordan Mata
 * File: 2D_Array.hpp
 * Date: September 30, 2018
 */

#include <vector>
#include <iostream>

char const TAB_CHAR = '\t';
char const SPACE_CHAR = ' ';
int const DEF_ROW_SIZE = 10;
int const DEF_COL_SIZE = 10;


/* Description: Used to emulate a 2D vector using contigous memory. Stores 
 *              objects of generic type T.
 *              Underlying container allocated on heap to support larger sizes.
 */
template<typename T>
class TwoDArray{
  
  private:
    int numRows;
    int numCols;
    std::vector<T> *vecPtr; // Underlying container

  public:
    /* Default constructor, creates the container of default size
     */
    TwoDArray(){ TwoDArray( DEF_ROW_SIZE, DEF_COL_SIZE ); }

    /* Constructor that specifies the size of the 2D Array.
     * Analogous to an mxn matrix.
     *
     * arg1 - int m -- Indicates number of rows
     * arg2 - int n -- Indicates number of columns
     */
    TwoDArray( int m, int n ):numRows(m), numCols(n),
                              vecPtr(new std::vector<T>(m*n)){}

    /* Destructor that specifies the size of the 2D Array
     */
    ~TwoDArray(){ delete vecPtr; }

    /* Getter method for accessing number of Rows. */
    int getRows(){ return numRows; }
  
    /* Getter method for accessing number of Columns. */
    int getCols(){ return numCols; }
    
    /* Used to read the object in the (i,j) index of the 2D 
     * array.
     *
     * arg1 - int i -- Indicates number of rows
     * arg2 - int j -- Indicates number of rows
     */
    T at( int i, int j ){ return vecPtr->at( i*(numCols)+j ); }

    /* Used to write to the (i,j) index of the 2D array.
     * Overwrites current object at that index.
     *
     * arg1 - int i -- Indicates number of rows
     * arg2 - int j -- Indicates number of rows
     * arg3 - T key -- Object of generic type T to insert
     */
    void insert( int i, int j, T item ){ vecPtr->at( i*(numCols)+j ) = item; }

};
#endif // TWODARRAY_HPP
