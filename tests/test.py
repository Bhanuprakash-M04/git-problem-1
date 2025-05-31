import sys
import os
sys.path.insert(0, os.path.abspath('.'))

from solutions.solution import Solution

def compare_arrays(a, b):
    return a == b

def print_array(arr):
    print("[" + ", ".join(map(str, arr)) + "]")

def run_test_cases():
    inputs = [
        [8, 1, 2, 2, 3],
        [6, 5, 4, 8],
        [7, 7, 7, 7],
        [1],
        [0, 0, 0],
        [10, 5, 10, 5],
        [100, 50, 0],
        [2, 0, 1, 0, 2]
    ]

    expecteds = [
        [4, 0, 1, 1, 3],
        [2, 1, 0, 3],
        [0, 0, 0, 0],
        [0],
        [0, 0, 0],
        [2, 0, 2, 0],
        [2, 1, 0],
        [3, 0, 2, 0, 3]
    ]

    passed = 0
    failed = 0

    solution = Solution()

    for i, (inp, expected) in enumerate(zip(inputs, expecteds)):
        result = solution.smallerNumbersThanCurrent(inp)
        print(f"Test Case {i + 1}:")
        print("Expected: ", end="")
        print_array(expected)
        print("Got:      ", end="")
        print_array(result)

        if compare_arrays(result, expected):
            print("✅ Passed\n")
            passed += 1
        else:
            print("❌ Failed\n")
            failed += 1

    print(f"Test Cases Passed: {passed}")
    print(f"Test Cases Failed: {failed}")
    print(f"Total Test Cases: {passed + failed}")

    if failed > 0:
        exit(1)

if __name__ == "__main__":
    run_test_cases()
