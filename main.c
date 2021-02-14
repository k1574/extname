#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

enum {
	BufSiz = 256,
};

static char *argv0;

void
usage(void)
{
	fprintf(stderr, "usage: %s <path> [num_of_exts]\n", argv0);
	exit(1);
}

char *
sext(char *p, unsigned int n)
{
	unsigned int i, len = strlen(p);
	while(*p++!='.' && len--) ;
	return p ;
}

char *
eext(char *p, unsigned int n)
{
	unsigned int i, len = strlen(p);
	p += len - 1 ;
	while(n--)
		while(len--){
			--p;
			if(*p == '.') break ;
		}
	++p;
	return p ;
}

int
main(int argc, char *argv[])
{
	unsigned int n;
	char *p;

	argv0 = argv[0] ;
	if(argc<2 || argc>3)
		usage();

	p = argv[1] ;

	if(argc==3) n = atoi(argv[2]) ;
	else n = 1 ;

	if(n) printf("%s\n", eext(argv[1], n));
	else printf("%s\n", sext(argv[1], n));

	return 0 ; 
}
