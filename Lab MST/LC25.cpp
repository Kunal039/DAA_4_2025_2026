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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;

        vector<ListNode*> arr;
        ListNode* temp = head;


        while(temp){
            arr.push_back(temp);
            temp = temp->next;
        }


        int n = arr.size();


        for(int i = 0; i + k <= n; i += k){
            reverse(arr.begin() + i, arr.begin() + i + k);
        }

        for(int i = 0; i < n - 1; i++){
            arr[i]->next = arr[i+1];
        }

        arr[n-1]->next = NULL;

        return arr[0];
    }
};
