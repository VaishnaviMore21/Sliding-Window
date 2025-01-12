

class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int maxlen = -1;  // Initialize maxlen as -1 to handle cases with fewer than k distinct characters
        int left = 0;
        int right = 0;
        map<char, int> mpp;

        while (right < s.size()) {
            mpp[s[right]]++;  // Add character to the map
            
            // Shrink the window if we have more than 'k' distinct characters
            while (mpp.size() > k) {
                mpp[s[left]]--;
                if (mpp[s[left]] == 0) {
                    mpp.erase(s[left]);
                }
                left++;
            }
            
            // If the number of distinct characters is exactly 'k', update maxlen
            if (mpp.size() == k) {
                maxlen = max(maxlen, right - left + 1);
            }

            right++;  // Move the right pointer to the next character
        }

        return maxlen;  // Return -1 if no valid substring is found
    }
};


