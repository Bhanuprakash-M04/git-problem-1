package solutions;

public class Solution {
    public static int[] smallerNumbersThanCurrent(int[] nums) {
        int len = nums.length;
        int[] hashNums = new int[101];
        int maxValue = 0;

        for (int num : nums) {
            hashNums[num]++;
            maxValue = Math.max(maxValue, num);
        }

        for (int i = 1; i <= maxValue; i++) {
            hashNums[i] += hashNums[i - 1];
        }

        for (int i = 0; i < len; i++) {
            int indexToLook = nums[i] - 1;
            if (indexToLook == -1) {
                nums[i] = 0;
            } else {
                nums[i] = hashNums[indexToLook];
            }
        }

        return nums;
    }
}
