// Libs
#include <stdio.h>
#include "gallows.h"

/**
 * Método de seleção de header
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
        // Win
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