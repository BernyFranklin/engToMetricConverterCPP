/*
 * englishToMetricConversionCPP Version1.0
 * Frank Bernal
 * CIS 054 C/C++ Programming
 * Input: Menu Selection, Inches, Centimeters
 * Output: Conversion Inches <=> Centimeters
 * 18 Mar 2022
 */

// Input Output stream
#include <iostream>
// toUpper function
#include <cctype>
// 2 places past decimal
#include <iomanip>
// Function prototypes
char menuSelect();
void englishConvert();
void metricConvert();
bool isNumber(double input);
// std namespace
using namespace std;

// Global Constant conversion rate English to Metric
const double CONVERSION_RATE = 2.54;

// Start Main
int main(int argc, const char * argv[]) {
    // Local variables
    char select;
    
    // Welcome message
    cout << "===========================================" << endl;
    cout << "Welcome to the English to Metric Converter!" << endl;
    cout << "===========================================" << endl;
    
    // Loop program until user quits
    do {
        // Call menuSelect
        select = menuSelect();
        // If E selected, convert from English to Metric
        if (select == 'E') {
            // Let user know they're converting english
            cout << endl;
            cout << "============================" << endl;
            cout << "Converting English to Metric" << endl;
            cout << "============================" << endl;
            // Call subroutine
            englishConvert();
        }   // End of E selected
        // If M selected, convert from Metric to English
        else if (select == 'M') {
            // Let user know they're converting metric
            cout << endl;
            cout << "============================" << endl;
            cout << "Converting Metric to English" << endl;
            cout << "============================" << endl;
            // Call subroutine
            metricConvert();
        }   // End of M selected
        else;  // Q is selected if we make it this far
    } while (select != 'Q');
    
    // Closing message
    cout << endl;
    cout << "====================================================" << endl;
    cout << "Thank you for using the English to Metric Converter!" << endl;
    cout << "====================================================" << endl;
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
        // Error prompt
        if (selection != 'E' && selection != 'M' && selection != 'Q') {
            cout << "Please enter a valid selection." << endl;
        }
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
            // Sets decimal two places
            cout << setiosflags(ios::fixed | ios::showpoint);
            cout << setprecision(1);
            cout << inches << " inches is equal to " << centimeters << " centimeters." << endl;
        }   // End of else
    } while (!isValid);   // Repeat until valid input
}  // End of englishConvert

// Start of metricConvert
void metricConvert() {
    // Local Variables
    double inches;
    double centimeters;
    bool isValid;
    // Do..while loop to loop for valid input
    do {
        // Assume good input
        isValid = true;
        // Prompt for input
        cout << "Enter the number of centimeters: ";
        // Read input
        cin >> centimeters;
        // Check if input is numeric
        isValid = isNumber(centimeters);
        // If not numeric
        if (!isValid)
            continue;
        // If input valid
        else {
            // Compute Inches to centimeters
            inches = centimeters / CONVERSION_RATE;
            // Print results
            // Sets decimal two places
            cout << setiosflags(ios::fixed | ios::showpoint);
            cout << setprecision(1);
            cout << centimeters << " centimeters is equal to " << inches << " inches." << endl;
        }   // End of else
    } while (!isValid);   // Repeat until valid input
}   // End of metricConvert

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
