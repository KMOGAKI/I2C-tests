#!/bin/sh

DEV_NAME="a71ch"
LOG_FILE_NAME="a71ch.log"

abort() {
	echo "COUNT = $LOOP_COUNTER" >> ./$LOG_FILE_NAME
	echo $(date) >> ./$LOG_FILE_NAME
	echo -e "\nend"
	pkill bmic.sh
	pkill pmic.sh
	pkill eeprom.sh
	exit 0
}

trap 'abort' 1 2 13 15

./bmic.sh & 
./pmic.sh &
./eeprom.sh &

echo "start $DEV_NAME i2c access"
LOOP_COUNTER=0

echo "start $DEV_NAME i2c access " > ./$LOG_FILE_NAME
echo $(date) >> ./$LOG_FILE_NAME

while :
do
	echo "LOOP_COUNTER=$LOOP_COUNTER"
	/./root/axHostSw/linux/A71CH_i2c_imx
	LOOP_COUNTER=$(( LOOP_COUNTER + 1 ))
	cat ./bmic.count
	cat ./pmic.count
	cat ./eeprom.count
done
