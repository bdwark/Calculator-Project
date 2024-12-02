#include "Menu.h"
#include "Calculator.h"

int main() {
    Calculator calc;
    int option;

    while (true) {
        displayMainMenu();
        std::cin >> option;

        switch (option) {
            case 1:
                handleBasicOperations(calc);
                break;
            case 2:
                handleStatisticalOperations(calc);
                break;
            case 3:
                std::cout << "Exiting program.\n";
                return 0;
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}



