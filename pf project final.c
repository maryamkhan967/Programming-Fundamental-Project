#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>

#define ROCK 1   //USING MACROS
#define PAPER 2
#define SCISSORS 3

void top(void);    //FUNCTION PROTOTYPE
void printTitle(char a[]);
void guess_word(int lenght);
void game_rock_paper_scissor(void);


int main(){
	int choice,lenght;
	char other_choice;
	
	top();
	
	printf("\n\nWe have three different games.");
	choice:
	printf("\n\n1-\tGUESS THE WORD\n2-\tROCK, PAPER, SCISSOR\n\nEnter the game you want to play (Enter no. of games): ");
   
	scanf("%d",&choice);
	
	switch(choice){
		case 1:
			
			printTitle("WORD GAME");
			printf("\n\nThis game will predict the name\nFirst you have to think about any word");
			printf("\nEnter the lenght of word: ");
            scanf("%d",&lenght);
            guess_word(lenght);
            printf("\nDo you want to play any other game(Y/y or N/n): ");
            getchar();
            scanf("%c",&other_choice);
            if(other_choice=='Y' || other_choice=='y')
                goto choice;
            break;
            
		case 2:
			
			printTitle("ROCK, PAPER, SCISSORS GAME");
			game_rock_paper_scissor();
			printf("\nDo you want to play any other game(Y/y or N/n): ");
            getchar();
            scanf("%c",&other_choice);
            if(other_choice=='Y' || other_choice=='y')
                goto choice;
			break;

		default:
			
			printf("\n\nINVALID INPUT.");
			goto choice;		
	}
	system("@cls||clear");
	printTitle("Thanks for playing!");	
}

//This function is for printing the heading.
void top(void)   {
	int i;
	printf("\n\n\t\t\t");
	printf("%c",201);
	
	for(i=0;i<17;i++)
	
		printf("%c",205);
		
	printf("%c\n\t\t\t%c   WELCOME TO    %c\n\t\t\t%c   HUB GAMES     %c\n\t\t\t%c",187,186,186,186,186,200);
	
	for(i=0;i<17;i++)
	printf("%c",205);
	printf("%c",188);
}

//This function is designed to print the heading of each game name.
void printTitle(char a[]){
    int i, j = 0;
    printf("\n\n");
    printf("%c%c",176,177);
    
    for( i = 0; i <= strlen(a)+7; i++)
        printf("%c",178);
        
    printf("%c%c\n",177,176);
    printf("%c%c%c%c%c ",176,177,178,177,176);
    
    while(a[j]!='\0'){
        printf("%c",a[j]);
        j++;
    }
    printf(" %c%c%c%c%c\n",176,177,178,177,176);
    printf("%c%c",176,177);
    
    for(i = 0; i <= strlen(a)+7; i++)
        printf("%c",178);
    printf("%c%c\n",177,176);	//The box is made up of the characters 176, 177, and 178,
					// which are used to create the top and bottom borders and the sides of the box
}

//Function for guess the word
void guess_word(int lenght){
	int i, j;
	char keepPlaying = 'Y';
	char alphabets[7][4]={{'A','B','C','D'},
                         {'E','F','G','H'}, 
                         {'I','J','K','L'},
                         {'M','N','O','P'},
                         {'Q','R','S','T'},
                         {'U','V','W','X'},
                         {'Y','Z'}};
    do{
	    printf("\n");
	    printf("|    column1\t|    column2\t|    column3\t|    column4\t|\n");
	    for(i=0;i<7;i++){
			printf("|");
	        for(j=0;j<4;j++){
	            printf("\t%c\t|",alphabets[i][j]);
	        }
	        printf("\n");
	    }
	    
	    int choiceColumns[lenght], secondChoiceColumns[lenght];
	    printf("\n");
	    
	    for(i=0;i<lenght;i++){
	        printf("Enter the Column of %d letter: ",i+1);
	        scanf("%d",&choiceColumns[i]);
	    }
	    
	    printf("\n");
	    printf("|    column1\t|    column2\t|    column3\t|    column4\t|    column5\t|    column6\t|    column7\t|\n");
	    for(i=0;i<lenght;i++){
			printf("|");
	        for(j=0;j<7;j++){
	            printf("\t%c\t|",alphabets[j][choiceColumns[i]-1]);
	        }
	        printf("\n");
	    }
	    printf("\n");
	    for(i=0;i<lenght;i++){
	        printf("Again! Enter the Column of %d letter: ",i+1);
	        scanf("%d",&secondChoiceColumns[i]);
	    }
	    printf("\nThe predict Word is: ");
	    for(i=0;i<lenght;i++){
	    	printf("%c",alphabets[secondChoiceColumns[i]-1][choiceColumns[i]-1]);
	    }
	    printf("\n");	
	  	
        getchar();
		printf("Do you want to keep playing? [Y/N]: ");
		scanf("%c",&keepPlaying);	
    }while(keepPlaying == 'y' || keepPlaying == 'Y');
}
 //Function for rock paper scissor
// Function for rock paper scissor
void game_rock_paper_scissor(void) {
    srand(time(NULL)); // srand is the seed for generating random numbers

    int player_throw = 0, computer_throw = 0;
    bool draw = false;
    char keepPlaying = 'Y';

    do {
        do {
            printf("\nSelect Your Throw.\n");
            printf("1: Rock\n");
            printf("2: Paper\n");
            printf("3: Scissors\n");
            printf("Selection: ");
            scanf("%d", &player_throw);

            // Validate player_throw
            if (player_throw < 1 || player_throw > 3) {
                printf("\nInvalid choice. Please select 1, 2, or 3.\n");
                continue; // Prompt again
            }

            computer_throw = (rand() % 3) + 1;

            if (computer_throw == ROCK)
                printf("\nComputer throws ROCK.\n");
            else if (computer_throw == PAPER)
                printf("\nComputer throws PAPER.\n");
            else if (computer_throw == SCISSORS)
                printf("\nComputer throws SCISSORS.\n");

            draw = false;
            if (player_throw == ROCK && computer_throw == SCISSORS)
                printf("\nROCK beats SCISSORS. YOU WIN.\n\n");
            else if (player_throw == ROCK && computer_throw == PAPER)
                printf("\nPAPER beats ROCK. YOU LOSE.\n\n");
            else if (player_throw == SCISSORS && computer_throw == ROCK)
                printf("\nROCK beats SCISSORS. YOU LOSE.\n\n");
            else if (player_throw == SCISSORS && computer_throw == PAPER)
                printf("\nSCISSORS beats PAPER. YOU WIN.\n\n");
            else if (player_throw == PAPER && computer_throw == ROCK)
                printf("\nPAPER beats ROCK. YOU WIN.\n\n");
            else if (player_throw == PAPER && computer_throw == SCISSORS)
                printf("\nSCISSORS beats PAPER. YOU LOSE.\n\n");
            else {
                printf("\nDRAW! Play Again.\n\n");
                draw = true;
            }
        } while (draw);

        getchar(); // To consume the newline character left by scanf
        printf("Do you want to keep playing? [Y/N]: ");
        scanf(" %c", &keepPlaying); // Note the space before %c to skip any leftover newline characters
    } while (keepPlaying == 'y' || keepPlaying == 'Y');
}
	1
   //END OF PROGRAM!
