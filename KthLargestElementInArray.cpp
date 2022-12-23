class Solution {
public:
    // Solution 1: Heap
    int findKthLargest(vector<int>& nums, int k) {
        /*
        Algorithm Steps:
        - Iterate through every int in input
        - Add to a heap
        - If the heap exceeds size k, evict the smallest element (min heap)
        - return top of heap
        O(nlogk) time complexity
        O(k) space complexity
        */
        priority_queue<int> heap;
        for (auto x : nums) {
            heap.push(-x);
            if (heap.size()>k) {heap.pop();}
        }

        return -heap.top();
         
    }
};
