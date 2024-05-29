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

void print_al(struct al_T *al)
{
	if(al->n < 10)
		printf("0%d. %c\n", al->n, al->c);
	else
		printf("%d. %c\n", al->n, al->c);
}


int main(int argc, char *argv[])
{
	int c;
	int aflag = 0;
	char *a_opt = NULL;

	while((c = getopt(argc, argv, "ha:")) != -1)
		switch(c) {
			case 'h':
				al_usage();
			case 'a':
				aflag = 1;
				a_opt = strdup(optarg);
				break;
			default:
				al_usage();
		}
	
	if(aflag && isalpha(a_opt[0]) && a_opt[1] == '\0') {

		for(int i = 0; i < 26; i++)
			if(al[i].c == a_opt[0]) {
				print_al(&al[i]);
				break;
			}
		free(a_opt);

		return 0;
	}

	for(int i = 0; i < 26; i++)
		print_al(&al[i]);

	return 0;
}

void al_usage(void)
{
	printf("usage: \n"
		" al [option] [letter]\n\n"
		" al	- Prints the alphabelt.\n"
		" al -a  - Prints specific letter.\n");
	
	exit(EXIT_FAILURE);
}
