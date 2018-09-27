//
// Created by florian on 25/09/18.
//

#include <iostream>
#include "std_lib_facilities.h"
#include "termcolor.hpp"
#include "player_vs_ai_module.h"

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CORE GAME ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void player_vs_ai_mode()
{
    char new_game = 'y', choice;
    int rounds = 0, player_won_rounds = 0, computer_won_rounds = 0;

    //Assuming the player wants to play at least once, loop can be broken
    //after having won or lost a battle and chosen to exit
    while (new_game == 'y')
    {
        char computer_choice = ai_choice();

        std::cout << "\n\n";
        std::cout << "Your choice, human: ";
        std::cin >> choice;
        user_input_test(choice);

        player_won_rounds += user_win_count(choice, computer_choice);
        computer_won_rounds += computer_win_count(choice, computer_choice);
        print_winner(choice, computer_choice);

        rounds++;

        /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ End game ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

        if(rounds == 3)
        {
            //If draw, enters deathmatch
            deathmatch(player_won_rounds, computer_won_rounds, choice, computer_choice);

            //Else, determines winner of the battle
            print_battle_winner(player_won_rounds, computer_won_rounds);

            std::cout << "\n\n";
            std::cout << "Do you want a new game? Press 'y' to continue, any key to exit: ";
            std::cin >> new_game;

            //All counters are reset after a battle is over
            rounds = 0;
            player_won_rounds = 0;
            computer_won_rounds = 0;
        }

        /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

    }
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */





/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ GAME PARTS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

//Selects a random 'char' in a vector in order to simulate a random choice for shifumi
//Pre-conditions : no arguments, just a subroutine
//Post-conditions : returns a 'char'
char ai_choice()
{
    vector<char> possible_outcomes = {'s', 'p', 'c'};

    srand((unsigned int) time(nullptr));
    constexpr int NUMBER_POSSIBLE_OUTCOMES = 3;
    int x = rand()%NUMBER_POSSIBLE_OUTCOMES;

    char computer_choice = possible_outcomes[x];

    return computer_choice;
}

//Checks if user input is valid, valid inputs are: 'p', 's' or 'c', enters a loop
//if input is not valid
void user_input_test(char &choice)
{
    while (choice != 'p' && choice != 's' && choice != 'c')
    {
        std::cout << termcolor::red << "\n" << "Wrong input!" << termcolor::reset;
        cin.clear();
        cin.ignore(1000, '\n');
        std::cout << "\n" << "Input a valid character ('p', 's' or 'c') : ";
        std::cin >> choice;
        std::cout << "\n";
    }
}

//Checks if player won the round, if yes, adds +1 to the number of won rounds
//If no, adds nothing
int user_win_count(char choice, char computer_choice)
{
    int a = 0;

    if (choice == 's' && computer_choice == 'c')
        a++;

    else if (choice == 'c' && computer_choice == 'p')
        a++;

    else if (choice == 'p' && computer_choice == 's')
        a++;

    else
        a;

    return a;
}

//Same function as above but with the ai
int computer_win_count(char choice, char computer_choice)
{
    int a = 0;

    if (choice == 'c' && computer_choice == 's')
        a++;

    else if (choice == 'p' && computer_choice == 'c')
        a++;

    else if (choice == 's' && computer_choice == 'p')
        a++;

    else
        a;

    return a;
}

//Compares user input with ai random choice and outputs an appropriate message
void print_winner (char choice, char computer_choice)
{
    if (choice == computer_choice)
        std::cout << "Draw!";

    else if (choice == 's' && computer_choice == 'c')
        std::cout << "Stone against cisors: " << termcolor::green << "you win !" << termcolor::reset;

    else if (choice == 'c' && computer_choice == 's')
        std::cout << "Cisors against stone: " << termcolor::red << "you lose !" << termcolor::reset;

    else if (choice == 'c' && computer_choice == 'p')
        std::cout << "Cisors against paper: " << termcolor::green << "you win !" << termcolor::reset;

    else if (choice == 'p' && computer_choice == 'c')
        std::cout << "Paper against cisors: " << termcolor::red << "you lose !" << termcolor::reset;

    else if (choice == 'p' && computer_choice == 's')
        std::cout << "Paper against stone: " << termcolor::green << "you win !" << termcolor::reset;

    else if (choice == 's' && computer_choice == 'p')
        std::cout << "Stone against paper: " << termcolor::red << "you lose !" << termcolor::reset;

    else
        std::cout << termcolor::red <<"Wrong input!" << termcolor::reset;
}

//If there's a draw after the third round, enters a loop until someone wins
//Hence to exit the loop, won rounds between the player and ai must be different
void deathmatch (int &player_won_rounds, int &computer_won_rounds, char &choice, char &computer_choice)
{
    while (player_won_rounds == computer_won_rounds)
    {
        computer_choice = ai_choice();

        std::cout << "\n\n";
        std::cout << "Last chance, human: ";
        std::cin >> choice;

        user_input_test(choice);

        player_won_rounds += user_win_count(choice, computer_choice);
        computer_won_rounds += computer_win_count(choice, computer_choice);
        print_winner(choice, computer_choice);

    }
}

//Prints an appropriate message depending on who won more battles
void print_battle_winner(int player_won_rounds, int computer_won_rounds)
{
    if (player_won_rounds < computer_won_rounds)
        std::cout << "\n\n" << termcolor::red << "I won the game human..." << termcolor::reset;
    else
        std::cout << "\n\n" << termcolor::green << "How is it even possible!" << termcolor::reset;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

