/* al - simply prints the alphabet */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

const char *version = "0.1";

/* This flag means to not print numbers alongside the alphabet */

int nflag;

struct al_T {
	char c;
	int n;
};

int al_compar(const void *, const void *);
void al_specific(char *);
void al_usage(void);
void print_al(struct al_T *);

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

int al_compar(const void *a, const void *b)
{
	return strcmp(*(const char **)a, *(const char **) b);
}

void al_specific(char *arg)
{
	if(isalpha(arg[0]) && arg[1] == '\0') {
		for(int i = 0; i < 26; i++)
			if(al[i].c == arg[0]) {
				print_al(&al[i]);
				break;
			}
	} else {
		fprintf(stderr, "error: al -s must be followed by a single letter(s).\n");
		exit(EXIT_FAILURE);
	}

}

void print_al(struct al_T *al)
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
	int c, sflag;
	nflag = sflag = 0;

	while((c = getopt(argc, argv, "hns:v")) != -1)
		switch(c) {
			case 'h':
				al_usage();
			case 'n':
				nflag = 1;
				break;
			case 's':
				sflag = 1;
				break;
			case 'v':
				printf("al: version: %s\n", version);
				return 0;
			default:
				al_usage();
		}

	if(sflag) {
		qsort(&argv[2], argc - 2, sizeof(char*), al_compar);
		
		argv += 2;

		while(*argv) {
			al_specific(*argv);
			argv++;
		}
	} else
		for(int i = 0; i < 26; i++)
			print_al(&al[i]);

	return 0;
}

void al_usage(void)
{
	printf("usage: \n"
		" al [option] [letter(s)]\n\n"
		" al     - Prints the alphabet.\n"
		" al -h  - Prints this menu.\n"
		" al -n  - Prints the alphabet with no numbers.\n"
		" al -s  - Prints specific letter(s).\n"
		" al -v  - Prints the al version number.\n");
	
	exit(EXIT_FAILURE);
}
