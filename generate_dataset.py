#!/usr/bin/env python3

import sys, random


def main():
    while True:
        try:
            data_count = int(input("Amount of integers to generate > "))

        except (KeyboardInterrupt, EOFError):
            print("\nClosing...")
            sys.exit(0)

        except (TypeError):
            continue

        break

    print(f"Generating new dataset of {data_count} integers to file data.csv...")

    data = []

    for i in range(data_count):
        data.append(str(i + 1))

    random.shuffle(data)

    with open("data.csv", "w") as f:
        f.write(','.join(data))

    print(f"Done!")


if __name__ == "__main__":
    main()