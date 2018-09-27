//
// Created by florian on 25/09/18.
//

#ifndef SHIFUMI_PLAYER_VS_AI_MODULE_H
#define SHIFUMI_PLAYER_VS_AI_MODULE_H

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CORE GAME ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void player_vs_ai_mode();

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */





/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ GAME PARTS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

char ai_choice();

void user_input_test(char &choice);


int user_win_count(char choice, char computer_choice);
int computer_win_count(char choice, char computer_choice);
void print_winner (char choice, char computer_choice);


void deathmatch (int &player_won_rounds, int &computer_won_rounds, char &choice, char &computer_choice);
void print_battle_winner(int player_won_rounds, int computer_won_rounds);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#endif //SHIFUMI_PLAYER_VS_AI_MODULE_H
