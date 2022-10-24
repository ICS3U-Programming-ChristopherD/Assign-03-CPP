// Copyright (c) 2022 Chris Di Bert All rights reserved.
// .
// Created by: Chris Di Bert
// Date: Oct.19, 2022
// This program calculates solutions of quadratic equations.

#include <cmath>
#include <iostream>
#include <string>

// Console colour function
void userColour() {
    // Initializing colour variables:
    std::string colourString, userChoice, userColourChoice;
    int colourInt;

    // Defining colours to be used in terminal output
#define BLACK "\033[30m"   /* Black */
#define RED "\033[31m"     /* Red */
#define GREEN "\033[32m"   /* Green */
#define YELLOW "\033[33m"  /* Yellow */
#define BLUE "\033[34m"    /* Blue */
#define MAGENTA "\033[35m" /* Magenta */
#define CYAN "\033[36m"    /* Cyan */
#define WHITE "\033[37m"   /* White */

    // Header of colour menu
    std::cout << "COLOURS\n";
    std::cout << "=======\n";

    // For loop which displays the colour choice menu:
    std::string colours[7] = {"Blue", "Green", "Cyan", "Red", "Magenta",
                              "Yellow", "White"};
    for (int i = 0; i < 7; i++) {
        std::cout << i << ". " << colours[i] << "\n";
    }

    // Separates menu from choice prompt
    std::cout << "=======\n\n";

    // Gets user's choice
    std::cout << "Enter the number of one of the colours in the list:\n";
    std::cout << ">> ";
    std::cin >> colourString;
    std::cout << "\n";

    // Tries casting user's input from string to int:
    try {
        colourInt = std::stoi(colourString);
    }

    // Exception thrown if user's input was not a number:
    catch (std::invalid_argument) {
        std::cout << "You must enter an integer.\n\n";
        userColour();
    }

    // Switch statement to determine console colour
    switch (colourInt) {
        case 0:
            userColourChoice = "\033[34m";
            std::cout << userColourChoice << "";
            break;
        case 1:
            userColourChoice = "\033[32m";
            std::cout << userColourChoice << "";
            break;
        case 2:
            userColourChoice = "\033[36m";
            std::cout << userColourChoice << "";
            break;
        case 3:
            userColourChoice = "\033[31m";
            std::cout << userColourChoice << "";
            break;
        case 4:
            userColourChoice = "\033[35m";
            std::cout << userColourChoice << "";
            break;
        case 5:
            userColourChoice = "\033[33m";
            std::cout << userColourChoice << "";
            break;
        case 6:
            userColourChoice = "\033[37m";
            std::cout << userColourChoice << "";
            break;
        default:
            std::cout << "Invalid choice\n\n";
            userColour();
            break;
    }
}

// Main function
int main() {
    // Asks user for the console colour
    userColour();

    // Initializing string variables to be converted to float:
    std::string userA, userB, userC;

    // Initializing variables used to restart:

    std::string restart, invalidRestart;

    // Initializing float variables to be used in solution calculation:
    float a, b, c;

    // Gets the 'a' value of the quadratic
    std::cout << "Enter the 'a' value of the quadratic\n";
    std::cout << ">> ";
    std::cin >> userA;
    std::cout << "\n";

    // Checks if the 'a' value is a number:
    try {
        a = std::stoi(userA);
    }

    // Exception thrown if the user did not enter a number:
    catch (std::invalid_argument) {
        std::cout << "You did not enter a number, enter any key to "
                  << "try again.\n\n";
        std::cin >> invalidRestart;
        std::cout << "\n\n\n\n";
        return main();
    }

    // Checks if the 'a' value is equal to 0:
    while (a == 0) {
        std::cout << "The 'a' value cannot be equal to 0.\n\n";
        std::cout << "Enter the 'a' value of the quadratic:\n";
        std::cout << ">> ";
        std::cin >> userA;
        try {
            a = std::stoi(userA);
        }

        // Exception thrown if the user did not enter a number:
        catch (std::invalid_argument) {
            std::cout << "You did not enter a number, enter any key to "
                      << "try again.\n\n";
            std::cin >> invalidRestart;
            std::cout << "\n\n\n\n";
            return main();
        }
    }

    // Gets the 'b' value of the quadratic
    std::cout << "Enter the 'b' value of the quadratic\n";
    std::cout << ">> ";
    std::cin >> userB;
    std::cout << "\n";

    // Checks if the 'b' value is a number:
    try {
        b = std::stoi(userB);

        // Exception thrown if the user did not enter a number:
    } catch (std::invalid_argument) {
        std::cout << "You did not enter a number, enter any key to "
                  << "try again.\n\n";
        std::cin >> invalidRestart;
        std::cout << "\n\n\n\n";
        main();
    }

    // Gets the 'c' value of the quadratic
    std::cout << "Enter the 'c' value of the quadratic\n";
    std::cout << ">> ";
    std::cin >> userC;
    std::cout << "\n";

    // Checks if the 'c' value is a number:
    try {
        c = std::stoi(userC);

        // Exception thrown if the user did not enter a number:
    } catch (std::invalid_argument) {
        std::cout << "You did not enter a number, enter any key to "
                  << "try again.\n\n";
        std::cin >> invalidRestart;
        std::cout << "\n\n\n\n";
        main();
    }

    // Declares the discriminant:
    float discriminant = b * b - 4 * a * c;

    // Deciding root type based on discriminant value:
    if (discriminant > 0) {
        float unknown1 = (-b + sqrt(discriminant)) / (2 * a);
        float unknown2 = (-b - sqrt(discriminant)) / (2 * a);
        std::cout << "The function has two real roots.\n";
        std::cout << "x1 = " << unknown1 << "\n";
        std::cout << "x2 = " << unknown2 << "\n";
    } else if (discriminant == 0) {
        std::cout << "The function has one real root." << std::endl;
        float unknown1 = -b / (2 * a);
        std::cout << "x1 = x2 = " << unknown1 << std::endl;

        // Code executed if the discriminant is less than 0:
    } else {
        float realPart = -b / (2 * a);
        float imaginaryPart = sqrt(-discriminant) / (2 * a);
        std::cout << "The function has two complex roots." << std::endl;
        std::cout << "x1 = " << realPart << "+" << imaginaryPart << "i\n\n";
        std::cout << "x2 = " << realPart << "-" << imaginaryPart << "i\n\n";
    }

    // Asks the user if they want to restart:
    std::cout << "Enter 'y' if you would like to restart: \n";
    std::cout << "Enter anything else to stop the program\n";
    std::cout << ">> ";
    std::cin >> restart;

    // If the user entered 'y', console is cleared and
    // the program restarts:
    if (restart == "y") {
        std::cout << "\n\n\n\n";
        main();
    }
}
