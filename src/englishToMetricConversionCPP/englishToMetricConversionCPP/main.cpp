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
// std namespace
using namespace std;

// Start Main
int main(int argc, const char * argv[]) {
    // Local variables
    double inches;
    double centimeters;
    char select;
    
    
    
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
