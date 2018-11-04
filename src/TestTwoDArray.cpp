#include <gtest/gtest.h>
#include <limits.h>
#include <iostream>
#include "TwoDArray.hpp"

class TestTwoDArray : public testing::Test{
  public:
    
    TwoDArray<int> * arrPtrDef;
    TwoDArray<int> * intArrPtr;

    virtual void SetUp(){
    }

    virtual void TearDown(){
      delete arrPtrDef;
      delete intArrPtr;
    }
};

TEST_F( TestTwoDArray, validSizeTest ){
  std::cout << "TEST 1" << std::endl;
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
  
  // #ROWS/#COLS VERY LARGE
  TwoDArray<int> arr6(INT_MAX,INT_MAX);
  intArrPtr = new TwoDArray<int>(INT_MAX,INT_MAX);
  ASSERT_EQ(INT_MAX,arr6.getNumRows()); // Stack test
  ASSERT_EQ(INT_MAX,arr6.getNumCols());
  ASSERT_EQ(INT_MAX,intArrPtr->getNumRows()); // Heap test
  ASSERT_EQ(INT_MAX,intArrPtr->getNumCols());
  
}

TEST_F( TestTwoDArray, invalidSizeTest ){
  
}

int main(int argc, char* argv[]){
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
