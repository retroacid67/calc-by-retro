#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <sstream>

using namespace std;

vector<string> history;

double calculate(double num1, double num2, const string& operation) {
    if (operation == "+") {
        return num1 + num2;
    }
    else if (operation == "-") {
        return num1 - num2;
    }
    else if (operation == "*") {
        return num1 * num2;
    }
    else if (operation == "/") {
        if (num2 == 0) {
            throw runtime_error("Error: Division by zero!");
        }
        return num1 / num2;
    }
    else if (operation == "^") {
        return pow(num1, num2);
    }
    else if (operation == "sqrt") {
        if (num1 < 0) {
            throw runtime_error("Error: Cannot take square root of a negative number!");
        }
        return sqrt(num1);
    }
    else if (operation == "sin") {
        return sin(num1);
    }
    else if (operation == "cos") {
        return cos(num1);
    }
    else if (operation == "tan") {
        return tan(num1);
    }
    else {
        throw invalid_argument("Error: Not a recognized operation!");
    }
}

void getInput(double& number, const string& prompt) {
    cout << prompt;
    while (!(cin >> number)) {
        cout << "Invalid input! Please enter a number: ";
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }
}

void showHistory() {
    cout << "\nCalculation History:\n";
    for (const auto& entry : history) {
        cout << entry << endl;
    }
}

int main() {
    double number1, number2;
    string operation;
    char continueCalculation;

    do {
        cout << "\n--- Simple Calculator ---\n";
        cout << "Available operations: +, -, *, /, ^ (power), sqrt, sin, cos, tan\n";

        // Get first number
        getInput(number1, "Enter first number: ");

        // Get operation
        cout << "Enter operation: ";
        cin >> operation;

        // If operation is sqrt, sin, cos, or tan, only one number is needed
        if (operation == "sqrt" || operation == "sin" || operation == "cos" || operation == "tan") {
            try {
                double result = calculate(number1, 0, operation); // num2 is not used
                string resultEntry = to_string(number1) + " " + operation + " = " + to_string(result);
                history.push_back(resultEntry);
                cout << "Result: " << result << endl;
            }
            catch (const exception& e) {
                cout << e.what() << endl;
            }
        }
        else {
            // Get second number
            getInput(number2, "Enter second number: ");

            // Perform calculation
            try {
                double result = calculate(number1, number2, operation);
                string resultEntry = to_string(number1) + " " + operation + " " + to_string(number2) + " = " + to_string(result);
                history.push_back(resultEntry);
                cout << "Result: " << result << endl;
            }
            catch (const exception& e) {
                cout << e.what() << endl;
            }
        }

        // Show history
        showHistory();

        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> continueCalculation;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear newline character

    } while (continueCalculation == 'y' || continueCalculation == 'Y');

    cout << "Thanks for using the calculator! Goodbye!" << endl; // Fixed syntax error here
    return 0;
}