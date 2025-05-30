
package solutions; 

class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int len = nums.length;
        int[] hashNums = new int[101];

        int maxValue = 0;

        for(int num: nums){//hashing the nums elements in HashNums
            hashNums[num]++;
            maxValue = Math.max(maxValue, num);
        }

        //making the hash array into a prefix Sum array
        for(int i=1; i<=maxValue; i++){
            hashNums[i] += hashNums[i-1];
        }

        //making the result array
        for(int i=0;i<len;i++){
            int indexToLook = nums[i]-1;
            if(indexToLook == -1){
                nums[i] = 0;
                continue;
            }
            nums[i] = hashNums[indexToLook];
        }

        return nums;
    }
}