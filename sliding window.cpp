
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        // code here
         int left = 0, right = 0, maxlen = 0;
        int k = 2; // Maximum number of distinct fruits
        unordered_map<int, int> m;

        while (right < arr.size()) {
            m[arr[right]]++;

            // If the number of distinct fruits exceeds k, shrink the window
            while (m.size() > k) {
                m[arr[left]]--;
                if (m[arr[left]] == 0) {
                    m.erase(arr[left]);
                }
                left++;
            }

            // Update the maximum length of the subarray
            maxlen = max(maxlen, right - left + 1);
            right++;
        }

        return maxlen;
    
    }
};
