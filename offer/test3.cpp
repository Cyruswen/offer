#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

//逆置单链表 使用堆
//struct ListNode {
//       int val;
//       struct ListNode *next;
//       ListNode(int x) :
//             val(x), next(NULL) {
//       }
// };
//
//class Solution {
//public:
//    vector<int> printListFromTailToHead(ListNode* head) {
//        std::vector<int> ArrayList;
//        std::stack<ListNode*> node;
//        ListNode* cur = head;
//        while(cur != NULL)
//        {
//            node.push(cur);
//            cur = cur->next;
//
//        }
//        while(!node.empty())
//        {
//            cur = node.top();
//            ArrayList.push_back(cur->val);
//            node.pop();
//
//        }
//        return ArrayList;
//    }
//};
//
//int main()
//{
//    ListNode* p = new ListNode(67);
//    p->next = new ListNode(0);
//    p->next->next = new ListNode(24);
//    p->next->next->next = new ListNode(58);
//    Solution s;
//    std::vector<int>v = s.printListFromTailToHead(p);
//    for(size_t i = 0; i < v.size(); i++)
//    {
//        cout<<v[i]<<" ";
//    }
//    cout<<endl;
//}


//
