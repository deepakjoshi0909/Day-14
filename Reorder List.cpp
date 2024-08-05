class Solution {
public:
    void reorderList(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        
       
        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;  // Fixed: Advance the pointer
        }

        int st = 0;
        int end = arr.size() - 1;
        ListNode* ans = head;
        
        while (st <= end) {
            if (st == end) {
                ans->val = arr[st];  
                break;
            }
            
            if (st < end) {
                ans->val = arr[st++];
                ans = ans->next;
                ans->val = arr[end--];
                ans = ans->next;
            }
        }
        
        if (ans != nullptr) {
            ans->next = nullptr;  
        }
    }
};
