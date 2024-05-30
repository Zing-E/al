/* al - simply prints the alphabet */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct al_T {
	char c;
	int n;
};

void al_usage(void);
void print_al(struct al_T *, int);

struct al_T al[] = {
	{'a', 1},
	{'b', 2},
	{'c', 3},
	{'d', 4},
	{'e', 5},
	{'f', 6},
	{'g', 7},
	{'h', 8},
	{'i', 9},
	{'j', 10},
	{'k', 11},
	{'l', 12},
	{'m', 13},
	{'n', 14},
	{'o', 15},
	{'p', 16},
	{'q', 17},
	{'r', 18},
	{'s', 19},
	{'t', 20},
	{'u', 21},
	{'v', 22},
	{'w', 23},
	{'x', 24},
	{'y', 25},
	{'z', 26},
};

void print_al(struct al_T *al, int nflag)
{
	if(!nflag)
		if(al->n < 10)
			printf("0%d. %c\n", al->n, al->c);
		else
			printf("%d. %c\n", al->n, al->c);
	else
		printf("%c\n", al->c);
}


int main(int argc, char *argv[])
{
	int sflag, nflag, c;
	char *s_opt;

	sflag = nflag = 0;

	while((c = getopt(argc, argv, "hns:")) != -1)
		switch(c) {
			case 'h':
				al_usage();
			case 'n':
				nflag = 1;
				break;
			case 's':
				sflag = 1;
				s_opt = strdup(optarg);
				break;
			default:
				al_usage();
		}
	
	if(sflag) {
		if(isalpha(s_opt[0]) && s_opt[1] == '\0') {
			for(int i = 0; i < 26; i++)
				if(al[i].c == s_opt[0]) {
					print_al(&al[i], nflag);
					break;
				}
			free(s_opt);

			return 0;
		
		} else {
			fprintf(stderr, "error: al -s must be followed by a single letter.\n");
			return -1;
		}
	}

	for(int i = 0; i < 26; i++)
		print_al(&al[i], nflag);

	return 0;
}

void al_usage(void)
{
	printf("usage: \n"
		" al [option] [letter]\n\n"
		" al	- Prints the alphabet.\n"
		" al -n  - Prints the alphabet with no numbers.\n"
		" al -s  - Prints specific letter.\n");
	
	exit(EXIT_FAILURE);
}
