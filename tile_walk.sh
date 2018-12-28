#!/bin/bash

STATUS='./status'

#Create the status directory if it does not exist
if [ ! -f $STATUS ]; then
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
