#!/bin/bash

PROJECT=~/Projects/tile-walk
STATUS=$PROJECT/status
BUILD=$PROJECT/build

#Create the build directory if it does not exist
if [ ! -d $BUILD ]; then
  echo 'Build directory does not exist! Making directory.'
  mkdir $BUILD
fi

#Create the status directory if it does not exist
if [ ! -d $STATUS ]; then
  echo 'Status directory does not exist! Making directory.'
  mkdir $STATUS
fi

#Delete the status log if it exists
if [ -d $STATUS/TestLog.txt ]; then
  rm -f $STATUS/TestLog.txt
fi

echo | tee -a $STATUS/TestLog.txt
echo '******************************' | tee -a $STATUS/TestLog.txt
echo '*       Making Files         *' | tee -a $STATUS/TestLog.txt
echo '******************************' | tee -a $STATUS/TestLog.txt
make |& tee -a $STATUS/TestLog.txt

echo | tee -a $STATUS/TestLog.txt
echo '******************************' | tee -a $STATUS/TestLog.txt
echo '*     TESTING TWODARRAY      *' | tee -a $STATUS/TestLog.txt
echo '******************************' | tee -a $STATUS/TestLog.txt
./build/TestTwoDArray | tee -a $STATUS/TestLog.txt

echo | tee -a $STATUS/TestLog.txt
echo '******************************' | tee -a $STATUS/TestLog.txt
echo '*       TESTING BOARD        *' | tee -a $STATUS/TestLog.txt
echo '******************************' | tee -a $STATUS/TestLog.txt
./build/TestBoard | tee -a $STATUS/TestLog.txt
