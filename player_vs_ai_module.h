//
// Created by florian on 25/09/18.
//

#ifndef SHIFUMI_PLAYER_VS_AI_MODULE_H
#define SHIFUMI_PLAYER_VS_AI_MODULE_H

char ai_choice();
void print_winner (char choice, char computer_choice);
int user_win_count(char choice, char computer_choice);
int computer_win_count(char choice, char computer_choice);
void user_input_test(char &choice);
void player_vs_ai_mode();

#endif //SHIFUMI_PLAYER_VS_AI_MODULE_H
