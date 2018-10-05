#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <map>
using namespace std;

#if 0
class Solution {
public:
    void push(int value) {
        if(stack2.empty())
            stack2.push(value);
        else if(stack2.top() > value)
            stack2.push(value);
        stack1.push(value);
    }
    void pop() {
        if(stack1.top() == stack2.top())
        {
            stack1.pop();
            stack2.pop();
        }
        else
            stack1.pop();
    }
    int top() {
        return stack1.top();
    }
    int min() {
        return stack2.top();
    }
private:
    stack<int> stack1;
    stack<int> stack2;
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > result;
        if(pRoot == NULL)
            return result;
        vector<int> v;
        stack1.push(pRoot);
        while(!stack1.empty() || !stack2.empty())
        {
            v.clear();
            while(!stack1.empty())
            {
                TreeNode* tmp = stack1.top();
                v.push_back(tmp->val);
                stack1.pop();
                if(tmp->left)
                    stack2.push(tmp->left);
                if(tmp->right)
                    stack2.push(tmp->right);
            }
            if(!v.empty())
                result.push_back(v);
            v.clear();
            while(!stack2.empty())
            {
                TreeNode* tmp = stack2.top();
                v.push_back(tmp->val);
                stack2.pop();
                if(tmp->right)
                    stack1.push(tmp->right);
                if(tmp->left)
                    stack1.push(tmp->left);
            }
            if(!v.empty())
                result.push_back(v);
        }
        return result;
    }

private:
    stack<TreeNode*> stack1;
    stack<TreeNode*> stack2;
};

int main()
{

    TreeNode* root = new TreeNode(1);
    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(3);
    TreeNode* node3 = new TreeNode(4);
    TreeNode* node4 = new TreeNode(5);
    TreeNode* node5 = new TreeNode(6);
    TreeNode* node6 = new TreeNode(7);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = node6;
    Solution a;
    vector<vector<int> > v;
    v = a.Print(root);
}
#endif

#if 1
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        size_t size = pushV.size();
        stack<int> help;
        size_t j = 0;
        for(size_t i = 0; i < size; i++)
        {
            while(help.empty() || help.top() != popV[i])
            {
                help.push(pushV[j++]);
                if(j > size)
                    return false;
            }
            help.pop();
        }
        if(help.empty())
            return true;
        else
            return false;
    }
};
#endif
