/*
 * englishToMetricConversionCPP Version1.0
 * Frank Bernal
 * CIS 054 C/C++ Programming
 * Input: Desired Unit, Input measurement
 * Output: Conversion Inches <=> Centimeters
 * 18 Mar 2022
 */

// Input Output stream
#include <iostream>
// toUpper function
#include <cctype>
// Function prototype
char menuSelect();
void englishConvert();
bool isNumber(double input);
// std namespace
using namespace std;

// Global Constant conversion rate English to Metric
const double CONVERSION_RATE = 2.54;

// Start Main
int main(int argc, const char * argv[]) {
    // Local variables
    char select;
    
    // Loop program until user quits
    do {
        // Call menuSelect
        select = menuSelect();
        // If E selected, convert from English to Metric
        if (select == 'E') {
            // Prompt for input
            englishConvert();
        }   // End of E selected
    } while (select != 'Q');
    return 0;
}   // End Main

// Start menuSelect
char menuSelect() {
    // Local variable
    char selection;
    // Loop menu until a valid input selected E, M, or Q
    do {
        // Blank line
        cout << endl;
        // Prompt
        cout << "Enter [E] to convert English to Metric, [M] to convert Metric to English, or [Q] to quit: ";
        // Read input
        cin >> selection;
        // Convert to uppercase
        selection = toupper(selection);
        // Repeat loop until E, M, or Q selected
    } while (selection != 'E' && selection != 'M' && selection != 'Q');
    return selection;
}   // End of menuSelect

// Start englishConvert
void englishConvert() {
    // Local Variables
    double inches;
    double centimeters;
    bool isValid;
    // Do..while loop to loop for valid input
    do {
        // Assume good input
        isValid = true;
        // Prompt for input
        cout << "Enter the number of inches: ";
        // Read input
        cin >> inches;
        // Check if input is numeric
        isValid = isNumber(inches);
        // If not numeric
        if (!isValid)
            continue;
        // If input valid
        else {
            // Compute Inches to centimeters
            centimeters = inches * CONVERSION_RATE;
            // Print results
            cout << inches << " inches is equal to " << centimeters << " centimeters." << endl;
        }   // End of else
    } while (!isValid);   // Repeat until valid input
}  // End of englishConvert

// Start of isNumber
bool isNumber(double input) {
    // Data mismatch
    if (!cin) {
        cout << "Input must be numeric, please try again." << endl;
        cout << endl; cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }   // End of data mismatch
    else if (input < 0) {
        cout << "Input must be positive, please try again." << endl;
        cout << endl; cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }
    else;
    return true;
}   // End of isNumber
