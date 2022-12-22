/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (lists.size() == 0) {return nullptr;}

        vector<ListNode*> result = lists;

        while (result.size()>1) {

            vector<ListNode*> newList;

            int length = result.size();

            

            for (int i = 1; i < length; i+=2) {
                ListNode* l1 = result[i-1];
                ListNode* l2 = result[i];
                cout << "3";
                newList.push_back(mergeTwoLists(l1, l2));
            }

            
            if (length % 2 == 1) {newList.push_back(result.back());}

            result = newList;


        }

        cout << result[0];

        return result[0];

        
        
    }


    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head;
        ListNode* curr = &head;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next; 
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        if (l1 != nullptr) {curr->next = l1;}
        if (l2 != nullptr) {curr->next = l2;}
        

        return head.next;
    }
};
