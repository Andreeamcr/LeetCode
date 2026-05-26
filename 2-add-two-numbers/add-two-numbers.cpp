/**
 * Definition for singly-linked list.
 */

//  struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* currentNode = new ListNode();
        ListNode* listHead = currentNode;
        int carry{0};
        int current_result{0};
        while(l1 || l2 || carry != 0){
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            current_result = sum % 10;
            listHead->next = new ListNode(current_result);
            listHead = listHead->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return currentNode->next;
    }
};