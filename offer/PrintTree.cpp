#include <iostream>
#include <vector>
#include <queue>
using namespace std;


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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> result;
        if(root == NULL)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* top;
        while(!q.empty())
        {
            top = q.front();
            if(top->left != NULL)
                q.push(top->left);
            if(top->right != NULL)
                q.push(top->right);
            result.push_back(top->val);
            q.pop();

        }
        return result;

    }

};
