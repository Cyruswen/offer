#include <iostream>
#include <stack>
using namespace std;

#if 0
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

#if 0
class TreeNode
{
    public int val;
    public TreeNode left = null;
    public TreeNode right = null;
    TreeNode(int x)
    {
        this.val = x;

    }
}

class TreePrint
{
    public  void postOrderPrint(TreeNode root)
    {
        if(root == null)
            return;
        System.out.println("后序遍历：");
        Stack<TreeNode> s1 = new Stack<TreeNode>();
        Stack<TreeNode> s2 = new Stack<TreeNode>();
        s1.push(root);
        while(!s1.empty())
        {
            TreeNode tmp = s1.pop();
            s2.push(tmp) ;
            if(tmp.left != null)
                s1.push(tmp.left);
            if(tmp.right != null)
                s1.push(tmp.right);

        }
        while(!s2.empty())
            System.out.print(s2.pop().val+" ");
        System.out.println();

    }

    public void inOrderPrint(TreeNode root)
    {
        if(root == null)
            return;
        System.out.println("中序遍历：");
        Stack<TreeNode> s = new Stack<TreeNode>();
        while(!s.empty() || root != null)
        {
            if(root != null)
            {
                s.push(root);
                root = root.left;

            }
            else
            {
                System.out.print(s.peek().val+" ");
                root = s.pop().right;

            }

        }
        System.out.println();

    }

    public void preOrderPrint(TreeNode root)
    {
        if(root == null)
            return;
        System.out.println("先序遍历：");
        Stack<TreeNode> s = new Stack<TreeNode>();
        s.push(root);
        while(!s.empty())
        {
            TreeNode tmp = s.pop();
            System.out.print(tmp.val+" ");
            if(tmp.left != null)
                s.push(tmp.right);
            if(tmp.right != null)
                s.push(tmp.left);

        }
        System.out.println();

    }

}

public class Main{
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        TreeNode node1 = new TreeNode(2);
        TreeNode node2 = new TreeNode(3);
        TreeNode node3 = new TreeNode(4);
        TreeNode node4 = new TreeNode(5);
        TreeNode node5 = new TreeNode(6);
        TreeNode node6 = new TreeNode(7);
        root.left = node1;
        root.right = node2;
        node1.left = node3;
        node1.right = node4;
        node2.left = node5;
        node2.right = node6;
        TreePrint p = new TreePrint();
        p.postOrderPrint(root);
        p.inOrderPrint(root);
        p.preOrderPrint(root);
    }

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

        bool _HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
        {
            if(pRoot1 == NULL)
                return false;
            if(pRoot2 == NULL)
                return true;
            if(pRoot1->val != pRoot2->val)
                return false;
            return _HasSubtree(pRoot1->left, pRoot2->left)&&_HasSubtree(pRoot1->right, pRoot2->right);
        }

        bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
        {
            bool result = false;
            if(pRoot1 != NULL && pRoot2 != NULL)
            { 
                if(pRoot1->val == pRoot2->val)
                     result = _HasSubtree(pRoot1, pRoot2);
                if(!result)
                {
                    HasSubtree(pRoot1->left, pRoot2);
                }
                if(!result)
                {
                    HasSubtree(pRoot1->right, pRoot2);
                }
            }
            return result;
        }
};
#endif

#if 0
//求树的镜像
struct TreeNode
{
    int val;
    TreeNode* pleft = NULL;
    TreeNode* pright = NULL;
    TreeNode(int x)
        :val(x)
    {}
};

class MirrorTree
{
public:
    //递归
    void MirrorRecur(TreeNode* root)
    {
        if(root == NULL)
            return;
        swap(root->pleft, root->pright);
        if(root->pleft != NULL)
            MirrorRecur(root->pleft);
        if(root->pright != NULL)
            MirrorRecur(root->pright);
    }

public:
    //非递归
    void Mirror(TreeNode* root)
    {
        if(root == NULL)
            return;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* tmp = s.top();
            swap(tmp->pleft, tmp->pright);
            s.pop();
            if(tmp->pleft)
                s.push(tmp->pleft);
            if(tmp->pright)
                s.push(tmp->pright);
        }
    }
};


void preOrderPrint(TreeNode* root)
{
    if(root == NULL)
        return;
    cout<<root->val<<" ";
    preOrderPrint(root->pleft);
    preOrderPrint(root->pright);
}

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
    preOrderPrint(root);
    cout<<endl;
    MirrorTree m;
    m.MirrorRecur(root);    
    preOrderPrint(root);
    cout<<endl;
    m.Mirror(root);
    preOrderPrint(root);
    cout<<endl;
    return 0;
}
#endif

#if 1

struct TreeNode
{
    int val;
    TreeNode* pright = NULL;
    TreeNode* pleft = NULL;
    TreeNode(int x)
        :val(x)
    {}
};

class Print
{
public:
    void zPrint(TreeNode* root)
    {
        if(root == NULL)
            return;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        while(!s1.empty() || !s2.empty())
        {
            while(!s1.empty())
            { 
                TreeNode* tmp = s1.top();
                cout<<tmp->val<<" ";
                s1.pop();
                if(tmp->pleft)
                    s2.push(tmp->pleft);
                if(tmp->pright)
                    s2.push(tmp->pright);
            }
            while(!s2.empty())
            {
                TreeNode* tmp = s2.top();
                cout<<tmp->val<<" ";
                s2.pop();
                if(tmp->pright)
                    s1.push(tmp->pright);
                if(tmp->pleft)
                    s1.push(tmp->pleft);
            }
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
    Print p;
    p.zPrint(root);
    return 0;
}

#endif
