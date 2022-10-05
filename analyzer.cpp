/// Lab 5 - Software Engineering
///     Porting analyzer.py to cpp
/// Authors: Daniel Pistorino

#include "StringData.h"
#include <algorithm>
#include <iostream>

using namespace std;

int binary_search(vector<string> container, string element);
int linear_search(vector<string> container, string element);

int main()
{
    vector<string> the_data = getStringData();

    long long start_time = systemTimeNanoseconds();

    int notHere_linear_loc = linear_search(the_data, "not_here");
    long long end_time = systemTimeNanoseconds();
    long long notHere_linear_time = end_time - start_time;

    start_time = systemTimeNanoseconds();
    int notHere_binary_loc = binary_search(the_data, "not_here");
    end_time = systemTimeNanoseconds();
    long long notHere_binary_time;
    notHere_binary_time = end_time - start_time;
    cout << "Search term: 'not_here'" << endl;
    cout << "Found at location:" << notHere_binary_loc << endl;
    cout << "\tLinear search time: " << notHere_linear_time << endl;
    cout << "\tBinary search time: " << notHere_binary_time << endl;

    start_time = systemTimeNanoseconds();
    int mzzzz_linear_loc = linear_search(the_data, "mzzzz");
    end_time = systemTimeNanoseconds();
    long long mzzzz_linear_time = end_time - start_time;
    start_time = systemTimeNanoseconds();
    int mzzzz_binary_loc = binary_search(the_data, "mzzzz");
    end_time = systemTimeNanoseconds();
    long long mzzzz_binary_time = end_time - start_time;
    cout << "Search term: 'mzzzz'" << endl;
    cout << "Found at location:" << mzzzz_binary_loc << endl;
    cout << "\tLinear search time: " << mzzzz_linear_time << endl;
    cout << "\tBinary search time: " << mzzzz_binary_time << endl;

    start_time = systemTimeNanoseconds();
    int aaaaa_linear_loc = linear_search(the_data, "aaaaa");
    end_time = systemTimeNanoseconds();
    long long aaaaa_linear_time = end_time - start_time;
    start_time = systemTimeNanoseconds();
    int aaaaa_binary_loc = binary_search(the_data, "aaaaa");
    end_time = systemTimeNanoseconds();
    long long aaaaa_binary_time = end_time - start_time;
    cout << "Search term: 'aaaaa'" << endl;
    cout << "Found at location:" << aaaaa_binary_loc << endl;
    cout << "\tLinear search time: " << aaaaa_linear_time << endl;
    cout << "\tBinary search time: " << aaaaa_binary_time << endl;
    return 1;
};

int linear_search(vector<string> container, string element) {
    int cont_len = container.size();
    for (int data_index=0; data_index < cont_len; data_index++) {
        if (container[data_index] == element) {
            return data_index;
        }
    }
    return -1;
};

int binary_search(vector<string> container, string element) {
    int maxIndex = container.size() - 1;
    int minIndex = 0;
    int midIndex = 0;
    while (minIndex <= maxIndex) {
        midIndex = int(minIndex + (maxIndex - minIndex) / 2);
        if (container[midIndex] < element) {
            minIndex = midIndex + 1;
        }
        else if (container[midIndex] > element) {
            maxIndex = midIndex - 1;
        }
        else if (container[midIndex] == element) {
            return midIndex;
        }
        else {
            return -1;
        }
    }
};
