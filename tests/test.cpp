#include <bits/stdc++.h>
#include "../solutions/solution.cpp" // 👈 Include the Solution class
using namespace std;

bool compareArrays(const vector<int> &a, const vector<int> &b)
{
    return a == b;
}

void printArray(const vector<int> &arr)
{
    cout << "[";
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i < arr.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

int runTestCases()
{
    vector<vector<int>> inputs = {
        {8, 1, 2, 2, 3},
        {6, 5, 4, 8},
        {7, 7, 7, 7},
        {1},
        {0, 0, 0},
        {10, 5, 10, 5},
        {100, 50, 0},
        {2, 0, 1, 0, 2}};

    vector<vector<int>> expecteds = {
        {4, 0, 1, 1, 3},
        {2, 1, 0, 3},
        {0, 0, 0, 0},
        {0},
        {0, 0, 0},
        {2, 0, 2, 0},
        {2, 1, 0},
        {3, 0, 2, 0, 3}};

    int passed = 0, failed = 0;
    Solution sol;

    for (size_t i = 0; i < inputs.size(); ++i)
    {
        vector<int> result = sol.smallerNumbersThanCurrent(inputs[i]);

        cout << "Test Case " << i + 1 << ":" << endl;
        cout << "Expected: ";
        printArray(expecteds[i]);
        cout << "Got:      ";
        printArray(result);

        if (compareArrays(result, expecteds[i]))
        {
            cout << "✅ Passed\n\n";
            passed++;
        }
        else
        {
            cout << "❌ Failed\n\n";
            failed++;
        }
    }

    cout << "Test Cases Passed: " << passed << endl;
    cout << "Test Cases Failed: " << failed << endl;
    cout << "Total Test Cases: " << passed + failed << endl;

    return (failed > 0) ? 1 : 0;
}

int main()
{
    return runTestCases();
}
