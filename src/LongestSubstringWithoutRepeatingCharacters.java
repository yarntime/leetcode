public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] appearPos = new int[256];
        int maxLength = 0;
        int currentLength = 0;
        int currentRepeatPos = 0;
        for (int i = 0; i < 256; ++i) {
            appearPos[i] = -1;
        }
        for (int i = 0; i < s.length(); ++i) {
            if (appearPos[s.charAt(i)] == -1) {
                currentLength++;
            } else {
                currentLength = i - Math.max(appearPos[s.charAt(i)], currentRepeatPos);
                currentRepeatPos = Math.max(appearPos[s.charAt(i)], currentRepeatPos);
            }
            appearPos[s.charAt(i)] = i;
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
        }
        return maxLength;
    }
}