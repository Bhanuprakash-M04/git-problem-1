__package__="solutions"
class Solution:
    def smallerNumbersThanCurrent(self, nums: list[int]) -> list[int]:
        n = len(nums)
        ans = [0]*n
        for i,v in enumerate(nums):
            cnt = 0
            for j in range(n):
                if j !=i and nums[j] < nums[i]:
                    cnt += 1
            ans[i] = cnt
        return ans