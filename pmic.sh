#!/bin/bash

DEV_NAME="pmic"
LOG_FILE_NAME="pmic.log"

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
	i2cget -f -y 3 0x08 0x00 c > /dev/null 2>&1 ; i2cget -f -y 3 0x08 0x03 c > /dev/null 2>&1 ; i2cget -f -y 3 0x08 0x04 c  > /dev/null 2>&1
        if [ $? != 0 ]; then
		ERROR_COUNTER=$(( ERROR_COUNTER + 1 ))
		echo "$DEV_NAME error count = $ERROR_COUNTER" > ./$DEV_NAME.count
		echo "$DEV_NAME error count = $ERROR_COUNTER"
        fi
	LOOP_COUNTER=$(( LOOP_COUNTER + 1 ))

	if [ 0 -eq $(( LOOP_COUNTER % 1000 )) ]; then
		echo "$DEV_NAME count = $LOOP_COUNTER" > ./$DEV_NAME.count
	fi
done
