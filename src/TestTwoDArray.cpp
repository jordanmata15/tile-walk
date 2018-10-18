#include <gtest/gtest.h>
#include "TwoDArray.hpp"

class TestTwoDArray : public testing::Test{
  public:
    
    TwoDArray<int> arrDef;
    TwoDArray<int> arr;
    TwoDArray<int> * arrPtrDef;
    TwoDArray<int> * arrPtr;

    virtual void SetUp(){
      arrPtrDef = new TwoDArray<int>();
      arrPtr = new TwoDArray<int>(25,35);
    }

    virtual void TestDown(){
    }
};

TEST_F( TestTwoDArray, validSizeTest ){
  //ASSERT_EQ(10,arr1.getNumRows());
  //ASSERT_EQ(10,arr1.getNumCols());
}

TEST_F( TestTwoDArray, invalidSizeTest ){
  
}

int main(int argc, char* argv[]){
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
