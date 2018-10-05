#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <unistd.h>
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

#if 0
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

#if 0
//非递归
//判断以序列是不是二叉搜索树的后序遍历结果。
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        size_t size = sequence.size()-1;
        if(size == 0)
            return false;
        while(size--)
        {
            size_t i = 0;
            while(sequence[i++] < sequence[size]);
            while(sequence[i++] > sequence[size]);
            if(i < size)
                return false;
        }
        return true;
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > result;
        if(pRoot == NULL)
            return result;
        queue<TreeNode*> q;
        q.push(pRoot);
        vector<int> v;
        while(!q.empty())
        {
            size_t hi = q.size();
            for(size_t i = 0; i < hi; i++)
            { 
                TreeNode* tmp = q.front();
                q.pop();
                v.push_back(tmp->val);
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
            result.push_back(v);
            v.clear();
        }
        return result;
    }
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
    a.Print(root);
    return 0;
}
#endif

#if 0   
以下是错误代码      自行略过。
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
        s1.push(pRoot);
        vector<int> v;
        while(!s1.empty() || !s2.empty())
        {
            v.clear();
            while(!s1.empty())
            {
                TreeNode* tmp = s1.top();
                s1.pop();
                v.push_back(tmp->val);
                if(tmp->right)
                    s2.push(tmp->right);
                if(tmp->left)
                    s2.push(tmp->left);
            }
            if(!v.empty())
                result.push_back(v);
            v.clear();
            while(!s2.empty())
            {
                TreeNode* tmp = s2.top();
                s2.pop();
                v.push_back(tmp->val);
                if(tmp->right)
                    s1.push(tmp->right);
                if(tmp->left)
                    s1.push(tmp->left);
            }
            if(!v.empty())
                result.push_back(v);
        }
        return result;
    }
private:
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root)
            isPath(root, expectNumber);
        return result;
    }

private:
    void isPath(TreeNode* node, int left)
    {
        tmp.push_back(node->val);
        if(left - node->val == 0 && node->left == NULL && node->right == NULL)
            result.push_back(tmp);
        else
        { 
            if(node->left)
                isPath(node->left, left-node->val);
            if(node->right)
                isPath(node->right, left- node->val);
        }
        tmp.pop_back();
    }

private:
    vector<vector<int> > result;
    vector<int> tmp;

};
#endif

#if 0
struct TreeNode
{
    int val;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    TreeNode(int x)
        :val(x)
    {}
};

class Solution
{
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root)
            isPath(root, expectNumber);
        return result;
    }

private:
    void isPath(TreeNode* node, int left)
    {
        tmp.push_back(node->val);
        if(left - node->val == 0 && !node->left && !node->right)
            result.push_back(tmp);
        if(node->left)
            isPath(node->left, left - node->val);
        if(node->right)
            isPath(node->right, left - node->val);
        tmp.pop_back();
    }

private:
    vector<vector<int> > result;
    vector<int> tmp;
};
#endif

#if 0
//生成随机数的函数
int main()
{
    srand(time(0));
    for(;;) 
    {
        cout<<"time(0): "<<time(0)<<" ";
        cout<<"生成随机数："<<rand()%10 + 1<<endl;
        sleep(1);
    }
    return 0;
}
#endif
