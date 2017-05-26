#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char *get_word(int num_of_lines, int random_number, char word_container[], FILE *fp); 
int word_counter(int argc, char **argv);
int strcmp_cap_or_lower(char user_guess, char *rdom);

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
	
	// NEW STUF***********************************************************************
	//char user_character = getchar();
	// visual format in these lines possibly put in it own function
	char display_word[37] = {'\0'};
	int space = 1;
	char display = '_';
	int guess_num = 0;
	for(int i = 0; i < strlen(random); i++){
		printf("%*c ", space, display );
		
	}
	// ******************************************* 
	char user_guess = getchar();
	while(1){
		guess_num++;
		char *rdom;
		*rdom = *(random + i);
		for(int i = 0; i < strlen(random); i++){
			int comparison = strcmp_cap_or_lower(user_character, rdom);
			if(strcmp_cap_or_lower == 0){
				count++;
				display_word[i] = *(random + i);
			}else{
				display_word[i] = display;
			}
			guess++;
			if (count == strlen(random - 1)){
				printf("you won");
				break;
			}
		}
		user_guess = '\0';
		user_guess = getchar;
	}
	//****************
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


// Everything above is working so far will add everything at this function call
int strcmp_cap_or_lower(char user_guess, char *rdom)  //get user guess from  getchar in previous lines and assess for the capital or lower case and random word.
{
	int result = 1;
	char case_conversion = ('a' - 'A');
	int guess = 5;
	if(user_guess >  'Z'){  //subtract 32 to get lowercase too
		if((user_guess == *(random + i) ||((user_guess - case_conversion) == *(random + i))){
			result = 0;
		}else{
			continue;
		}
	}else{
		if((user_guess == *(random + i) || ((user_guess + case_conversion) == *(random + i))){
			result = 0;
		}else{
			continue;
		}
	}
	
	return(result);

}
