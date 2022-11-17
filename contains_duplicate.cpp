class Solution {
public:
    // Solution 1: O(n^2) O(1) space
    bool containsDuplicate(vector<int>& nums) {
        
        for (int i = 0; i < nums.size(); i++ ) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        
        return false;
        
    }
    
    
    // Solution 2: O(1) time, O(n) space
    bool containsDuplicate(vector<int>& nums) {
        
        // Create a hashset to store every number we encounter
        unordered_set<int> hashset;
        
        for (int &num : nums) {
            // If the number is already in the hashset, we found a duplicate
            if (hashset.find(num) != hashset.end()) {
                return true;
            }
            // Else lets add the current number to the set and move on
            hashset.insert(num);
            
        }
        
        return false;
        
    }
};
