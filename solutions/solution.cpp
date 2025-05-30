#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j && nums[i] > nums[j])
                    cnt++;
            }
            ans.push_back(cnt);
        }
        // print the answer
        return ans;
    }
};