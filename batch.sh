#!/bin/bash
#빌드 후 여러번의 알고리즘의 구현 검증 및 수행시간 측정을 한 뒤, 결과를 로그파일로 저장하는 스크립트
make
NUM_ELEM=10000
TIME_LOG_PATH='./time.log'
CORRECT_LOG_PATH='./correct.log'
rm ./*.csv
rm ./*.log
for i in {1..100}
do
   ./main $NUM_ELEM $i 2>>$TIME_LOG_PATH 1>> $CORRECT_LOG_PATH
done