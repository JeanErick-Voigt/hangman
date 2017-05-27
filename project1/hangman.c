#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>


//game of hangman that will loop till you don't want to play anymore
//should keep track of wins and losses
char *get_word(int num_of_lines, int random_number, char word_container[], FILE *fp); 
int word_counter(char **argv);
int strcmp_cap_or_lower(char user_guess, char rdom);

int main(int arg, char **argv)
{
	FILE *fp;
	fp = fopen(argv[1], "r");
	char word_container[36];

	int num_of_words = word_counter(argv);
	printf("The file count is  ----> %d", num_of_words);

	char answer[5] = {'\0'};
	int win = 0, loss = 0, game = 0;

	while(1){

		printf("Press q to quit or any character to play\n");
		fgets(answer, 5, stdin);
		printf("The length of answer --> %d\n", strlen(answer));
		//answer[strlen(answer) - 1] = '\0';
		printf("%s", answer);
		if(answer[0] == 'q'){
			exit(1);
		}
		char answer[5] = {'\0'};
		srand(time(NULL));

	
		int list_row = rand() % num_of_words;      //the row where the word will come from

		game++;
		


		char * random = get_word(num_of_words, list_row, word_container, fp);
		printf("This is word----> %s\n", random);
		printf("length = %lu\n", strlen(random));

		printf("Game %d.  %3d Win/ %3d Losses.", game, win, loss);
		
	
		char *display_word = (char*) malloc(strlen(random + 1)); //remove if doesnt work
		int space = 1;
		char display = '_';
		int guess_num = 0;
		for(unsigned int i = 0; i < strlen(random); i++){
			printf("%*c ", space, display );
		
		}
		printf("\n");
		unsigned int count = 0;
		
		int correct_guess = 0;
		while(1){
			printf("this is correct guess count %d", correct_guess);
			if (correct_guess < 1){
				guess_num++;
				//correct_guess = 0;
			}
			if(guess_num == 5){
				printf("you lost");
				loss++;
				break;
			}
			
//			printf("\ninput a char: ");  //changing to the below line
			
			correct_guess = 0;
			printf(" :");
			
			char mike[40] =  {'\0'};
			fgets(mike, 40, stdin);
			mike[(strlen(mike) - 1)] = '\0';
			char user_guess = '\0';
			user_guess = mike[0];
			unsigned int i;
			for(i = 0; i < (strlen(random)); i++){
				char rdom = '\0';
				rdom = random[i];
				printf("this is rdom letter ----> %c \n", rdom);
				printf("this is guess number ---> %d and random[%d] index character ---> %c\n", guess_num, i, random[i]);
				int comparison;
				comparison = strcmp_cap_or_lower(user_guess, rdom);
				printf("comparison number before the branch---> %d", comparison);
				if(comparison == 0){
					if((*(display_word + i) >= 'A') && (*(display_word + i) <= 'Z')){
						printf("Already guessed  that, guess again");
						correct_guess++;
						break;
					}
					else if((*(display_word + i) >= 'a' ) && (*(display_word + i) <= 'z')){
						printf("Already guessed that, guess again");
						correct_guess++;
						break;
					}else{
						printf("This is print statement\n");
						count++;
						*(display_word + i) = user_guess; //go back to display_word[i] if it doesnt work
						correct_guess +=1;
						
					}
				}
				else if(comparison != 0 && ((*(display_word + i) < 'A' && *(display_word + i) > 'Z') || (*(display_word + i) < 'a' && 
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
					win++;
					printf("random word ---->\n");
					printf("%s", random);
					break;
				}
			}
		
			printf("this is guess number---> %d", guess_num);
			for(int x = 0; x < strlen(random); x++){
				printf("%c", display_word[x]);
			}
			printf("Test to print word -----------------------> \n");
			
			for(int x = 0; x < strlen(random); x++){
				printf("%c", display_word[x]);
			}
			if ((guess_num == 5) || (count == (strlen(random)))){
				break;  //breaks out of game loop.
			}
		}
		printf("do you want to play again?");  //big while loop to play again.
	}
	
}

int word_counter(char **argv)
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


char * get_word(int num_of_lines, int random_number, char *word_container, FILE *fp)
{
	for (int i = 0; i <= num_of_lines; i++){
		fgets(word_container, 36, fp);
		if ( i == random_number){
			word_container[strlen(word_container) -1] = '\0';
			return(word_container);
		}
	}
}

// Everything above is working so far will add everything at this function call
int strcmp_cap_or_lower(char user_guess, char rdom)  //get user guess from  getchar in previous 
//lines and assess for the capital or lower case and random word.
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
