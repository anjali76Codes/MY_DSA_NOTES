class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
            // If the list is empty or has only one node, return the head
            if (head == nullptr || head->next == nullptr) return head;
    
            // Dummy node to act as the previous node to the head
            ListNode* dummy = new ListNode(0);
            dummy->next = head;
            ListNode* prev = dummy;  // This will always point to the node before the pair being swapped
    
            while (prev->next != nullptr && prev->next->next != nullptr) {
                // Nodes to be swapped
                ListNode* first = prev->next;
                ListNode* second = prev->next->next;
    
                // Perform the swapping
                first->next = second->next;
                second->next = first;
                prev->next = second;
    
                // Move prev two steps ahead for the next pair
                prev = first;
            }
    
            // The new head of the list is the next of the dummy node
            return dummy->next;
        }
    };
    