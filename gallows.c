// Libs
#include "gallows.h"

// Global's properties
char newChance[CHANCE_LENGTH];

/**
 * Set level for game
 */
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
		default:
			range;
			break;
    }
    
    return range;
}

/**
 * Select ASCII Art
 */
void asciiArt(int type, char gameName[], float *results) {
    switch(type) {
        // Header game
        case 0:
            printf(ANSI_COLOR_GREEN "         __          " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_GREEN "       _|  |_        " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_GREEN "     _|      |_      " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_GREEN "    |  _    _  |     " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_GREEN "    | |_|  |_| |     " ANSI_COLOR_RESET "     %s\n", gameName);
            printf(ANSI_COLOR_GREEN " _  |  _    _  |  _  " ANSI_COLOR_RESET "       Game\n");
            printf(ANSI_COLOR_GREEN "|_|_|_| |__| |_|_|_| " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_GREEN "  |_|_        _|_|   " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_GREEN "    |_|      |_|     " ANSI_COLOR_RESET "\n");
            break;
        // Win game
        case 1:
            printf(ANSI_COLOR_YELLOW "  ___________        " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_YELLOW "  \\___===___/       " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_YELLOW " .-\\:      /-.      " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_YELLOW "( (|:.     |) )      " ANSI_COLOR_RESET "Congratulations!\n");
            printf(ANSI_COLOR_YELLOW " '-|:.     |-'       " ANSI_COLOR_RESET "   You Win!\n");
            printf(ANSI_COLOR_YELLOW "   \\::.    /        " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_YELLOW "    '::. .'          " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_YELLOW "      ) (            " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_YELLOW "    _.'_'._          " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_YELLOW "    \"\"\"\"\"\"\"   " ANSI_COLOR_RESET "\n");
            break;
        // Lose game
        case 2:
            printf(ANSI_COLOR_RED "          _.--""--._        " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_RED "         / _    _ \\        " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_RED "     _  ( (_\\  /_) )  _    " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_RED "    {  \\._\\  /\\  /_./  } " ANSI_COLOR_RESET "     Sorry\n");
            printf(ANSI_COLOR_RED "    /_'=-.}______{.-='_\\   " ANSI_COLOR_RESET " You Lose!\n");
            printf(ANSI_COLOR_RED "     _  _.=('''')=._  _     " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_RED "    (_''_.-''~~''-._''_)    " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_RED "     {_'            '_}     " ANSI_COLOR_RESET "\n");
            break;
        // Analytics
        case 3:
            printf(ANSI_COLOR_MAGENTA "      _____           " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_MAGENTA "    /_____/\\         " ANSI_COLOR_RESET " Game Results\n");
            printf(ANSI_COLOR_MAGENTA "   /_____\\\\ \\      " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_MAGENTA "  /_____\\ \\\\ /     " ANSI_COLOR_RESET "   Total Games: %.0f\n", results[0]);
            printf(ANSI_COLOR_MAGENTA " /_____/ \\/ / /      " ANSI_COLOR_RESET " Guesses: %.0f\n", results[1]);
            printf(ANSI_COLOR_MAGENTA "/_____/ /   \\//\\    " ANSI_COLOR_RESET "  Lose: %.0f\n", results[2]);
            printf(ANSI_COLOR_MAGENTA "\\_____\\//\\   / /   " ANSI_COLOR_RESET "   Win: %.0f\n", results[3]);
            printf(ANSI_COLOR_MAGENTA " \\_____/ / /\\ /     " ANSI_COLOR_RESET "\n");
            printf(ANSI_COLOR_MAGENTA "  \\_____/ \\\\ \\    " ANSI_COLOR_RESET "    Lose Percent: %.2f%%\n", results[4]);
            printf(ANSI_COLOR_MAGENTA "   \\_____\\ \\\\     " ANSI_COLOR_RESET "    Win Percent: %.2f%%\n", results[5]);
            printf(ANSI_COLOR_MAGENTA "    \\_____\\/        " ANSI_COLOR_RESET "\n\n");
            break;
    }
}

/**
 * New chance for player
 */
bool tryAgain() {
    printf("Do you want a new chance? (y/n) ");
    scanf("%s", &newChance[0]);
    
    if (strcmp("n", newChance) == 0) {
        return true;
    }
    else {
        //system("clear");
		system("cls");
    }
    
    return false;
}
