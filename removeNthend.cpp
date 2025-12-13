struct ListNode {
    int val;
    ListNode *next;
    
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}  
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == NULL) return NULL;

    ListNode* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    if (n > count) return head; // Assuming n is valid, but to be safe

    if (n == count) {
        // Remove head
        ListNode* toDelete = head;
        head = head->next;
        delete toDelete;
        return head;
    }

    // Find the (count - n - 1)th node (0-based)
    ListNode* prev = head;
    for (int i = 1; i < count - n; i++) {
        prev = prev->next;
    }

    ListNode* toDelete = prev->next;
    prev->next = toDelete->next;
    delete toDelete;

    return head;
}
