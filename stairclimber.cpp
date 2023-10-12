/*******************************************************************************
 * Name        : stairclimber.cpp
 * Author      : Aaren Patel
 * Date        : 10/6/2023
 * Description : Lists the number of ways to climb n stairs.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System
 ******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

vector< vector<int> > get_ways(int num_stairs) {
    /* Returns a vector of int vectors with all the possible ways to climb a staircase with num_stairs stairs with step sizes of 1, 2, or 3 stairs. */
    
    //Base Case
    vector<vector<int>> ways = {};
    if (num_stairs <= 0) {
        return {{}};
    }
    //Recursive loops for all step sizes
    for (int i = 1; i < 4; i++)
        if (num_stairs >= i) {
            vector<vector<int>> prevWays = get_ways(num_stairs-i);
            for (vector<int> j : prevWays) {
                j.insert(j.begin(), i);
                ways.push_back(j);
            }
        }
    return ways;
}

void addSpace (int count, int len) {
    /* Helper function to add spaces in formatting. */
    while (count != 0) {
        count = count/10;
        len = len/10;
    }
    while (len != 0) {
        cout << " ";
        len = len/10;
    }
}


void display_ways(const vector< vector<int> > &ways) {
    /* Displays the vector of int vectors to the console in a readable manner */
    unsigned int count = 1, val = 0;
    int len = ways.size();
    for (vector<int> i : ways) {
        addSpace(count, len);
        cout << count << ". [";
        for (int j : i) {
            if (val == i.size()-1)
                cout << j;
            else
                cout << j << ", ";
            val+= 1;
        }
        val = 0;
        cout << "]" << endl;
        count++;
    }
}

int main(int argc, char * const argv[]) {
    //Invalid number of arguments
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <number of stairs>" << endl;
        return 1;
    }

    int numStairs;
    istringstream iss(argv[1]);
    //Invalid input for second argument
    if (!(iss >> numStairs) || numStairs < 1) {
        cerr << "Error: Number of stairs must be a positive integer." << endl;
        return 1;
    }
    
    //Creates the vector with the ways to climb the stair of numStairs stairs
    vector<vector<int>> ways = get_ways(numStairs);

    //Output to console
    if (numStairs == 1)
        cout << ways.size() << " way to climb " << numStairs << " stair." << endl;
    else
        cout << ways.size() << " ways to climb " << numStairs << " stairs." << endl;
    display_ways(ways);

    return 0;
}
