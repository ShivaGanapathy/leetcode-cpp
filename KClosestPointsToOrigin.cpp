class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        /*
        Algorithm Steps:
        - Iterate through every point in given list of points
            - Add point distance as well as point to max heap
            - If heap size exceeds k, pop from heap and evict largest distance point
        - Pop remaining elements from heap as add to resulting vector
        Time Complexity of O(n + nlogk + klogk) = O(nlogk)
        Space Complexity of O(k) used for heap;
        
        */

        priority_queue<pair<int,vector<int>>> heap;

        for (auto point: points) {
            int x = point[0];
            int y = point[1];
            int distance = pow(x,2) + pow(y,2);
            pair item = {distance, point};
            heap.push(item);
            if (heap.size()>k) {heap.pop();}
        }

        vector<vector<int>> res;
        while (heap.size()>0) {
            auto [x, y] = heap.top();
            res.push_back(y);
            heap.pop();
        }

        return res;

    }
};
