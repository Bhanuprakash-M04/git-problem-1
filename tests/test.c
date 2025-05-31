#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../solutions/solution.c"

// Compare two arrays
bool compareArrays(int *arr1, int size1, int *arr2, int size2)
{
    if (size1 != size2)
        return false;
    for (int i = 0; i < size1; i++)
    {
        if (arr1[i] != arr2[i])
            return false;
    }
    return true;
}

// Print an array
void printArray(int *arr, int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");
}

// Test runner returns number of failed test cases
int runTestCases()
{
    int passed = 0, failed = 0;

    // Test cases
    int input1[] = {8, 1, 2, 2, 3};
    int expected1[] = {4, 0, 1, 1, 3};

    int input2[] = {6, 5, 4, 8};
    int expected2[] = {2, 1, 0, 3};

    int input3[] = {7, 7, 7, 7};
    int expected3[] = {0, 0, 0, 0};

    int input4[] = {1};
    int expected4[] = {0};

    int input5[] = {0, 0, 0};
    int expected5[] = {0, 0, 0};

    int input6[] = {10, 5, 10, 5};
    int expected6[] = {2, 0, 2, 0};

    int input7[] = {100, 50, 0};
    int expected7[] = {2, 1, 0};

    int input8[] = {2, 0, 1, 0, 2};
    int expected8[] = {3, 0, 2, 0, 3};

    int *inputs[] = {input1, input2, input3, input4, input5, input6, input7, input8};
    int *expecteds[] = {expected1, expected2, expected3, expected4, expected5, expected6, expected7, expected8};
    int sizes[] = {5, 4, 4, 1, 3, 4, 3, 5};
    int numTests = sizeof(sizes) / sizeof(sizes[0]);

    for (int t = 0; t < numTests; t++)
    {
        int returnSize = 0;
        int *result = smallerNumbersThanCurrent(inputs[t], sizes[t], &returnSize);

        printf("Test Case %d:\n", t + 1);
        printf("Expected: ");
        printArray(expecteds[t], sizes[t]);
        printf("Got:      ");
        if (result == NULL)
        {
            printf("NULL (no result returned)\n");
            failed++;
        }
        else
        {
            printArray(result, returnSize);
            if (compareArrays(result, returnSize, expecteds[t], sizes[t]))
            {
                printf("✅ Passed\n\n");
                passed++;
            }
            else
            {
                printf("❌ Failed\n\n");
                failed++;
            }
        }

        free(result);
    }

    printf("Test Cases Passed: %d\n", passed);
    printf("Test Cases Failed: %d\n", failed);
    printf("Total Test Cases: %d\n", passed + failed);

    return failed; // Return number of failed test cases
}

int main()
{
    int failed = runTestCases();
    return (failed > 0) ? 1 : 0; // Exit with code 1 if any test failed
}
