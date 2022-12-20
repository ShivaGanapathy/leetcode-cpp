class Solution {
public:
    // O(n) time, O(n) memory
    int trap(vector<int>& height) {
        vector<int> maxLeft(height.size());
        maxLeft[0] = 0;
        vector<int> maxRight(height.size());
        maxRight[height.size()-1] = 0;
        
        for (int i=1; i < height.size(); i++) {
            maxLeft[i] = max(height[i-1], maxLeft[i-1]);
        }

        for (int i=height.size()-2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i+1], height[i+1]);
        }


        int res = 0;

        for (int i=0; i < height.size(); i++) {
            int blocks = min(maxLeft[i], maxRight[i]) - height[i];
            
            if (blocks >= 0) {
                res += blocks;
            }
        }

        return res;
    }
};
