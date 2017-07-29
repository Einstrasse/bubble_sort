#!/bin/bash

make
NUM_ELEM=10000
TIME_LOG_PATH='./time.log'
CORRECT_LOG_PATH='./correct.log'
rm ./*.log
for i in {1..100}
do
   ./main $NUM_ELEM $i 2>>$TIME_LOG_PATH 1>> $CORRECT_LOG_PATH
done