#!/usr/bin/env python3

import time, sys, os


def partition(array, low, high):
    pivot = array[high]
    i = low - 1

    for j in range(low, high):
        if array[j] <= pivot:
            i += 1

            (array[i], array[j]) = (array[j], array[i])

    (array[i + 1], array[high]) = (array[high], array[i + 1])
    return i + 1


def quick_sort(array, low, high):
    if low < high:
        pivot = partition(array, low, high)

        array = quick_sort(array, low, pivot - 1)
        array = quick_sort(array, pivot + 1, high)

    return array


def main():
    if not os.path.isfile("../data.csv"):
        print("You must run generate_dataset.py to generate a dataset.")
        sys.exit(0)

    unsorted_data = [int(number) for number in open("../data.csv", "r").read().split(",")]
    unsorted_data_size = len(unsorted_data)

    print(f"[RUNNING IN PYTHON] Sorting unsorted data of {unsorted_data_size} integers...")
    
    benchmark_start = time.time()
    quick_sort(unsorted_data, 0, unsorted_data_size - 1)
    benchmark_elapsed = time.time() - benchmark_start

    print(f"Sorted array in {benchmark_elapsed:.4f}s.")

if __name__ == "__main__":
    main()