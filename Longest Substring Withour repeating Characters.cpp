class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       vector<int> mpp(256, -1); // To store the last index of every character
        int left = 0, right = 0; // Sliding window pointers
        int n = s.size();        // Size of the string
        int maxlen = 0;          // To store the maximum length

        while (right < n) {
            // If character is already seen and lies within the current window
            if (mpp[s[right]] != -1 && mpp[s[right]] >= left) {
                left = mpp[s[right]] + 1; // Move the left pointer
            }

            mpp[s[right]] = right; // Update the last index of the character
            maxlen = max(maxlen, right - left + 1); // Update the maximum length
            right++; // Expand the window
        }

        return maxlen; 
    }
};
