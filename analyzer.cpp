/*
COP3504C - Lab 04

Author: Tomas Mejia
Description: Implementation of linear and binary searches, in C++ this time
*/

#include <iostream>
#include <vector>
#include <chrono>
#include "StringData.h"

using namespace std;
using namespace std::chrono;


int linear_search(vector<string> container, string element) {
  for (int i = 0; i < container.size(); i++) {
    if (container[i] == element) {
      return i;
    }
  }
  return -1;
}

int binary_search(vector<string> container, string element) {
  int low = 0;
  int high = container.size();
  while (low != high) {
    int mid = (low + high);
    if (element > container[mid]) {
      low = mid + 1;
    } else if (element < container[mid]) {
      high = mid;
    } else {
      return mid;
    }
  }
  return -1;
}

int main() {
  vector<string> string_data = getStringData();

  std::cout << "Searching for \"not_here\"";
  long long startTime = systemTimeNanoseconds();
  linear_search(string_data, "not_here");
  long long stopTime = systemTimeNanoseconds();
  std::cout << "Linear took " << (stopTime-startTime) << " nanoseconds";
  startTime = systemTimeNanoseconds();
  binary_search(string_data, "not_here");
  stopTime = systemTimeNanoseconds();
  std::cout << "Binary took " << (stopTime - startTime) << " seconds";

  std::cout << "Searching for \"mzzzz\"";
  startTime = systemTimeNanoseconds();
  linear_search(string_data, "mzzzz");
  stopTime = systemTimeNanoseconds();
  std::cout << "Linear took " << (stopTime-startTime) << " nanoseconds";
  startTime = systemTimeNanoseconds();
  binary_search(string_data, "mzzzz");
  stopTime = systemTimeNanoseconds();
  std::cout << "Binary took " << (stopTime - startTime) << " seconds";

  std::cout << "Searching for \"aaaaa\"";
  startTime = systemTimeNanoseconds();
  linear_search(string_data, "aaaaa");
  stopTime = systemTimeNanoseconds();
  std::cout << "Linear took " << (stopTime-startTime) << " nanoseconds";
  startTime = systemTimeNanoseconds();
  binary_search(string_data, "aaaaa");
  stopTime = systemTimeNanoseconds();
  std::cout << "Binary took " << (stopTime - startTime) << " seconds";
}