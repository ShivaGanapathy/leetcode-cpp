class Solution {
public:
    // O(n) time O(k) space Monotonic decreasing queue solution
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;

        for (int rp = 0; rp < nums.size(); rp++) {

            while(q.size() > 0 && nums[rp] > nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(rp);

            if (rp >= k-1) {res.push_back(nums[q.front()]);}

            if (q.front() == rp-(k-1)) {
                q.pop_front();
            }

        }

        return res;
    }
};
