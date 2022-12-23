class comparator {
public:
    bool operator()(const pair<int, string>& p1, const pair<int, string>& p2 ) {
        if (p1.first == p2.first) {return p1.second < p2.second;}
        return p1.first > p2.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        /*
        Algorithm Steps:
        - Iterate through every words, and count # of occurences in Hashmap
        - Iterate through every word-count pair in the hashmap
            - Append the item to a heap
            - If the heap exceeds size k, eject element
            - Since we are maintaining a heap of size k, the smallest elements must be continously ejected
        - Itereate through contents of heap, and append items to result array
        - Since the order of elements being popped are smallest to largest, we require the reverse
        - This solution has a time complexity of O(n + nlog(k) + klog(k)) = O(nlogk)
        */

        unordered_map<string, int> counter;

        for(string& word: words) {counter[word]+=1;}

        priority_queue<pair<int, string>, vector<pair<int,string>>, comparator> heap;

        for(auto[key,value] : counter) {
            std::pair item = {value, key};
            heap.push(item); 
            if (heap.size()>k) {
                heap.pop();
            }
        }

        vector<string> res;

        while(heap.size()>0) {
            res.push_back(heap.top().second);
            heap.pop();
        }

        reverse(res.begin(), res.end());

        return res;


    }
};
