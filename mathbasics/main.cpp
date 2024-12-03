#include "Menu.h"
#include "Calculator.h"

int main() {
    Calculator calc; // makes an instance of the of the Calculator class to perform operations
    int option; // holds the user's numerical input for their choice in the menu prompted below

    while (true) {
        displayMainMenu(); // displays the main menu in a loop unless the 3rd option to leave the program is selected
        std::cin >> option; // gets the user's choice

        switch (option) {
            case 1: // calls the 'BasicOperations' function to handle basic math operations like addition or multiplication
                handleBasicOperations(calc);
                break;
            case 2: // calls the 'StatisticalOperations' function to handle operations for multiple values like mean or median
                handleStatisticalOperations(calc);
                break;
            case 3: // ends the program
                std::cout << "Exiting program.\n";
                return 0;
            default: // given if an invalid option is picked, prompts the user to try again
                std::cout << "Invalid option. Please try again.\n";
        }
    }

    return 0; 
}



