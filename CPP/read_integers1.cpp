#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <regex>

int main() {
    std::string restart;

    do {
        std::vector<int> numbers; // Vector to store user's input numbers
        std::set<int> taken_numbers; // Set to keep track of unique numbers
        std::string user_input;

        // Instructions to the user
        std::cout << "\nEnter a series of numbers, type 0 to stop." << std::endl;
        std::cout << "Rules: no negative numbers, no duplicates, and only integers." << std::endl;

        // Read numbers from the user until they type 0
        while (true) {
            std::cout << "Enter a number: ";
            std::cin >> user_input;

            // Check if the input is a valid integer
            std::regex int_pattern("^-?[0-9]+$");
            if (!std::regex_match(user_input, int_pattern)) {
                std::cout << "Error! Only integers are allowed. Try again.\n";
                continue;
            }

            int num = std::stoi(user_input);

            if (num == 0) {
                break; // Stop if the user enters 0
            }

            if (num < 0) { // So the use dont type negative numbers.
                std::cout << "Error! Negative numbers are not allowed. Try again.\n";
                continue;
            }

            // Check if the number already exists in the set
            if (taken_numbers.find(num) != taken_numbers.end()) {
                std::cout << "The number " << num << " is already entered. Try another one.\n";
                continue;
            }

            numbers.push_back(num); // Add the number to the vector
            taken_numbers.insert(num); // Add the number to the set
            std::cout << "The number " << num << " was added.\n";
        }

        // If no numbers were entered, exit the program
        if (numbers.empty()) {
            std::cout << "\nNo numbers were entered. The program is terminating.\n";
            break;
        }

        // Print all entered numbers
        std::cout << "\nThe numbers you entered: ";
        for (int number : numbers) {
            std::cout << number << ", ";
        }
        std::cout << "\n";

        // Calculate the product of all positive numbers
        int product = 1;
        for (int num : numbers) {
            if (num > 0) {
                product *= num;
            }
        }
        std::cout << "The product of all positive numbers: " << product << "\n";

        // Calculate the number of even and odd numbers
        int count_evens = 0, count_odds = 0;
        for (int num : numbers) {
            if (num % 2 == 0) {
                count_evens++;
            } else {
                count_odds++;
            }
        }

        std::cout << "The number of even numbers: " << count_evens << "\n";
        std::cout << "The number of odd numbers: " << count_odds << "\n";

        // Find the second largest number
        std::sort(numbers.begin(), numbers.end()); // Sort the numbers
        if (numbers.size() > 1) {
            std::cout << "The second largest number is: " << numbers[numbers.size() - 2] << "\n";
        } else {
            std::cout << "There are not enough numbers to determine the second largest.\n";
        }

        // Ask the user if they want to run the program again
        while (true) {
            std::cout << "Do you want to run the program again? yes or no: ";
            std::cin >> restart;
            std::transform(restart.begin(), restart.end(), restart.begin(), ::tolower);

            if (restart == "yes" || restart == "no") {
                break;
            } else {
                std::cout << "Invalid answer. Please respond with yes or no.\n";
            }
        }

        if (restart == "no") {
            std::cout << "\nThe program has been successfully terminated.\n";
        }

    } while (restart == "yes");

    return 0;
}
