#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#if 0
class Solution {
private:        
    static bool compare(int a, int b)
    {
        string x = to_string(a)+to_string(b);
        string y = to_string(b)+to_string(a);
        return x < y; 
    }

public:
    string PrintMinNumber(vector<int> numbers) {
        size_t len = numbers.size();
        if(len == 0)
            return "";
        string result = "";
        sort(numbers.begin(), numbers.end(), compare);
        for(size_t i = 0; i < numbers.size(); i++)
        {
            result += to_string(numbers[i]);
        }
        return result;
    }
};

int main()
{
    int arr[] = {3,32,321};
    vector<int> v(arr, arr+3);
    Solution a;
    string s = a.PrintMinNumber(v);
    cout<<s<<endl;
}
#endif

#if 0
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index <= 0)
            return 0;
        int numth = 0;
        int num = 0;
        while(numth < index)
        {
            num += 1;
            if(isUgly(num))
                numth++;
        }
        return num;
    }
private:
    bool isUgly(int num)
    {
        while(num % 2 == 0)
            num /= 2;
        while(num % 3 == 0)
            num /= 3;
        while(num % 5 == 0)
            num /= 5;
        if(num == 1)
            return true;
        return false;
    }
};

int main()
{
    Solution a;
    int x = a.GetUglyNumber_Solution(1500);
    cout<<x<<endl;
    return 0;
}
#endif
#if 0

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
        }
};

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2 ) {
        if(pHead1 == NULL || pHead2 == NULL)
            return NULL;
        ListNode* cur1 = pHead1;
        ListNode* cur2 = pHead2;
        int len1 = 1;
        int len2 = 1;
        while(cur1 != NULL)
        {
            cur1 = cur1->next;
            len1++;
        }
        while(cur2 != NULL)
        {
            cur2 = cur2->next;
            len2++;
        }
        cur1 = pHead1;
        cur2 = pHead2;
        if(len1 > len2)
            for(int i = 0; i < (len1-len2); i++)
                cur1 = cur1->next;
        else
            for(int i = 0; i < len2 - len1; i++)
                cur2 = cur2->next;
        while(cur1 != cur2 && cur1 != NULL && cur2 != NULL)
        {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    }
};
#endif

#if 0
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        map<int,int> m;
        for(size_t i = 0; i < data.size(); i++)
            m[data[i]]++;
        return m[k];
    }
};
#endif

#if 0
//错误代码
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        size_t end = data.size() - 1;
        size_t beg = 0;
        size_t mid = (end + beg)/2;
        while(end - beg > 1)
        {
            if(data[mid] == k)
                break;
            else if(data[mid] > k)
                end = mid - 1;
            else
                beg = mid + 1;
        }
        if(end - beg <= 1)
            return 0;
        int cur = mid;
        int count = 1;
        while(cur >= 0)
        {
            --cur;
            if(data[cur] == k)
                count++;
            else
                break;
        }
        cur = mid;
        while(cur < (int)data.size())
        {
            ++cur;
            if(data[cur] == k)
                count++;
            else
                break;
        }
        return count;
    }
};
#endif

#if 0
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int end = data.size() - 1;
        int begin = 0;
        int preIndex = getPre(data, begin, end, k);
        int lastIndex = getLast(data, begin, end, k);
        if(preIndex != -1 && lastIndex != -1)
            return lastIndex - preIndex + 1;
        return -1;
    }
private:
    int getPre(vector<int> data, int begin, int end, int k)
    {
        int mid = (end - begin)/2;
        while(begin <= end)
        {
            if(data[mid] > k)
                end = mid-1;
            else if(data[mid] < k)
                begin = mid + 1;
            else
            { 
                if(mid > 0 && data[mid] != k)
                    return mid;
                else
                    end = mid - 1;
            }
            mid = (begin + end)/2;
        }
        return -1;
    }

    int getLast(vector<int> data, int begin, int end, int k)
    {
        int mid = (end - begin)/2;
        while(begin <= end)
        {
            if(data[mid] > k)
                end = mid - 1;
            else if(data[mid] < k)
                begin = mid + 1;
            else
            {
                if(mid < (int)data.size() && data[mid] != k)
                    return mid;
                else
                    begin = mid + 1;
            }
        }
        return -1;
    }
};
#endif

#if 0
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int size = data.size();
        int begin = size - 1;
        int end = 0;
        int mid = (end + begin)/2;
        int count = 0;
        while(begin <= end)
        {
            if(data[mid] < k)
                begin = mid + 1;
            else if(data[mid] > k)
                end = mid - 1;
            else
                break;
        }
        if(begin > end)
            return count;
        int cur = mid;
        while(cur > 0 && data[cur--] == k)
            count++;
        cur = mid;
        while(cur < size && data[++cur] == k)
            count++;
        return count;
    }

};
#endif

#if 0
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<int> tmp;
        vector<vector<int> > result;
        if(sum <= 0)
            return result;
        int small = 1;
        int big = 2;
        while(small < big)
        {
            int tmp_sum = (small + big)*(big - small + 1)/2;
            if(tmp_sum < sum)
                big++;
            else if(tmp_sum > sum)
                small++;
            else
            { 
                for(int i = small; i <= big; i++)
                    tmp.push_back(i);
                result.push_back(tmp);
                tmp.clear();
                small++;
            }
        }
        return result;
    }
};
#endif

#if 0
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        int size = array.size();
        if(size < 2)
            return result;
        int begin = 0;
        int end = size - 1;
        while(begin < end)
        {
            if(array[begin]+array[end] == sum)
            {
                result.push_back(array[begin]);
                result.push_back(array[end]);
                break;
            }
            else if(begin < size && array[begin]+array[end] < sum)
                begin++;
            else if(end >= 0 && array[begin]+array[end] > sum)
                end--;
        }
        return result;
    }
};
#endif

#if 0
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int size = data.size();
        if(size < 2)
            return;
        int result = 0;
        for(int i = 0; i < size; i++)
            result ^= data[i];
        int flag = 1;
        int index = 0;
        while(flag)
        {
            if((result & flag) == 0)
            {
                index++;
                flag = flag<<1;
            }
            else
                break;
        }
        if(flag == 0)
            return;
        for(int i = 0; i < size; i++)
        {
            if(isBit1(data[i], index))
                *num1 ^= data[i];
            else
                *num2 ^= data[i];
        }
    }
private:
    bool isBit1(int num, int index)
    {
        num = num>>index;
        return num&1?true:false;
    }
};
#endif

#if 1
//树的先序遍历

struct TreeNode{
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
    //先序遍历
    void prePrint(TreeNode* root)
    {
        if(root == NULL)
            return;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* tmp = s.top();
            s.pop();
            cout<<tmp->val<<" ";
            if(tmp->right)
                s.push(tmp->right);
            if(tmp->left)
                s.push(tmp->left);
        }
        cout<<endl;
    }
    //中序遍历
   void vinPrint(TreeNode* root)
   {
       if(root == NULL)
           return;
       stack<TreeNode*> s;
       while(!s.empty() || root != NULL)
       {
           if(root)
           {
                s.push(root);
                root = root->left;
           }
           else
           {
               TreeNode* tmp = s.top();
               s.pop();
               cout<<tmp->val<<" ";
               root = tmp->right;
           }
       }
       cout<<endl;
   }

   //后序遍历
   void postPrint(TreeNode* root)
   {
       if(root == NULL)
           return;
       stack<TreeNode*> s;
       stack<int> s2;
       s.push(root);
       while(!s.empty())
       {
           TreeNode* tmp = s.top();
           s.pop();
           s2.push(tmp->val);
           if(tmp->left)
               s.push(tmp->left);
           if(tmp->right)
               s.push(tmp->right);
       }
       while(!s2.empty())
       {
           cout<<s2.top()<<" ";
           s2.pop();
       }
       cout<<endl;
   }

   //层序遍历
   void levePrint(TreeNode* root)
   {
       if(root == NULL)
           return;
       queue<TreeNode*> q;
       q.push(root);
       while(!q.empty())
       {
           TreeNode* tmp = q.front();
           q.pop();
           cout<<tmp->val<<" ";
           if(tmp->left)
               q.push(tmp->left);
           if(tmp->right)
               q.push(tmp->right);
       }
       cout<<endl;
   }
   //之字形遍历
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
               s1.pop();
               cout<<tmp->val<<" ";
               if(tmp->left)
                   s2.push(tmp->left);
               if(tmp->right)
                   s2.push(tmp->right);
           }
           while(!s2.empty())
           {
               TreeNode* tmp = s2.top();
               s2.pop();
               cout<<tmp->val<<" ";
               if(tmp->right)
                   s1.push(tmp->right);
               if(tmp->left)
                   s1.push(tmp->left);
           }
       }
       cout<<endl;
   }
   //求二叉树的高度
   int depth(TreeNode* root)
   {
       if(root == NULL)
           return 0;
       int left = depth(root->left);
       int right = depth(root->right);
       return left > right ? left+1 : right+1;
   }
   //判断一颗二叉树是不是平衡二叉树
   void isBalanced(TreeNode* root)
   {
       if(root == NULL)
           return;
       if(_isBalanced(root))
           cout<<"该树是平衡二叉树"<<endl;
       else
           cout<<"该树不是平衡二叉树"<<endl;
   }

   //查找一颗二叉树路径和为sum的路径
   void findWay(TreeNode* root, int sum)
   {
        if(root == NULL)
            return;
        _findWay(root ,sum);
        cout<<"和为sum的路径有："<<endl;
        printResult();
   }


private:
   bool _isBalanced(TreeNode* root)
   {
       if(root == NULL)
           return true;
       int left = depth(root->left);
       int right = depth(root->right);
       int diff = left - right;
       if(diff > 1 || diff < -1)
           return false;
       return _isBalanced(root->left) && _isBalanced(root->right);
   }

   void _findWay(TreeNode* root, int left)
   {
       tmp.push_back(root->val);
       if(left - root->val == 0 && root->left == NULL && root->right == NULL)
           result.push_back(tmp);
       if(root->left)
           _findWay(root->left, left - root->val);
       if(root->right)
           _findWay(root->right, left - root->val);
       tmp.pop_back();
   }
    
   void printResult()
   {
       for(size_t i = 0; i < result.size(); i++)
       {
           for(size_t j = 0; j < result[i].size(); j++)
               cout<<result[i][j]<<" ";
           cout<<" ";
       }
       cout<<endl;
   }

private:
   vector<int> tmp;
   vector<vector<int> > result;
};


int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(3);
    TreeNode* node3 = new TreeNode(14);
    TreeNode* node4 = new TreeNode(5);
    TreeNode* node5 = new TreeNode(6);
    TreeNode* node6 = new TreeNode(7);
    root->left = node1;
    //root->right = node2;
    root->right = NULL;
    node1->left = node3;
    node1->right = node4;
    node4->left = node2;
    node2->left = node5;
    node2->right = node6;
    Solution a;
    cout<<"先序遍历："<<endl;
    a.prePrint(root);
    cout<<"中序遍历："<<endl;
    a.vinPrint(root);
    cout<<"后序遍历："<<endl;
    a.postPrint(root);
    cout<<"层序遍历："<<endl;
    a.levePrint(root);
    cout<<"之字遍历："<<endl;
    a.zPrint(root);
    cout<<"高度为："<<endl;
    cout<<a.depth(root)<<endl;
    a.isBalanced(root);
    a.findWay(root, 17);
    return 0;
}
#endif
