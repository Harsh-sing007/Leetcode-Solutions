class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        auto countNodes = [](ListNode* temp) -> int {
            int count = 0;
            while (temp) {
                count++;
                temp = temp->next;
            }
            return count;
        };

        int n1 = countNodes(headA);
        int n2 = countNodes(headB);

        ListNode* t1 = headA;
        ListNode* t2 = headB;

        if (n1 > n2) swap(t1, t2);

        int d = abs(n1 - n2);

        while (d--) t2 = t2->next;

        while (t1 != t2) {
            t1 = t1->next;
            t2 = t2->next;
        }

        return t1;
    }
};