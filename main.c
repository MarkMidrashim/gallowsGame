// Libs
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <math.h>
#include <locale.h>
#include <windows.h>
#include "gallows.h"

// Global's properties
char secretWord[GALLOWS_WORD], guesses[GALLOWS_WORD], newChance[CHANCE_LENGTH];
int attempts = 0, hit = 0, hanged = 0, lose = 0, win = 0;

/**
 * 
 */
void header() {
    //system("clear");
    float fill[6];
    asciiArt(0, GAME_NAME, fill);
}

/**
 * 
 */
void analytics() {
    system("clear");
	system("cls");
    
    // Calculation
    int total = win + lose;
    double percentWin = ((double)win / (double)total) * 100;
    double percentLose = ((double)lose / (double)total) * 100;
    
    float results[6] = {total, attempts, win, lose, percentLose, percentWin};
    asciiArt(3, GAME_NAME, results);
}

/**
 * Database de palavras
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
 * Verifica se o palpite/letra existe na palavra
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

int level() {
    header();
    int levelGame = 0, range = 10;

    printf("\n   Game Level\n");
    printf("----------------\n");
    printf(ANSI_COLOR_GREEN  "E A S Y"     ANSI_COLOR_RESET "        " ANSI_COLOR_CYAN "1" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_YELLOW "M E D I U M" ANSI_COLOR_RESET "    " ANSI_COLOR_CYAN "2" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_RED    "H A R D"     ANSI_COLOR_RESET "        " ANSI_COLOR_CYAN "3" ANSI_COLOR_RESET "\n");
    printf("----------------\n");
    printf("What level will you play? ");
    scanf("%d", &levelGame);

    // Generate random number
    switch(levelGame) {
        case 1:
            range = 10;
            break;
        case 2:
            range = 20;
            break;
        case 3:
            range = 30;
            break;
    }
    
    return range;
}

/**
 * Verifica se letra existe
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
 * Contador de palpites errados
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
 * Verifica se ganhou
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
 * Verifica se perdeu
 */
bool isLose() {
    if (wrongGuesses() >= GUESSING_NUMBER) {
        lose++;
        return true;
    }
    
    return false;
}

/**
 * Desenho da forca
 */
void drawsGallows() {
    //system("clear");
    
    int hanged = wrongGuesses();

    printf("    _______       \n");
    printf("   |/      |      \n");
    printf("   |      %c%c%c  \n", (hanged >= 1 ? '(' : ' '),    (hanged >= 1 ? '_' : ' '), (hanged >= 1 ? ')' : ' '));
    printf("   |      %c%c%c  \n", (hanged >= 3 ? '\\': ' '),    (hanged >= 2 ? '|' : ' '), (hanged >= 4 ? '/' : ' '));
    printf("   |       %c     \n", (hanged >= 2 ? '|' : ' '));
    printf("   |      %c %c   \n", (hanged >= 5 ? '/' : ' '),    (hanged >= 6 ? '\\' : ' '));
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

void submitGuess() {
    char letter;
    printf("What's the letter? ");
    scanf(" %c", &letter);

    guesses[attempts] = letter;
    attempts++;
}

/**
 * Verifica nova chance para jogador
 */
bool tryAgain() {
    printf("Do you want a new chance? (y/n) ");
    scanf("%s", &newChance[0]);
    
    if (strcmp("n", newChance) == 0) {
        return true;
    }
    else {
        system("clear");
		system("cls");
    }
    
    return false;
}

void game() {
	do {
        drawsGallows();
        submitGuess();    
    } while (!isWin() && !isLose());
}

int main() {
    setlocale(LC_ALL, "Portuguese");
	
	do {
		// Select level & Defines secret word
		readDatabase(level());
		
		game();
		
		float fill[6];
			
		if (!isWin()) {
			asciiArt(1, GAME_NAME, fill);
		}
		
		if (!isLose()) {
			asciiArt(2, GAME_NAME, fill);
		}
		
		if (tryAgain()) {
			break;
		}
    } while (true);
	
    // Analytics
    analytics();
}