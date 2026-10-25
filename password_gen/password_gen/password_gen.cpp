#include <iostream>
#include <string>
#include <limits>
#include "generator.h"

void Retry()
{
    std::cout << "\nPress Enter twice to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    system("cls");
}

int main()
{
    while (true)
    {
        std::string User_Choice;
        int User_LengthChoice;
        Generate_Password password_generator;

        std::cout << " === Password Generator === \n";
        std::cout << " 1. Generate Password \n";
        std::cout << " 2. Generate Password, with custom length [8 between 64] \n";
        std::cout << "> ";

        std::getline(std::cin, User_Choice);

        if (User_Choice.empty())
        {
            std::cout << "Please select an option.\n";
            Retry();
            continue;
        }

        if (User_Choice == "1")
        {
            password_generator.Password_Generates();
            Retry();
        }
        else if (User_Choice == "2")
        {
            std::cout << "Enter Number Length: ";

            if (!(std::cin >> User_LengthChoice))
            {
                std::cout << "Invalid input. Enter a number.\n";

                std::cin.clear();
                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(), '\n');

                Retry();
                continue;
            }

            if (User_LengthChoice >= 8 && User_LengthChoice <= 64)
            {
                password_generator.Password_Generates(User_LengthChoice);
                Retry();
            }
            else
            {
                std::cout << "Please enter a length between 8 and 64.\n";
                Retry();
            }
        }
        else
        {
            std::cout << "Invalid choice. Select 1 or 2.\n";
            Retry();
        }
    }
    return 0;
}