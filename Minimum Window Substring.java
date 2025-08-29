import java.util.*;

class Solution {
    public static String smallestWindow(String s, String t) {
        int n = s.length(), m = t.length();
        if (n < m) return "";               // return empty string when impossible

        int[] hash = new int[256];          // local -> reinitialized for every call
        for (int i = 0; i < m; i++) hash[t.charAt(i)]++;

        int left = 0, right = 0, count = 0;
        int minLen = Integer.MAX_VALUE, start = -1;

        while (right < n) {
            if (hash[s.charAt(right)] > 0) count++;
            hash[s.charAt(right)]--;
            right++;

            while (count == m) {           // valid window
                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }
                hash[s.charAt(left)]++;
                if (hash[s.charAt(left)] > 0) count--;
                left++;
            }
        }

        return (start == -1) ? "" : s.substring(start, start + minLen);
    }

    // quick local test
    
}
