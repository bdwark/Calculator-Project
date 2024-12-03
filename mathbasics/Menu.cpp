#include "Menu.h"
#include <iostream>
#include <vector>
#include <limits>

// Prints the prompt that is the main menu with choice of operation
void displayMainMenu() {
    std::cout << "1. Basic Operations\n";
    std::cout << "2. Statistical Operations (Mean, Median, Lowest, Highest)\n";
    std::cout << "3. Exit\n";
    std::cout << "Choose an option: ";
}

// basic operations calculator
void handleBasicOperations(Calculator& calc) {
    double currentResult = 0.0; // states the the first inputted or current value as a double to include decimals
    char operation; // stores the input of the character for all the operations
    double nextNumber; // stores the next value

// prompts and takes the user's first inputted value
    std::cout << "\nEnter your first number: ";
    std::cin >> currentResult;

    while (true) {
        std::cout << "Enter an operation (+, -, *, /, ^, r) or 'q' to quit: "; // gives the list of symbols for the operations
        std::cin >> operation;

        if (operation == 'q') {
            std::cout << "Final result: " << currentResult << "\nGoodbye!\n"; // quites the loop and gives final result
            break;
        }

// handles 'r' for radical input case
        if (operation == 'r') {
            double rootValue;
            std::cout << "Enter the root value (e.g., 2 for square root): ";
            std::cin >> rootValue;
            if (rootValue == 0) {
                std::cerr << "Error: Root value cannot be zero.\n";
                continue;
            }
            currentResult = calc.radical(currentResult, rootValue);
        } else {
            std::cout << "Enter the next number: "; // asks for next number after operation is chosen
            std::cin >> nextNumber;

// chooses case dependent on your equavilant operation symbol and returns result by calling on one of the basic operations
            switch (operation) {
                case '+':
                    currentResult = calc.add(currentResult, nextNumber);
                    break;
                case '-':
                    currentResult = calc.subtract(currentResult, nextNumber);
                    break;
                case '*':
                    currentResult = calc.multiply(currentResult, nextNumber);
                    break;
                case '/':
                    currentResult = calc.divide(currentResult, nextNumber);
                    break;
                case '^':
                    currentResult = calc.exponentiate(currentResult, nextNumber);
                    break;
                default:
                    std::cout << "Invalid operation. Please try again.\n"; // accounts for invalid input and restarts loop
                    continue;
            }
        }

        std::cout << "Current result: " << currentResult << "\n"; // displays current result after operation and next value are applied
    }
}

// statistical operations for multiple inputs
void handleStatisticalOperations(Calculator& calc) {
    int choice; // holds the operation choice chosen, 1-4
    std::vector<double> numbers; // stores the list of numbers inputted in a vector (list)
    double num; // placeholder for each number inputted

    std::cout << "\nEnter numbers (type a non-numeric character to stop): "; // prompts the user to input their numbers and adds them to the vector
    while (std::cin >> num) {
        numbers.push_back(num);
    }
// clears and ignores non numerical inputs
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

// handles case if there are no numbers entered, returns to main menu
    if (numbers.empty()) {
        std::cout << "No numbers entered. Returning to main menu.\n";
        return;
    }

// gives choice of result you'd like to get from your list of values
    std::cout << "Choose an operation:\n";
    std::cout << "1. Mean\n2. Median\n3. Lowest\n4. Highest\n";
    std::cin >> choice;

// chooses case dependent on your equavilant operation number 1-4 and returns result by calling on one of the statistical operations
    switch (choice) {
        case 1:
            std::cout << "Mean: " << calc.calculateMean(numbers) << std::endl;
            break;
        case 2:
            std::cout << "Median: " << calc.calculateMedian(numbers) << std::endl;
            break;
        case 3:
            std::cout << "Lowest: " << calc.findLowest(numbers) << std::endl;
            break;
        case 4:
            std::cout << "Highest: " << calc.findHighest(numbers) << std::endl;
            break;
        default:
            std::cout << "Invalid choice.\n";
    }
}


