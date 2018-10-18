
#include <gtest/gtest.h>
#include "Board.hpp"

class TestBoard : public testing::Test{
  public:
    
//    Board b;

    virtual void SetUp(){
      //std::cout << "GOT HERE!";
    }

    virtual void TestDown(){
    }
};

TEST_F( TestBoard, validSizeTest ){
}

TEST_F( TestBoard, invalidSizeTest ){
}

int main(int argc, char* argv[]){
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
