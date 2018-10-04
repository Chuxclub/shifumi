#include <iostream>
#include "std_lib_facilities.h"
#include "termcolor.hpp"
#include "player_vs_ai_module.h"
#include "TSS.h"

int main()
{
    char user_choice = ' ';

    MainTitleSeparator(24, "WELCOME TO SHIFUMI BATTLE!", "green");
    std::cout << "\n";

    do
    {
        std::cout << "\n";
        std::cout << "Want to challenge me, human (Press 'y' for yes, any key to exit) ? ";
        std::cin >> user_choice;

        switch (user_choice)
        {
            case 'y':
                player_vs_ai_mode();
                break;

            default:
                break;
        }

    } while(user_choice == 'y');

    std::cout << "\n";
    MainSeparator(74);

    return 0;
}