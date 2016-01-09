public class Solution {
    public int maxProduct(String[] words) {
        int result = 0;
        int[] map = new int[words.length];
        for (int i = 0; i < words.length; ++i) {
            map[i] = getIntValue(words[i]);
        }
        for (int i = 0; i < words.length; ++i) {
            for (int j = i + 1; j < words.length; ++j) {
                if ((map[i] & map[j]) == 0) {
                    int cur = words[i].length() * words[j].length();
                    if (cur > result) {
                        result = cur;
                    }
                }
            }
        }
        return result;
    }
    
    private int getIntValue(String s) {
        int result = 0;
        for (int i = 0; i < s.length(); ++i) {
            int v = s.charAt(i) - 'a';
            result |= 1 << v;
        }
        return result;
    }
}