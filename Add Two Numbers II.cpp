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

    void convertIntoNum(ListNode* l1, vector<int>& num){
        while(l1 != NULL){
            num.push_back(l1->val);
            l1 = l1->next;
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> num1;
        vector<int> num2;

        convertIntoNum(l1, num1);
        convertIntoNum(l2, num2);

        stack<int> st;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;

        while(i >= 0 || j >= 0 || carry != 0){
            int sum = carry;
            if(i >= 0) sum += num1[i--];
            if(j >= 0) sum += num2[j--];
            st.push(sum % 10);
            carry = sum / 10;
        }

        ListNode* root = new ListNode();
        ListNode* temp = root;

        while(!st.empty()){
            temp->next = new ListNode(st.top());
            st.pop();
            temp = temp->next;
        }

        return root->next;
    }
};
