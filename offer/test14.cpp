#include <iostream>
#include <stack>
using namespace std;

#if 1
struct TreeNode
{
    int val;
    TreeNode* pleft = NULL;
    TreeNode* pright = NULL;
    TreeNode(int x)
        :val(x)
    {}
};

class TreePrintRecur
{ 
//树的遍历  递归实现
public:
    void preOrderPrint(TreeNode* root)
    {
        if(root == NULL)
            return;
        cout<<root->val<<" ";
        preOrderPrint(root->pleft);
        preOrderPrint(root->pright);
    }
    
    void inOrderPrint(TreeNode* root)
    {
        if(root == NULL)
            return;
        inOrderPrint(root->pleft);
        cout<<root->val<<" ";
        inOrderPrint(root->pright);
    }

    void postOrderPrint(TreeNode* root)
    {
        if(root == NULL)
            return;
        postOrderPrint(root->pleft);
        postOrderPrint(root->pright);
        cout<<root->val<<" ";
    }
};

//思路：搞一个栈，先将根节点入栈，接下来直到栈为空，依次出栈，
//出栈后判断出栈元素的右孩子是否为空，不为空右孩子入栈。
//判断左孩子是否为空，不为空左孩子入栈。

class TreePrint
{
    //非递归实现树的遍历
public:
    void preOrderPrint(TreeNode* root)
    {
        if(root == NULL)
            return;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* tmp = s.top();
            cout<<tmp->val<<" ";
            s.pop();
            if(tmp->pright != NULL)
                s.push(tmp->pright);
            if(tmp->pleft != NULL)
                s.push(tmp->pleft);
        }
        cout<<endl;
    }

    void inOrderPrint(TreeNode* root)
    {
        if(root == NULL)
            return;
        stack<TreeNode*> s;
        while(!s.empty() || root != NULL)
        {
            if(root != NULL)
            {
                s.push(root);
                root = root->pleft;
            }
            else
            {
                TreeNode* tmp = s.top();
                s.pop();
                cout<<tmp->val<<" ";
                root = tmp->pright;
            }
        }
        cout<<endl;
    }

    //后序遍历
    void postOrderPrint(TreeNode* root)
    {
        if(root == NULL)
            return;
        stack<TreeNode*> tmp;
        stack<TreeNode*> result;
        tmp.push(root);
        while(!tmp.empty())
        {
            TreeNode* tmpNode = tmp.top();
            result.push(tmpNode);
            tmp.pop();
            if(tmpNode->pleft != NULL)
                tmp.push(tmpNode->pleft);
            if(tmpNode->pright != NULL)
                tmp.push(tmpNode->pright);
        }
        while(!result.empty())
        {
            cout<<result.top()->val<<" ";
            result.pop();
        }
        cout<<endl;
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
    root->pleft = node1;
    root->pright = node2;
    node1->pleft = node3;
    node1->pright = node4;
    node2->pleft = node5;
    node2->pright = node6;
    TreePrintRecur print;
    cout<<"一、递归遍历:"<<endl;
    cout<<"先序遍历："<<endl;
    print.preOrderPrint(root);
    cout<<endl;
    cout<<"中序遍历："<<endl;
    print.inOrderPrint(root);
    cout<<endl;
    cout<<"后序遍历："<<endl;
    print.postOrderPrint(root);
    cout<<endl;
    cout<<"二、非递归遍历:"<<endl;
    TreePrint print2;
    cout<<"先序遍历："<<endl;
    print2.preOrderPrint(root);
    cout<<"中序遍历："<<endl;
    print2.inOrderPrint(root);
    cout<<"后序遍历："<<endl;
    print2.postOrderPrint(root);
    return 0;
}
#endif
