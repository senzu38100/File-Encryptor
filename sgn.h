/* sgn.h */
#define _GNU_SOURCE // to make the function assert_perror work
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/random.h>
#include <fcntl.h>

int8 *securerand(int16);
int8 *readkey(int8*);
int main(int, char**);
