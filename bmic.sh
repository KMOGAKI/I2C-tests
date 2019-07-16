#!/bin/sh

DEV_NAME="bmic"
LOG_FILE_NAME="bmic.log"

abort() {
	echo "COUNT = $LOOP_COUNTER" >> ./$LOG_FILE_NAME
	echo $(date) >> ./$LOG_FILE_NAME
	echo -e "\nend"
	exit 0
}

trap 'abort' 1 2 13 15

echo "start $DEV_NAME i2c access"
LOOP_COUNTER=0
ERROR_COUNTER=0

echo "start $DEV_NAME i2c access " > ./$LOG_FILE_NAME
echo $(date) >> ./$LOG_FILE_NAME

while :
do
	./a.out
        if [ $? != 0 ]; then
	        ERROR_COUNTER=$(( ERROR_COUNTER + 1 ))
		echo "$DEV_NAME error count = $ERROR_COUNTER"
		echo "$DEV_NAME error count = $ERROR_COUNTER" > ./$DEV_NAME.count
        fi
	LOOP_COUNTER=$(( LOOP_COUNTER + 1 ))
	if [ 0 -eq $(( LOOP_COUNTER % 1000 )) ]; then
		echo "$DEV_NAME count = $LOOP_COUNTER" > ./$DEV_NAME.count
	fi
done
