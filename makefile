# Where to find gtest files.
GTEST_DIR = /usr/src/gtest

# gtest headers
GTEST_HEADERS = /usr/include/gtest/*.h \
                /usr/include/gtest/internal/*.h

BUILD = ./build

CXX = g++
CPPFLAGS = -std=c++11 -Wall -Wextra -g
CXXFLAGS = -c -g -std=c++11 -Wall -Wextra -I $(GTEST_DIR)
LDFLAGS = -L /usr/local/lib -l gtest -l pthread


TEST_TARGETS = TestTwoDArray TestBoard
TESTOBJ = $(BUILD)/TestTwoDArray.o $(BUILD)/TestBoard.o \
					$(BUILD)/Board.o
OBJ = $(BUILD)/Board.o

all: $(TEST_TARGETS)

TestTwoDArray: $(BUILD)/TestTwoDArray.o
	$(CXX) $(CPPFLAGS) -o $(BUILD)/$@ $^ $(LDFLAGS)

TestBoard: $(BUILD)/TestBoard.o $(BUILD)/Board.o
	$(CXX) $(CPPFLAGS) -o $(BUILD)/$@ $^ $(LDFLAGS)

$(BUILD)/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<	

clean:
	rm -rf $(BUILD)/* core
