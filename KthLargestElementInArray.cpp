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
    // Solution 2: Quickselect
    int findKthLargest(vector<int>& nums, int k) {
        /*
        Algorithm Steps:
        - Select a pivot (maybe the midpoint)
        - Create a new vector to store all element to the left of the pivot
        - Create a new vector to store all elements to the right of the pivot
        - If k falls within the left side, call quick sort of (left, k)'
        - If k falls within the left size call quick sort of (right, k-left.size()-1)
        - if the given array is of size 1, return the element

        - The average case time complexity is O(n) assuming we make average performing pivot choices
        - If our pivot sucks, our algo becomes O(n^2)

        */


        for (auto x: nums) {cout << x << "";}
        cout << ", " << k << "\n";


        if (nums.size() == 1) {return nums[0];}
        int pivot_idx = nums.size()/2;
        int pivot_val = nums[pivot_idx];

        cout << "pivot val is :  " << pivot_val << "\n";

        vector<int> left;
        vector<int> right;
        
        
        for (int i = 0; i<pivot_idx; i++) {
            if (nums[i] < pivot_val) {left.push_back(nums[i]);}
            else {right.push_back(nums[i]);}
        };

        for (int i = pivot_idx+1; i<nums.size(); i++) {
            if (nums[i] < pivot_val) {left.push_back(nums[i]);}
            else {right.push_back(nums[i]);}
        };

        if (k <= right.size()) {return findKthLargest(right, k);}
        if (k > right.size() + 1) {return findKthLargest(left, k-1-right.size());}
        else {return pivot_val;}



    }
};
