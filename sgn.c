/* sgn.c */
#include "sgn.h"

int8 *securerand(int16 size) {
	
	int8 *p, *start;
	size_t n;
	
	assert(size > 0);
	p = (int8 *)malloc(size);
	assert(p);
	
	n = getrandom(p, (size_t)size, GRND_RANDOM|GRND_NONBLOCK);

	if (n == size)
		return p;
	else if( n < 0) {
		free(p);
		return 0;
	}	
	fprintf(stderr, "Warning: Entropy pool is empty. This might take longer than usual \n");
	p += n;
	n= getrandom(p, (size-n), GRND_RANDOM);

	if (n==size)
		return start;
	else  (n < 0) {
		free(start);
		return 0;
	}
		
}

int main(int argc, char *argv[]) {
	Arcfour *rc4; 
	char *infile, *outfile;
	int infd, outfd;
	int 8 *key;
	int16 keysize;
	int16 padsize;
	int16 padsize16;
	int8 *padsize8;
	int8 *padding;

	if (argc < 3) {
		fprintf(stderr, "Usage: %s <infile> <outfile>\n", *argv);
		return -1;
	}
	
	infile = argv[1];
	outfile = argv[2];

	infd = open(infile, O_RDONLY);
	if (infd < 1) {
		perror("open");
		return -1;
	}
	
	outfd = open(outfile, O_WRONLY|O_CREAT, 00600); // so only our user will be able to read that file
	if (outfd < 1) {
		close(infd);
		perror("open");
		return -1;	
	}

//	key = readkey("Key:");
//	assert(key);
	keysize = (int16)strlen((char *)key);
	
	
	padsize8 = securerand(2);
	padsize16 = (int16 *)padsize8;
	padsize = *padsize16;
	printf("padsize: %d\n", (int)padsize);
	
	close(infd);
	close(outfd);
	free(padsize8);

	return 0;
}

