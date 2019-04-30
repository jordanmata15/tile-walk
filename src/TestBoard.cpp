#include <gtest/gtest.h>
#include "Board.hpp"

class TestBoard : public testing::Test{
  public:
    

    virtual void SetUp(){
    }

    virtual void TestDown(){
    }
};

TEST_F( TestBoard, validMoveTest ){
  //ASSERT_EQ(10, tenByTen);
}

TEST_F( TestBoard, invalidMoveTest ){
}

TEST_F( TestBoard, loadBoard ){
  Board tenByTen(10, 10,  ' ', ' ', ' ');
  if(tenByTen.loadBoard("./BoardSamples/10x10Numbered.brd") == 0){
    std::cout << std::endl;
    tenByTen.displayBoard();
    std::cout << std::endl;
  }
}

int main(int argc, char* argv[]){
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
