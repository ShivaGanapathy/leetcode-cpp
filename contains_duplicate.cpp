class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        // Brute force O(n^2) O(1) space
        for (int i = 0; i < nums.size(); i++ ) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        
        return false;
        
    }
};
