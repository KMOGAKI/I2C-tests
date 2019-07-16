/* Copyright (c) 2017 Atmark Techno, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <stdint.h>

#define I2C_SLAVE_ADDR  (0x10)

struct slavedata {
        char command;
        char size;
        char slvaddr;
};
struct slavedata slvdata[5];

typedef struct {
        uint8_t ctrl;
        uint8_t data;
} packet;

int get_general_4(void)
{
        int fd, ret;
        packet p;

        fd = open("/dev/i2c-3", O_RDWR);
        if (fd < 0) {
                printf("Faild to open i2c port\n");
                return fd;
        }

        ret = ioctl(fd, I2C_SLAVE, 0x10);
        if (ret < 0) {
                printf("Unable to get bus access to talk to slave\n");
                close(fd);
                return ret;
        }

        uint8_t dammy[4];
        dammy[0] = 0x04;
        ret = write(fd, &dammy, 1);
        if (ret < 0)
                return ret;
        ret = read(fd, &dammy, 4);
        if (ret < 0)
                return ret;

        close(fd);
        usleep(4000);

        return 0;
}

int get_general_5(void)
{
        int fd, ret;
        packet p;

        fd = open("/dev/i2c-3", O_RDWR);
        if (fd < 0)
        {
                printf("Faild to open i2c port\n");
                return fd;
        }

        ret = ioctl(fd, I2C_SLAVE, 0x10);
        if (ret < 0)
        {
                printf("Unable to get bus access to talk to slave\n");
                close(fd);
                return ret;
        }

        uint8_t dammy[4];
        dammy[0] = 0x05;
        ret = write(fd, &dammy, 1);
        if (ret < 0)
                return ret;
        ret = read(fd, &dammy, 4);
        if (ret < 0)
                return ret;

        close(fd);
        usleep(4000);

        return 0;
}

int get_general_6(void)
{
        int fd, ret;
        packet p;

        fd = open("/dev/i2c-3", O_RDWR);
        if (fd < 0)
        {
                printf("Faild to open i2c port\n");
                return fd;
        }

        ret = ioctl(fd, I2C_SLAVE, 0x10);
        if (ret < 0)
        {
                printf("Unable to get bus access to talk to slave\n");
                close(fd);
                return ret;
        }

        uint8_t dammy[4];
        dammy[0] = 0x06;
        ret = write(fd, &dammy, 1);
        if (ret < 0)
                return ret;
        ret = read(fd, &dammy, 4);
        if (ret < 0)
                return ret;

        close(fd);
        usleep(4000);

        return 0;
}

int get_eeprom(void)
{
        int fd, ret;
        packet p;

        fd = open("/dev/i2c-3", O_RDWR);
        if (fd < 0)
        {
                printf("Faild to open i2c port\n");
                return fd;
        }

        ret = ioctl(fd, I2C_SLAVE, 0x15);
        if (ret < 0)
        {
                printf("Unable to get bus access to talk to slave\n");
                close(fd);
                return ret;
        }

        uint8_t dammy[4];
        dammy[0] = 0x01;
        ret = write(fd, &dammy, 1);
        if (ret < 0)
                return ret;
        ret = read(fd, &dammy, 2);
        if (ret < 0)
                return ret;

        close(fd);
        usleep(4000);

        return 0;
}

int get_init_status(void)
{
        int fd, ret;
        packet p;

        fd = open("/dev/i2c-3", O_RDWR);
        if (fd < 0)
        {
                printf("Faild to open i2c port\n");
                return fd;
        }

        ret = ioctl(fd, I2C_SLAVE, 0x17);
        if (ret < 0)
        {
                printf("Unable to get bus access to talk to slave\n");
                close(fd);
                return ret;
        }

        uint8_t dammy[4];
        dammy[0] = 0x01;
        ret = write(fd, &dammy, 1);
        if (ret < 0)
                return ret;
        ret = read(fd, &dammy, 2);
        if (ret < 0)
                return ret;

        close(fd);
        usleep(4000);

        return 0;
}

int main(void)
{
	int ret = 0;
                ret = get_general_4();
		if(ret != 0){
			return -1;
		}
                ret = get_general_5();
		if(ret != 0){
			return -1;
		}
                ret = get_general_6();
		if(ret != 0){
			return -1;
		}
                ret = get_eeprom();
		if(ret != 0){
			return -1;
		}
                ret = get_init_status();
		if(ret != 0){
			return -1;
		}
}

