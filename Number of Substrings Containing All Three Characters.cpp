class Solution {
public:
    int numberOfSubstrings(string s) {
         int lastseen[3] = {-1, -1, -1};  // To store the last seen indices of 'a', 'b', and 'c'
        int cnt = 0;  // To count the number of valid substrings
        int n = s.size();  // Length of the string

        for (int i = 0; i < n; i++) {
            lastseen[s[i] - 'a'] = i;  // Update the last seen index of the current character

            // Check if all characters 'a', 'b', and 'c' have been seen at least once
            if (lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1) {
                cnt += 1 + min({lastseen[0], lastseen[1], lastseen[2]});
            }
        }

        return cnt;  // Return the count of substrings containing all three characters
    }
};
