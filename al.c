/* al - print the alphabet to the terminal */

#include <ctype.h>
#include <stdio.h>

struct al_T {
	char c;
	int n;
};

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
	if(argv[1] && isalpha(argv[1][0]) && argv[1][1] == '\0') {

		for(int i = 0; i < 26; i++)
			if(al[i].c == argv[1][0]) {
				print_al(&al[i]);
				break;
			}

		return 0;
	}

	for(int i = 0; i < 26; i++)
		print_al(&al[i]);

	return 0;
}
