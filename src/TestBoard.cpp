#include <gtest/gtest.h>
#include "Board.hpp"

class TestBoard : public testing::Test{
  
  public:  
    Board tenByTen;
    Board sixBySix;

    virtual void SetUp(){
      tenByTen = Board(10, 10,  ' ', ' ', ' ');
      if(tenByTen.loadBoard("./BoardSamples/10x10MiddleFree.brd") == -1){
        std::cerr << "FAILED TO READ FILE: BoardSamples/10x10MiddleFree.brd!\n";
      }/*
      sixBySix = Board(6, 6,  ' ', ' ', ' ');
      if(tenByTen.loadBoard("./BoardSamples/6x6MiddleFree.brd") == -1){
        std::cerr << "FAILED TO READ FILE: BoardSamples/6x6Full.brd!\n";
      }*/
    }

    virtual void TestDown(){
    }
};
/*
TEST_F( TestBoard, validMoveTest ){
  tenByTen.setCurrIdx(3,4); // Above empty space
  ASSERT_EQ(true, tenByTen.isValidMove('S'));
    
  tenByTen.setCurrIdx(4,3); // Left of empty space
  ASSERT_EQ(true, tenByTen.isValidMove('D'));
    
  tenByTen.setCurrIdx(5,4); // Below empty space
  ASSERT_EQ(true, tenByTen.isValidMove('W'));
    
  tenByTen.setCurrIdx(3,4); // Right of empty space
  ASSERT_EQ(true, tenByTen.isValidMove('A'));
}

TEST_F( TestBoard, invalidMoveTest ){
}
*/
TEST_F( TestBoard, loadBoard ){
  // Valid Boards
  ASSERT_EQ(0, tenByTen.loadBoard("./BoardSamples/10x10MiddleFree.brd"));
  
  // Invalid Boards
  ASSERT_EQ(-1, tenByTen.loadBoard("./oardSamples/10x10MiddleFree.brd"));
}

int main(int argc, char* argv[]){
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
