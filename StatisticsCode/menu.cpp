#include "Menu.h"
#include <iostream>
#include <vector>
#include <limits>

void displayMainMenu() {
    std::cout << "1. Basic Operations\n";
    std::cout << "2. Statistical Operations (Mean, Median, Lowest, Highest)\n";
    std::cout << "3. Exit\n";
    std::cout << "Choose an option: ";
}

// basic operations calculator
void handleBasicOperations(Calculator& calc) {
    double currentResult = 0.0;
    char operation;
    double nextNumber;

    std::cout << "\nEnter your first number: ";
    std::cin >> currentResult;

    while (true) {
        std::cout << "Enter an operation (+, -, *, /, ^, r) or 'q' to quit: ";
        std::cin >> operation;

        if (operation == 'q') {
            std::cout << "Final result: " << currentResult << "\nGoodbye!\n";
            break;
        }

        if (operation == 'r') {
            double rootValue;
            std::cout << "Enter the root value (e.g., 2 for square root): ";
            std::cin >> rootValue;
            if (rootValue == 0) {
                std::cerr << "Error: Root value cannot be zero.\n";
                continue;
            }
            currentResult = calc.radical(currentResult, rootValue);
        }
        else {
            std::cout << "Enter the next number: ";
            std::cin >> nextNumber;

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
                std::cout << "Invalid operation. Please try again.\n";
                continue;
            }
        }

        std::cout << "Current result: " << currentResult << "\n";
    }
}


void handleStatisticalOperations(Calculator& calc) {
    int choice;
    std::vector<double> numbers;
    double num;

    std::cout << "\nEnter numbers (type a non-numeric character to stop): ";
    while (std::cin >> num) {
        numbers.push_back(num);
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (numbers.empty()) {
        std::cout << "No numbers entered. Returning to main menu.\n";
        return;
    }

    std::cout << "Choose an operation:\n";
    std::cout << "1. Mean\n2. Median\n3. Lowest\n4. Highest\n";
    std::cin >> choice;

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


