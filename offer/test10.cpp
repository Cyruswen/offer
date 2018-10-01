#include <iostream>
#include <stack>
#include <string.h>
#include <vector>
#include <string>
#include <map>
using namespace std;

#if 0
class Solution {
public:
    void replaceSpace(char *str,int length) {
        if(str == NULL)
            return;
        int space_count = 0;
        for(int i = 0; i < length; i++)
        {
            if(str[i] == ' ')
                space_count++;
        }
        int new_len = space_count*2 + length;
        int pre = length - 1;
        int last = new_len - 1;
        str[last] = '\0';
        while(pre != last)
        {
            if(str[pre] != ' ')
                str[last--] = str[pre--];
            else{ 
                str[last] = '0';
                str[last - 1] = '2';
                str[last - 2] = '%';
                last -= 3;
                pre--;
            }
        }
    }
};

int main()
{
    char str[20] = "we are happy.";
    int length = strlen(str);
    Solution a;
    a.replaceSpace(str,length);
    cout<<str<<endl;
    return 0;
}
#endif

#if 0
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size() == 0 || vin.size() == 0)
            return NULL;
        vector<int> leftpre;
        vector<int> leftvin;
        vector<int> rightpre;
        vector<int> rightvin;
        size_t i = 0;
        for(; i < vin.size(); i++)
        {
            if(vin[i] == pre[0])
            {
                break;
            }
        }
        for(size_t j = 0; j < i; j++)
        {
            leftvin.push_back(vin[j]);
        }
        for(size_t j = 1; j <= i; j++)
        {
            leftpre.push_back(pre[j]);
        }
        for(size_t j = i+1; j < vin.size(); j++)
        {
            rightvin.push_back(vin[j]);
        }
        for(size_t j = i+1; j < pre.size(); j++)
        {
            rightpre.push_back(pre[j]);
        }
        TreeNode* root = new TreeNode(pre[0]); 
        root->left = reConstructBinaryTree(leftpre, leftvin);
        root->right = reConstructBinaryTree(rightpre, rightvin);
        return root;
    }
};
#endif

#if 0
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int tmp = stack2.top();
        stack2.pop();
        return tmp;
    }

private:
        stack<int> stack1;
        stack<int> stack2;
};
#endif

//34512
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int index1 = 0;
        int index2 = rotateArray.size()-1;
        int midindex = (index1 + index2)/2;
        while(rotateArray[index1] > rotateArray[index2])
        {
            if(index2 - index1 == 1)
            {
                midindex = index2;
                break;
            }
            if(rotateArray[midindex] > rotateArray[index1])
                index1 = midindex;
            if(rotateArray[midindex] < rotateArray[index2])
                index2 = midindex;
            midindex = (index1 + index2)/2;
        }
        return rotateArray[midindex];
    }
};

int main()
{
    Solution a;
    int arr[] = {3,4,5,1,2};
    size_t size = sizeof(arr)/sizeof(4);
    vector<int> v(arr, arr+size);
    int tmp = a.minNumberInRotateArray(v);
    cout<<tmp<<endl;
    return 0;
}
