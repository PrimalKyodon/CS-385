/*******************************************************************************
 * Name        : unique.cpp
 * Author      : Aaren Patel
 * Date        : 9/30/2023
 * Description : Determining uniqueness of chars with int as bit vector.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System
 ******************************************************************************/
#include <iostream>
#include <cctype>

using namespace std;

bool is_all_lowercase(const string &s) {
    /* Returns true if all characters in string are lowercase */
    for (char i : s)
        // For-each loop that returns false as soon as a char other than a lowercase letter is found.
        if ( i - 'a' > 25 || i - 'a' < 0)
            return false;
    return true;
}

bool all_unique_letters(const string &s) {
    /* Returns true if all letters in string are unique */
    int storeLetters = 0;

    for (char i : s) {
        // For-each loop that checks if each element is unique by comparing it to an integer that tracks the used integers with bit shifting. Returns false if a duplicate is found.
        int letter = i - 'a';
        if (((1 << letter) & storeLetters) == 0)
            storeLetters = storeLetters | (1 << letter);
        else
            return false;
    }
    return true;
}

int main(int argc, char * const argv[]) {
    /* Reads and parses command line arguments. Calls other functions to produce correct output. */
    if (argc != 2) {
        // Wrong number of inputs
        cout << "Usage: " << argv[0] << " <string>" << endl;
        return 1;
    }
    else if (!is_all_lowercase(argv[1])) {
        // Doesnt contain only lowercase letters
        cout << "Error: String must contain only lowercase letters." << endl;
        return 1;
    }
    else if (all_unique_letters(argv[1]))
        // Unique Letters
        cout << "All letters are unique." << endl;
    else
        // Duplicate Letters
        cout << "Duplicate letters found." << endl;
    
    return 0;
}
