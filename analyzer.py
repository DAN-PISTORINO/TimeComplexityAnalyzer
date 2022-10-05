# Lab 4 - Time Complexity & Profiling
# Authors: Daniel Pistorino and Sean Hanlon
import stringdata
import time as t


def main():
    the_data = stringdata.get_data()

    start_time = t.time()
    nothere_linear_loc = linear_search(the_data, "not_here")
    end_time = t.time()
    nothere_linear_time = end_time - start_time

    start_time = t.time()
    nothere_binary_loc = binary_search(the_data, "not_here")
    end_time = t.time()
    nothere_binary_time = end_time - start_time
    print("Search term: 'not_here'")
    print("Found at location:", nothere_binary_loc)
    print("\tLinear search time: ", nothere_linear_time)
    print("\tBinary search time: ", nothere_binary_time)
    print("\t\tStart time:", start_time)
    print("\t\tEnd time:", end_time)
    
    start_time = t.time()
    mzzzz_linear_loc = linear_search(the_data, "mzzzz")
    end_time = t.time()
    mzzzz_linear_time = end_time - start_time
    start_time = t.time()
    mzzzz_binary_loc = binary_search(the_data, "mzzzz")
    end_time = t.time()
    mzzzz_binary_time = end_time - start_time
    print("Search term: 'mzzzz'")
    print("Found at location:", mzzzz_binary_loc)
    print("\tLinear search time: ", mzzzz_linear_time)
    print("\tBinary search time: ", mzzzz_binary_time)

    start_time = t.time()
    aaaaa_linear_loc = linear_search(the_data, "aaaaa")
    end_time = t.time()
    aaaaa_linear_time = end_time - start_time
    start_time = t.time()
    aaaaa_binary_loc = binary_search(the_data, "aaaaa")
    end_time = t.time()
    aaaaa_binary_time = end_time - start_time
    print("Search term: 'aaaaa'")
    print("Found at location:", aaaaa_binary_loc)
    print("\tLinear search time: ", aaaaa_linear_time)
    print("\tBinary search time: ", aaaaa_binary_time)
    return 1

def linear_search(container: tuple[str], element: str) -> int:
    cont_len = len(container)
    for data_index in range(cont_len):
        if container[data_index] == element:
            return data_index
    return -1

def binary_search(container: tuple[str], element: str) -> int:
    maxIndex = len(container)-1
    minIndex = 0
    midIndex = 0
    while minIndex <= maxIndex:
        midIndex = int(minIndex + (maxIndex-minIndex)/2)
        if container[midIndex] < element:
            minIndex = midIndex +1
        elif container[midIndex] > element:
            maxIndex = midIndex -1
        elif container[midIndex] == element:
            return midIndex
        else:
            return -1



        

if __name__ == "__main__":
    main()