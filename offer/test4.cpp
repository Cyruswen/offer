#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int len = vin.size();
        if(len == 0)
        {
            return NULL;
        }
        vector<int> leftpre;
        vector<int> leftin;
        vector<int> rightpre;
        vector<int> rightin;
        int leftlen = 0;
        TreeNode* root = new TreeNode(pre[0]);
        int i = 0;
        for(; i < len; i++)
        {
            if(vin[i] == pre[0])
            {
                break;
            }
            leftlen++;
        }
        for(int j = 0; j <= leftlen; j++)
        {
            leftpre.push_back(pre[j+1]);
            leftin.push_back(vin[j]);
        }
        for(; i < len; i++)
        {
            rightin.push_back(vin[i+1]);
            rightpre.push_back(pre[i+1]);
        }
        root->left = reConstructBinaryTree(leftpre,leftin);
        root->right = reConstructBinaryTree(rightpre,rightin);
        return root;
    }
};

int main()
{
    vector<int> pre;
    pre.push_back(1);
    pre.push_back(2);
    pre.push_back(4);
    pre.push_back(7);
    pre.push_back(3);
    pre.push_back(5);
    pre.push_back(6);
    pre.push_back(8);
    vector<int> vin;
    vin.push_back(4);
    vin.push_back(7);
    vin.push_back(2);
    vin.push_back(1);
    vin.push_back(5);
    vin.push_back(3);
    vin.push_back(8);
    vin.push_back(6);
    Solution s;
    s.reConstructBinaryTree(pre, vin);
    return 0;
}
