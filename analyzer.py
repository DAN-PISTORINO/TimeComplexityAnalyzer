"""
COP3504C - Lab 04

Author: Tomas Mejia
Description: Implementation of linear and binary searches.
"""

import time


def get_data() -> tuple:
    string_data_set = ["."] * (26**5)
    temp_set = [".", ".", ".", ".", "."]
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    index = 0
    for i in range(len(alphabet)):
        temp_set[4] = alphabet[i]
        for j in range(len(alphabet)):
            temp_set[3] = alphabet[j]
            for k in range(len(alphabet)):
                temp_set[2] = alphabet[k]
                for l in range(len(alphabet)):
                    temp_set[1] = alphabet[l]
                    for m in range(len(alphabet)):
                        temp_set[0] = alphabet[m]
                        string_data_set[index] = (temp_set[0] + temp_set[1] +
                                                  temp_set[2] + temp_set[3] +
                                                  temp_set[4])
                        index += 1
    string_data_set.sort()
    string_data_tuple = tuple(string_data_set)
    return string_data_tuple


def linear_search(container, element):
    for i in range(len(container)):
        if container[i] == element:
            return i
    return -1


def binary_search(container, element):
    low = 0
    high = len(container)
    while low != high:
        mid = (low + high) // 2
        if element > container[mid]:
            low = mid+1
        elif element < container[mid]:
            high = mid
        else:
            return mid
    return -1


def main():
    string_data = get_data()

    print("Searching for \"not_here\"")
    startTime = time.time()
    linear_search(string_data, "not_here")
    print("Linear took " + str(time.time() - startTime) + " seconds")
    startTime = time.time()
    binary_search(string_data, "not_here")
    print("Binary took " + str(time.time() - startTime) + " seconds")

    print("\nSearching for \"mzzzz\"")
    startTime = time.time()
    linear_search(string_data, "mzzzz")
    print("Linear took " + str(time.time() - startTime) + " seconds")
    startTime = time.time()
    binary_search(string_data, "mzzzz")
    print("Binary took " + str(time.time() - startTime) + " seconds")

    print("\nSearching for \"aaaaa\"")
    startTime = time.time()
    linear_search(string_data, "aaaaa")
    print("Linear took " + str(time.time() - startTime) + " seconds")
    startTime = time.time()
    binary_search(string_data, "aaaaa")
    print("Binary took " + str(time.time() - startTime) + " seconds")


if __name__ == '__main__':
    main()
