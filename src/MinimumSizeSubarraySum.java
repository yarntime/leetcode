public class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int result = 0;
        int curLength = 0;
        int sum = 0;
        int start = 0, end = 0;
        while (true) {
            if (end == nums.length && sum < s) {
                break;
            }
            if (sum < s) {
                sum += nums[end++];
            } else {
                curLength = end - start;
                if (result == 0 || curLength < result) {
                    result = curLength;
                }
                sum -= nums[start++];
            }
        }
        return result;
    
    }
}