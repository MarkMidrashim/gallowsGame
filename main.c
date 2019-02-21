// Libs
#include "gallows.h"

// Global's properties
char secretWord[GALLOWS_WORD], guesses[GALLOWS_WORD];
int attempts = 0, hit = 0, hanged = 0, lose = 0, win = 0;

/**
 * Header
 */
void header() {
    //system("clear");
	system("cls");
	
    float fill[6];
    asciiArt(0, GAME_NAME, fill);
}

/**
 * Analytics
 */
void analytics() {
    //system("clear");
	system("cls");
    
    // Calculation statistic
    int total = win + lose;
    double percentWin = ((double)win / (double)total) * 100;
    double percentLose = ((double)lose / (double)total) * 100;
    
    float results[6] = {total, attempts, win, lose, percentLose, percentWin};
    asciiArt(3, GAME_NAME, results);
}

/**
 * Database words
 */
void readDatabase(int amountWords) {
    FILE* database;

    database = fopen("C:\\Users\\Wilson\\Documents\\Gallows\\database.txt", "r");
    if (database == 0) {
        printf("Database is not available!\n");
        exit(1);
    }

    srand(time(0));

    for(int i = 0; i <= (rand() % amountWords); i++) {
        fscanf(database, "%s", secretWord);
    }

    fclose(database); 
}

/**
 * Checks whether the word contains letter
 */
bool guessesExists(char letter) {
    bool find = false;

    for(int j = 0; j < attempts; j++) {
        if(guesses[j] == letter) {
            find = true;
            break;
        }
    }
    
    return find;
}

/**
 * Checks exists letter
 */
bool letterExists(char letter) {
    for(int i = 0; i < strlen(secretWord); i++) {
        if (letter == secretWord[i]) {
            return true;
        }
    }

    return false;
}

/**
 * Counter wrongs guesses
 */
int wrongGuesses() {
    int wrongs = 0;
    
    for (int i = 0; i < attempts; i++) {
        if (letterExists(guesses[i]) == false) {
            wrongs++;
        }
    }
    
    return wrongs;
}

/**
 * Checks out if it has lose
 */
bool isLose() {
	if (wrongGuesses() >= GUESSING_NUMBER) {
        lose++;
        return true;
    }
	
	return false;
}

/**
 * Checks out if it has won
 */
bool isWin() {
	for (int i = 0; i < strlen(secretWord); i++) {
		if (guessesExists(secretWord[i]) == false) {
			return false;
		}
	}
    
	win++;
	return true;
}

/**
 * Draws gallows
 */
void drawsGallows() {
    //system("clear");
	system("cls");
    
    int wrongs = wrongGuesses();

    printf("    _______       \n");
    printf("   |/      |      \n");
    printf("   |      %c%c%c  \n", (wrongs >= 1 ? '(' : ' '),    (wrongs >= 1 ? '_' : ' '), (wrongs >= 1 ? ')' : ' '));
    printf("   |      %c%c%c  \n", (wrongs >= 3 ? '\\': ' '),    (wrongs >= 2 ? '|' : ' '), (wrongs >= 4 ? '/' : ' '));
    printf("   |       %c     \n", (wrongs >= 2 ? '|' : ' '));
    printf("   |      %c %c   \n", (wrongs >= 5 ? '/' : ' '),    (wrongs >= 6 ? '\\' : ' '));
    printf(" __|__            \n\n");
    
    for(int i = 0; i < strlen(secretWord); i++) {
        if (guessesExists(secretWord[i])) {
            printf("%c ", secretWord[i]);
        } 
        else {
            printf("_ ");
        }
    }
        
    printf("\n");
}

/**
 * Submit letter's guess
 */
void submitGuess() {
    char letter;
    printf("What's the letter? ");
    scanf(" %c", &letter);

    guesses[attempts] = letter;
    attempts++;
}

/**
 * Execute logical game
 */
void game() {
	do {
        drawsGallows();
        submitGuess();    
    } while (!isWin() && !isLose());
}

/**
 * Reset variables for restart game
 */
void resetVariables() {
	memset(secretWord, 0, sizeof(secretWord));
	memset(guesses, 0, sizeof(guesses));
	attempts = 0;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
	
	do {
		// Select level & Defines secret word
		readDatabase(level());
		game();
		
		float fill[6];
		
		if (isWin()) {
			resetVariables();
			asciiArt(1, GAME_NAME, fill);
		}
		else if (isLose()) {
			resetVariables();
			asciiArt(2, GAME_NAME, fill);
		}
		else {
			printf("Your result is undefined!\n");
		}
		
		if (tryAgain()) {
			break;
		}
    } while (true);
	
    // Analytics
    analytics();
	
	printf("Press ENTER to exit this game ");
	char out = fgetc(stdin);
	
	if (out==0x0A) {
		exit(1);
	}
}
