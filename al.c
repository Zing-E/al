/* al - simply prints the alphabet */

#include <ctype.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int specific_flag = 0;
	int n = 1;

	if(*++argv && isalpha(*argv[0]))
		specific_flag = 1;

	if(specific_flag) {
		for(char c = 'a'; c <= 'z'; c++, n++)
			if(c == *argv[0]) {
				if(n < 10)
					printf("0%d. %c\n", n, c);
				else
					printf("%d. %c\n", n, c);
				break;
			}
		
		return 0;
	}

	for(char c = 'a'; c <= 'z'; c++, n++)
		if(n < 10)
			printf("0%d. %c\n", n, c);
		else
			printf("%d. %c\n", n, c);

	return 0;
}
