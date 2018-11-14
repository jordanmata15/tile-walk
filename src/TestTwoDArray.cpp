/* Author: Jordan Mata
 * File: TestTwoDArray.cpp
 * Date: November 12, 2018
 */

#include <gtest/gtest.h>
#include <limits.h>
#include <vector>
#include <iostream>
#include "TwoDArray.hpp"

class TestTwoDArray : public testing::Test{
  
  public:    
    TwoDArray<int> * arrPtrDef;
    TwoDArray<int> * intArrPtr;
    TwoDArray<int> inOrderArr;
    TwoDArray<int> reverseArr;
    TwoDArray<int> mixedArr;
    TwoDArray<int> nonSquareArr;

    virtual void SetUp(){
      inOrderArr = TwoDArray<int>(10,10);
      reverseArr = TwoDArray<int>(10,10);
      mixedArr = TwoDArray<int>(10,10);
      nonSquareArr = TwoDArray<int>(7,5);
      
      // populate the 3 arrays
      for( int i = 0; i < 10; i++){
        for( int j = 0; j < 10; j++){
          int nextVal = (10*i)+j;

          inOrderArr.insert(i,j,nextVal);
          reverseArr.insert(9-i,9-j,nextVal);
          
          // populate mixed with alternating vals
          if (nextVal % 2 == 0) mixedArr.insert(i,j,nextVal); 
          else mixedArr.insert(i,j,100-nextVal); 
        
        }
      }
    }

    virtual void TearDown(){
      // Used to visually debug arrays by printing them
      /*for( int i = 0; i < 10; i++){
        for( int j = 0; j < 10; j++){
          //std::cout << reverseArr.at(i,j) << '\t';
          //std::cout << inOrderArr.at(i,j) << '\t';
          //std::cout << mixedArr.at(i,j) << '\t';
          //if (i < 7 && j < 5) std::cout << nonSquareArr.at(i,j) << '\t';
        }
        //std::cout << std::endl;
      }*/
    }
};

/* Test of valid initialization sizes of the TwoDArray. Tests for cases where 
 * both dimensions of the same size, one larger than the other, and default 
 * constructor. Sizes range from 0 to INT_MAX
 */
TEST_F( TestTwoDArray, validSizeTest ){
  // Default constructor
  TwoDArray<int> arrDef;
  arrPtrDef = new TwoDArray<int>();
  ASSERT_EQ(10,arrDef.getNumRows()); // Stack test
  ASSERT_EQ(10,arrDef.getNumCols());
  ASSERT_EQ(10,arrPtrDef->getNumRows()); // Heap test
  ASSERT_EQ(10,arrPtrDef->getNumCols());

  // #ROWS = #COLS
  TwoDArray<int> arr(15,15);
  intArrPtr = new TwoDArray<int>(25,25);
  ASSERT_EQ(15,arr.getNumRows()); // Stack test
  ASSERT_EQ(15,arr.getNumCols());
  ASSERT_EQ(25,intArrPtr->getNumRows()); // Heap test
  ASSERT_EQ(25,intArrPtr->getNumCols());
  delete intArrPtr;

  // #ROWS > #COLS
  TwoDArray<int> arr1(27,13);
  intArrPtr = new TwoDArray<int>(17,6);
  ASSERT_EQ(27,arr1.getNumRows()); // Stack test
  ASSERT_EQ(13,arr1.getNumCols());
  ASSERT_EQ(17,intArrPtr->getNumRows()); // Heap test
  ASSERT_EQ(6,intArrPtr->getNumCols());
  delete intArrPtr;

  // #ROWS < #COLS
  TwoDArray<int> arr2(42,49);
  intArrPtr = new TwoDArray<int>(18,1);
  ASSERT_EQ(42,arr2.getNumRows()); // Stack test
  ASSERT_EQ(49,arr2.getNumCols());
  ASSERT_EQ(18,intArrPtr->getNumRows()); // Heap test
  ASSERT_EQ(1,intArrPtr->getNumCols());
  delete intArrPtr;

  // #ROWS > 0, #COLS = 0
  TwoDArray<int> arr3(42,0);
  intArrPtr = new TwoDArray<int>(18,0);
  ASSERT_EQ(42,arr3.getNumRows()); // Stack test
  ASSERT_EQ(0,arr3.getNumCols());
  ASSERT_EQ(18,intArrPtr->getNumRows()); // Heap test
  ASSERT_EQ(0,intArrPtr->getNumCols());
  delete intArrPtr;

  // #ROWS = 0, #COLS > 0
  TwoDArray<int> arr4(0,49);
  intArrPtr = new TwoDArray<int>(0,1);
  ASSERT_EQ(0,arr4.getNumRows()); // Stack test
  ASSERT_EQ(49,arr4.getNumCols());
  ASSERT_EQ(0,intArrPtr->getNumRows()); // Heap test
  ASSERT_EQ(1,intArrPtr->getNumCols());
  delete intArrPtr;
  
  // #ROWS = 0, #COLS = 0
  TwoDArray<int> arr5(0,0);
  intArrPtr = new TwoDArray<int>(0,0);
  ASSERT_EQ(0,arr5.getNumRows()); // Stack test
  ASSERT_EQ(0,arr5.getNumCols());
  ASSERT_EQ(0,intArrPtr->getNumRows()); // Heap test
  ASSERT_EQ(0,intArrPtr->getNumCols());
  delete intArrPtr;
  
  // #ROWS and #COLS VERY LARGE
  TwoDArray<int> arr6(INT_MAX,INT_MAX);
  intArrPtr = new TwoDArray<int>(INT_MAX,INT_MAX);
  ASSERT_EQ(INT_MAX,arr6.getNumRows()); // Stack test
  ASSERT_EQ(INT_MAX,arr6.getNumCols());
  ASSERT_EQ(INT_MAX,intArrPtr->getNumRows()); // Heap test
  ASSERT_EQ(INT_MAX,intArrPtr->getNumCols());
  delete arrPtrDef;
  delete intArrPtr;
}

/* Test used to verify the vector correctly supports different data types.
 * Tests using primitive and reference types, including a test where the
 * 2D array holds 2D array objects
 */
TEST_F( TestTwoDArray, validTypeTest ){
  // int Test
  TwoDArray<int> intArrDef;
  TwoDArray<int> intArr(10,7);
  intArrDef.insert(0,0,3);
  intArr.insert(0,0,4);
  ASSERT_EQ(typeid(int),typeid(intArrDef.at(0,0)));
  ASSERT_EQ(typeid(int),typeid(intArr.at(0,0)));

  // char test
  TwoDArray<char> charArrDef;
  TwoDArray<char> charArr(7,10);
  charArrDef.insert(0,0,'a');
  charArr.insert(0,0,'$');
  ASSERT_EQ(typeid(char),typeid(charArrDef.at(0,0)));
  ASSERT_EQ(typeid(char),typeid(charArr.at(0,0)));

  // pointer test
  void * temp = nullptr;
  TwoDArray<void *> ptrArrDef;
  TwoDArray<void *> ptrArr(7,7);
  ptrArrDef.insert(0,0,temp);
  ptrArr.insert(0,0,temp);
  ASSERT_EQ(typeid(void *),typeid(ptrArrDef.at(0,0)));
  ASSERT_EQ(typeid(void *),typeid(ptrArr.at(0,0)));

  // object test (vector)
  std::vector<int> intVec;
  TwoDArray<std::vector<int>> vecArrDef;
  TwoDArray<std::vector<int>> vecArr(2,3);
  vecArrDef.insert(0,0,intVec);
  vecArr.insert(0,0,intVec);
  ASSERT_EQ(typeid(std::vector<int>),typeid(vecArrDef.at(0,0)));
  ASSERT_EQ(typeid(std::vector<int>),typeid(vecArr.at(0,0)));
  
  // object test (TwoDArray)
  TwoDArray<TwoDArray<int>> arrayArrDef;
  TwoDArray<TwoDArray<int>> arrayArr(2,3);
  arrayArrDef.insert(0,0,intArr);
  arrayArr.insert(0,0,intArr);
  ASSERT_EQ(typeid(TwoDArray<int>),typeid(arrayArrDef.at(0,0)));
  ASSERT_EQ(typeid(TwoDArray<int>),typeid(arrayArr.at(0,0)));
}

/* Test of the operator= function for TwoDArray. Tests that num
 * rows/cols match the rval and that the content in the vectors
 * are the same.
 */
TEST_F( TestTwoDArray, testCopy ){
  // Resizing test (new dimensions different than original)
  TwoDArray<int> copyArr(9,12);
  ASSERT_EQ(9,copyArr.getNumRows());
  ASSERT_EQ(12,copyArr.getNumCols());
  
  copyArr = inOrderArr;
  ASSERT_EQ(10,copyArr.getNumRows());
  ASSERT_EQ(10,copyArr.getNumCols());

  TwoDArray<int> mixedSize(17, 33);
  copyArr = mixedSize;
  ASSERT_EQ(17,copyArr.getNumRows());
  ASSERT_EQ(33,copyArr.getNumCols());

  // Testing same content with resizing
  TwoDArray<int> emptyArr(18,100);
  emptyArr = inOrderArr;
  for( int i = 0; i < emptyArr.getNumRows(); i++){
    for( int j = 0; j < emptyArr.getNumCols(); j++){
      ASSERT_EQ(inOrderArr.at(i,j), emptyArr.at(i,j));
    }
  }
}

/* Tests the insert and At functions. Compares the results with
 * the equivalent 2D arrays
 */
TEST_F( TestTwoDArray, testInsertAndAt ){
  int intArr[10][10];
  int sumArrA[10][10];
  TwoDArray<int> sumArrV(10,10);

  // populate the arrays
  for( int i = 0; i < 10; i++){
    for( int j = 0; j < 10; j++){
      intArr[i][j] = (10*i)+j; // populate an array in order
                               // to compare to inOrderArr
      int val = mixedArr.at(i,j) + inOrderArr.at(i,j)
                  + reverseArr.at(i,j);
      sumArrA[i][j] = val;      // populate array and a vector
      sumArrV.insert(i,j, val); // to compare to each other
    }
  }

  // Compare the arrays
  for( int i = 0; i < 10; i++){
    for( int j = 0; j < 10; j++){
      ASSERT_EQ(inOrderArr.at(i,j), intArr[i][j]);
      ASSERT_EQ(sumArrA[i][j], sumArrV.at(i,j));
    }
  }
}

int main(int argc, char* argv[]){
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
