class Solution {
public:
    // Solution 1: Brute force
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
        
    }
    
    
   // Solution 2: Hashmap
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // We want to make a vector to store the result of the function
        vector<int> res;
        
        // We want to create a hashmap to store complements
        unordered_map<int, int> hashmap;
        
        for (int i = 0; i < nums.size(); i++) {
            
            int complement = target - nums[i];
            
            // If we haven't seen the complement yet, add the current number
            if (hashmap.find(complement) == hashmap.end()) {
                hashmap[nums[i]] = i;
            }
            // If we have seen the complement before, we are ready to return
            else {
                res.push_back(hashmap[complement]);
                res.push_back(i);
                return res;
            }
        }
        
        return res;
};
