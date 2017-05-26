#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char *get_word(int num_of_lines, int random_number, char word_container[], FILE *fp); 
int word_counter(int argc, char **argv);
int main(int argc, char **argv)
{
	FILE *fp;
	fp = fopen(argv[1], "r");
	char word_container[36];
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
	printf("This is the random list row -----> %d \n", list_row);

	printf("This is random word\n");
	char * random = get_word(num_of_words, list_row, word_container, fp);
	printf("This is letter in random word ---> %c\n", *(random + 1));
	printf("This is word----> %s", random); 
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


char * get_word(int num_of_lines, int random_number, char word_container[], FILE *fp)
{
	int count = 0;
	for (int i = 0; i <= num_of_lines; i++){
		fgets(word_container, 36, fp);
		if ( i == random_number){
			word_container[strlen(word_container) -1] = '\0';
			return(word_container);
			break;
		}else{
			continue;
		}
	}
}
