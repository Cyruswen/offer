#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
        }
};

#if 1
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        // 1 2 3 3 4 4 5
        ListNode* pre = pHead;
        ListNode* fast = pHead->next;
        ListNode* slow = pHead;
        while(fast != NULL)
        { 
            if(fast->val == slow->val)
            {
                while(fast->next != NULL && fast->next->val == slow->val)
                {
                    fast = fast->next;
                }
                pre->next = fast->next;
                slow = pre->next;
                fast = slow->next;
            }
            else
            { 
                pre = slow;
                slow = slow->next;
                fast = fast->next; 
            }
        }       
        return pHead;
    }
};
#endif

#if 0
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == NULL)
            return NULL;
        map<int, int> m;
        ListNode* cur = pHead;
        while(cur != NULL)
        {
            m[cur->val]++;
            cur = cur->next;
        }
        cur = pHead;
        ListNode* new_pHead = new ListNode(0);
        ListNode* cur2 = new_pHead;
        while(cur != NULL)
        {
            if(m[cur->val] == 1)
            {
                cur2->next = new ListNode(cur->val);
                cur2 = cur2->next;

            }
            cur = cur->next;

        }
        ListNode* tmp = new_pHead;
        new_pHead = new_pHead->next;
        delete tmp;
        return new_pHead;

    }

};
#endif
int main()
{
    Solution a;
    ListNode* phead = new ListNode(1);
    ListNode* p1 = new ListNode(2);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(4);
    ListNode* p5 = new ListNode(5);
    phead->next = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    ListNode* pHead = a.deleteDuplication(phead);
    ListNode* cur = pHead;
    while(cur != NULL)
    {
        cout<<cur->val<<" ";
        cur = cur->next;
    }
    cout<<endl;
    return 0;
}
