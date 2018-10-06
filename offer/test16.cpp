#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <string>
using namespace std;

#if 0
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
        label(x), next(NULL), random(NULL) {
        }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL)
            return NULL;
        RandomListNode* cur = pHead;
        while(cur != NULL)
        {
            RandomListNode* new_node = new RandomListNode(cur->label);
            new_node->next = cur->next;
            cur->next = new_node;
            cur = new_node->next;

        }
        cur = pHead;
        while(cur != NULL)
        {
            if(cur->random)
            {
                cur->next->random = cur->random->next;

            }
            cur = cur->next->next;
            RandomListNode* new_head = pHead->next;
            cur = new_head;
            RandomListNode* tmp = pHead;
            while(cur->next != NULL)
            {
                tmp->next = cur->next;
                cur->next = cur->next->next;
                cur = cur->next;
                tmp = tmp->next;

            }
            tmp->next = NULL;
            return new_head;

        }
    };
#endif

#if 0

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
        }
};

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL)
            return NULL;
        stack<TreeNode*> s;
        vector<TreeNode*> result;
        while(!s.empty() || pRootOfTree != NULL)
        {
            if(pRootOfTree)
            { 
                s.push(pRootOfTree);
                pRootOfTree = pRootOfTree->left;
            }
            else
            {
                TreeNode* tmp = s.top();
                s.pop();
                result.push_back(tmp);
                pRootOfTree = tmp->right;
            }
        }
        TreeNode* root = result[0];
        TreeNode* cur = root;
        for(size_t i = 1; i < result.size(); i++)
        {
            cur->right = result[i];
            result[i]->left = cur;
            cur = cur->right;
        }
        return root;
    }

};
#endif

#if 0
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int len = numbers.size();
        if(len == 0)
            return 0;
        map<int,int> m;
        for(int i = 0; i < len;i++)
            m[numbers[i]]++;
        for(int i = 0; i < len; i++)
            if(m[numbers[i]] > len/2)
                return numbers[i];
        return 0;
    }
};
#endif

#if 1
int main()
{
    int a = 0;
    long b = 0;
    size_t c = 0;
    long long d = 0;
    double e = 1.0;
    cout<<"a "<<sizeof(a)<<" b "<<sizeof(b)<<" c "<<sizeof(c)<<" d "<<sizeof(d)<<" e "<<sizeof(e)<<" "<<endl;
    return 0;
}
#endif
