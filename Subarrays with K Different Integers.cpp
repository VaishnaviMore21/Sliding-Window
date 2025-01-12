class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }
    
    int atMostKDistinct(vector<int>& nums, int k) {
        int left = 0, right = 0, cnt = 0;
        unordered_map<int, int> freq;
        
        while (right < nums.size()) {
            // Expand the window by including nums[right]
            freq[nums[right]]++;
            
            // If distinct elements exceed k, shrink the window
            while (freq.size() > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }
            
            // Add the number of valid subarrays ending at `right`
            cnt += (right - left + 1);
            right++;
        }
        
        return cnt;
    }
};
