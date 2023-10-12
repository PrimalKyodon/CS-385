/*******************************************************************************
 * Name        : sieve.cpp
 * Author      : Aaren Patel
 * Date        : September 19, 2023
 * Description : Sieve of Eratosthenes
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System
 ******************************************************************************/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

class PrimesSieve {
public:
    PrimesSieve(int limit);

    ~PrimesSieve() {
        delete [] is_prime_;
    }

    void display_primes() const;

private:
    // Instance variables
    bool * const is_prime_;
    const int limit_;
    int num_primes_, max_prime_;

    // Method declarations
    void sieve();
    static int num_digits(int num);
};

PrimesSieve::PrimesSieve(int limit) :
        is_prime_{new bool[limit + 1]}, limit_{limit} {
    sieve();
}

void PrimesSieve::display_primes() const {
    const int maxDigits = num_digits(max_prime_);
    int count = 0;

    //Header Output
    cout << endl << "Number of primes found: " << num_primes_ << endl << "Primes up to " << limit_ << ":" << endl;
    //Case for multiple lines of output
    if (limit_ >= 107) { 
        cout << setw(maxDigits);
        for (int i = 2; i <= limit_; i++) {
            if (count + maxDigits + 1>= 80) {
                count = 0;
                cout << endl;
            }
        
            if (is_prime_[i] == 0) {
                if (count != 0) {
                    cout << setw(maxDigits + 1) << i;
                    count += 1;
                }
                else
                    cout << setw(maxDigits) <<  i; 
                count += maxDigits;
            }
        }
    }
    //Case for one line of output
    else {
        for (int i = 2; i <= limit_; i++) {
            if (i == max_prime_)
                cout << i << endl;
            else if (is_prime_[i] == 0)
                cout << i  << " ";
        }
    }
}

void PrimesSieve::sieve() {
    //Count tracker for non-primes excluding 1
    int count = 0;
    //Sets all values in the array is_prime_[] to 0
    for (int i = 0; i <= limit_; i++)
        is_prime_[i] = 0;
    //Filters out all non-primes while counting new ones
    for (int i = 2; i <= sqrt(limit_); i++) {
        if (is_prime_[i] == 0) {
            for (int j = i*i; j <= limit_; j+=i) {
                if (is_prime_[j] == 0) {
                    is_prime_[j] = 1;
                    count++;
                }
            }
        }
    }
    //Gets the max_prime_
    for (int i = 0; i <= limit_; i++)
        if (is_prime_[i] == 0) {
            max_prime_ = i;
        }
    //Sets num_primes_ to the total number of numbers denoted by limit - the counted non-primes and removes the edge case of 1 which is not prime or composite
    num_primes_ = limit_ - count - 1;
}

int PrimesSieve::num_digits(int num) {
    //Calcultes the number of digits in num though recursion
    if (num/10 == 0)
        return 1;
    return 1 + num_digits(num/10);
}

int main() {
    cout << "**************************** " <<  "Sieve of Eratosthenes" <<
            " ****************************" << endl;
    cout << "Search for primes up to: ";
    string limit_str;
    cin >> limit_str;
    int limit;

    // Use stringstream for conversion. Don't forget to #include <sstream>
    istringstream iss(limit_str);

    // Check for error.
    if ( !(iss >> limit) ) {
        cerr << "Error: Input is not an integer." << endl;
        return 1;
    }
    if (limit < 2) {
        cerr << "Error: Input must be an integer >= 2." << endl;
        return 1;
    }
    //Creates object sieve
    PrimesSieve* sieve = new PrimesSieve(limit);
    //Outputs the display
    sieve->display_primes();
    //Deletes the Sieve object before termination of program
    delete sieve;
    //Clears iss
    iss.clear();
    return 0;
}
