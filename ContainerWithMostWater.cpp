class Solution {
public:
    // Two pointer solution
    // O(n) time O(1) space
    int maxArea(vector<int>& height) {
        int lp = 0;
        int rp = height.size()-1;
        int res = 0;

        while (lp < rp) {
            res = max(res, (rp-lp) * min(height[lp], height[rp]));
            if (height[lp] < height[rp]) {
                lp++;
            }
            else {
                rp--;
            }
        }

        return res;
    }
};
