#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int word_counter(int argc, char **argv);
int main(int argc, char **argv)
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
	if (strcasecmp (str, word) == 0) {
		printf("the same");
	}

	int num_of_words = word_counter(argc, argv);
	printf("The file count is  ----> %d", num_of_words);
	//printf("The letter %c", line[1]);
	//return(0);

	srand(time(NULL));
	int list_row = rand() % num_of_words;      //the row where the word will come from
	printf("This is the random list row -----> %d", list_row);
}

int word_counter(int argc, char **argv)
{
	FILE *fp;
	char line[36];
	fp = fopen(argv[1], "r");
	int count = 0;
	while(fgets(line, 36, fp) != NULL){
		count++;
	}
	return(count);
	rewind(fp);
}


