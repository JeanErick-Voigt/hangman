#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	//char *array = "Johnny";
	char line[15];
	char *word = "J";
	char  str[20] = {'\0'};
	//printf("The word");
	fgets(line, 15, stdin);
	int x = strlen(line);
	line[x - 1] = '\0';
	printf("length %d\n", x);
	strcat(str, line);
	printf("%s\n" , str);
	if (strcmp (str, word) == 0) {
		printf("the same");
	}
	//printf("The letter %c", line[1]);
	//return(0);
}
