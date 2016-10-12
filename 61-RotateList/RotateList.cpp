#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

typedef struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
} ListNode;

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL) {
            return head;
        }
        int len = 0;
        for (ListNode *node = head; node != NULL; node = node->next) {
            len++;
        }
        k = k % len;
        if (k == 0) {
            return head;
        }
        ListNode *fast = head;
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }
        ListNode *slow = head;
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        return head;
    }
};

int main() {
    Solution solution;
    //若此处写为 ListNode *head, *temp, *currentHead; 则错误
    ListNode *head, *temp, *currentHead = new ListNode(1);
    head = currentHead;
    for (int i = 1; i < 5; i++) {
        currentHead->next = new ListNode(i+1);
        currentHead = currentHead->next;
    }

    head = solution.rotateRight(head, 2);

    temp = head;
    for (int i = 0; i < 5 && temp; i++) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}


