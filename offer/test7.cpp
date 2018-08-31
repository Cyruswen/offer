#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
        }
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == NULL)
        {
            return NULL;

        }
        ListNode* cur = pListHead;
        size_t count = 0;
        while(cur != NULL)
        {
            count++;
            cur = cur->next;
        }

        if(k > count)
        {
            return NULL;
        }
        ListNode* fast = pListHead;
        ListNode* slow = pListHead;
        for(size_t i = 1; i < k; i++)
        {
            fast = fast->next;

        }
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;

        }
        return slow;
    }
};

int main()
{
    ListNode s1 = ListNode(1);
    ListNode s2 = ListNode(2);
    ListNode s3 = ListNode(3);
    ListNode s4 = ListNode(4);
    ListNode s5 = ListNode(5);
    s1.next = &s2;
    s2.next = &s3;
    s3.next = &s4;
    s4.next = &s5;
    Solution s;
    ListNode* p = s.FindKthToTail(&s1, 6);
    cout<<(*p).val<<endl;
    return 0;
}
