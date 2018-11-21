#ifndef TWODARRAY_HPP
#define TWODARRAY_HPP

/* Author: Jordan Mata
 * File: TwoDArray.hpp
 * Date: September 30, 2018
 */

#include <vector>

/* Description: Used to emulate a 2D vector using contigous memory. Stores 
 *              objects of generic type T. Implemented in header to allow
 *              generics during compile time.
 */
template<typename T>
class TwoDArray{
  
  private:
    char const TAB_CHAR = '\t';
    char const SPACE_CHAR = ' ';
    int const DEF_ROW_SIZE = 10;
    int const DEF_COL_SIZE = 10;
    int numRows;
    int numCols;
    std::vector<T> vec; // Underlying container

  public:
    /* Default constructor, creates the container of default size
     */
    TwoDArray():TwoDArray( DEF_ROW_SIZE, DEF_COL_SIZE ){}

    /* Constructor that specifies the size of the 2D Array.
     * Analogous to an mxn matrix.
     *
     * arg1 - const int & m -- Indicates number of rows
     * arg2 - const int & n -- Indicates number of columns
     */
    TwoDArray( const int & m, const int & n ): 
                    numRows(m), numCols(n), vec(m*n){}

    /* Default destructor
     */
    ~TwoDArray(){}
    
    /* Overload operator= to copy the contents of another 2D 
     * array into this array. Settings this_arr = x_arr makes 
     * this_arr a reference to a copy of x_arr
     *
     * arg1 - const TwoDArray & x -- 2DArray to set this equal to
     */
    TwoDArray & operator=( const TwoDArray & x ){
      this->vec = x.vec;
      this->numRows = x.numRows;
      this->numCols = x.numCols;
      return *this;
    }

    /* Getter method for accessing number of Rows. */
    int getNumRows(){ return numRows; }
  
    /* Getter method for accessing number of Columns. */
    int getNumCols(){ return numCols; }

    /* Used to read the object in the (i,j) index of the 2D 
     * array.
     *
     * arg1 - const int & i -- Indicates number of rows
     * arg2 - const int & j -- Indicates number of rows
     */
    T at( const int & i, const int & j ){
      return vec.at( (i*numCols) + j );
    }

    /* Used to write to the (i,j) index of the 2D array.
     * Overwrites current object at that index.
     *
     * arg1 - const int & i -- Indicates number of rows
     * arg2 - const int & j -- Indicates number of rows
     * arg3 - const T & key -- Object of generic type T to insert
     */
    void insert( const int & i, const int & j, const T & item ){
      vec.at( (i*numCols) + j ) = item;
    }

};
#endif // TWODARRAY_HPP
