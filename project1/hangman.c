#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char *get_word(int num_of_lines, int random_number, char word_container[], FILE *fp); 
int word_counter(int argc, char **argv);
int strcmp_cap_or_lower(char user_guess, char rdom);

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
	printf("This is word----> %s\n", random);
	printf("length = %d\n", strlen(random));
	
	// NEW STUF***********************************************************************
	//char user_character = getchar();
	// visual format in these lines possibly put in it own function
	//char display_word[37] = {'\0'};
	char *display_word = (char*) malloc(strlen(random + 1)); //remove if doesnt work
	int space = 1;
	char display = '_';
	int guess_num = 0;
	for(int i = 0; i < strlen(random); i++){
		printf("%*c ", space, display );
		
	}
	// ******************************************* 
	//printf("input a char: ");
	//char mike[40];
	//fgets(mike,40, stdin);
	//mike[strlen(mike) - 1] = '\0';
	//char user_guess = mike[0];
	//int i;
	int count = 0;
	while(1){
		guess_num++;
		printf("\ninput a char: ");
		char mike[40] =  {'\0'};
		fgets(mike, 40, stdin);
		mike[(strlen(mike) - 1)] = '\0';
		char user_guess = '\0';
		user_guess = mike[0];
		int i;
		for(i = 0; i < (strlen(random)); i++){
			char rdom = '\0';
			rdom = random[i];
			printf("this is rdom letter ----> %c \n", rdom);
			printf("this is guess number ---> %d and random[%d] index character ---> %c\n", guess_num, i, random[i]);
			int comparison;
			comparison = strcmp_cap_or_lower(user_guess, rdom);
			printf("comparison number before the branch---> %d", comparison);
			if(comparison == 0){
				printf("This is print statement\n");
				count++;
				*(display_word + i) = user_guess; //go back to display_word[i] if it doesnt work
			}else if(comparison != 0 && ((*(display_word + i) < 'A' && *(display_word + i) > 'Z') || (*(display_word + i) < 'a' && 
					*(display_word + i) > 'z'))){
				printf("This is the comparison number ----> %d\n", comparison);
				printf("This is underscore in else\n");
				*(display_word + i) = display;
			}
			if (count == (strlen(random))){
				printf("COUNT - %d\n", count);
				printf("LENGTH: %ld\n", strlen(random));
				printf("Guess num is %d", guess_num);
				printf("you won");
				printf("random word ---->\n");
				printf("%s", random);
				break;
			}
		}
		//display_word[i+1] = '\0';
		printf("Test to print word -----------------------> \n");
		for(int x = 0; x < strlen(random); x++){
 			//printf("letter");
			printf("%c", display_word[x]);
		}
		//printf("input a char: ");
		//fgets(mike, 40, stdin);
		//mike[(strlen(mike) - 1)] = '\0';
		//user_guess = mike[0];
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
	rewind(fp);
	return(count);
}


char * get_word(int num_of_lines, int random_number, char word_container[], FILE *fp)
{
	int count = 0;
	for (int i = 0; i <= num_of_lines; i++){
		fgets(word_container, 36, fp);
		if ( i == random_number){
			word_container[strlen(word_container) -1] = '\0';
			return(word_container);
		}
	}
}

// Everything above is working so far will add everything at this function call
int strcmp_cap_or_lower(char user_guess, char rdom)  //get user guess from  getchar in previous lines and assess for the capital or lower case and random word.
{
	int result = 0;
	user_guess = tolower(user_guess);
	rdom = tolower(rdom);
	if ( rdom == user_guess ){
		result = 0;
	}else{
		result = 1;
	}
	user_guess = '\0';
	rdom = '\0';
	return(result);
}
