// Libs
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <locale.h>
#include <windows.h>

// Defines
#define GAME_NAME "Gallows"

#define CHANCE_LENGTH 1
#define GALLOWS_WORD 20
#define GUESSING_NUMBER 5

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

#ifndef TRUE
#  define TRUE  (1==1)
#endif

#ifndef FALSE
#  define FALSE (!TRUE)
#endif

// Methods
void asciiArt(int type, char gameName[], float *results);

void header();
void analytics();
void readDatabase(int amountWords);
bool guessesExists(char letter);
int level();
bool letterExists(char letter);
int wrongGuesses();
bool isWin();
bool isLose();
void drawsGallows();
void submitGuess();
bool tryAgain();
void game();
void resetVariables();
