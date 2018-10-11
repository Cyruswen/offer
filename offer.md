### 剑指offer

1. **求连续子数组的最大和问题**

思路：一个子序列加上a的和比a还小,我们就可以丢弃这个子序列，从a重新开始。

设置一个最大和maxsum,设置一个循环和cursum, 连续求和，当cursum小于第n项，把第n项的值赋给cursum, 当cursum > maxsum时，令maxsum=cursum;

```c++
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int maxsum = array[0];
        int cursum = array[0];
        for(int i = 1; i < array.size(); i++)
        {
            cursum += array[i];
            if(cursum < array[i])
                cursum = array[i];
            if(cursum > maxsum)
                maxsum = cursum;
        }
        return maxsum;
    }
};
```

2. **数据流的中位数问题**

思路：可以建一个大堆和一个小堆，小堆保存数据流的较大的部分，大堆保存数据流较小的部分，我们保证大小堆之间的差值在1以内（大堆比小堆高1，或者相等）这样如果时奇数大小的数据流大堆的堆顶就是中位数，如果是偶数个数据流，两个堆的堆顶之和除2就是中位数。

```C++
class Solution {
public:
    priority_queue<int, vector<int>, less<int>> q;
    priority_queue<int, vector<int>, greater<int>> p;
    void Insert(int num)
    {
        if(q.empty() || num > q.top())
            p.push(num);
        else
            q.push(num);
        if(q.size() == (p.size() + 2))
        {
            p.push(q.top());
            q.pop();
        }
        if(p.size() == (q.size() + 1))
        {
            q.push(p.top());
            p.pop();
        }
    }

    double GetMedian()
    { 
        if(q.size() == p.size())
            return (p.top()+q.top())/2.0;
        else
            return q.top();
    }

};
```

3. **左旋字符串**

思路：

方法一：将要旋转的字符串存到新的字符串里，删除调要旋转的部分，将两个字符串相加得到结果。

```c++
class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(n < 0 || str.size() == 0)
            return "";
        int step = n % str.size();
        if(step == 0)
            return str;
        string tmp = str.substr(0, step);
        str.erase(0, n);
        return (str+tmp);
    }
};
```

方法二：将待旋转的字符串分为两部分，先逆置左半部分，再逆置右半部分，最后整体逆置。



4.**不用加减乘除做加法**

思路：不带进位相加的和再加上带进位的和，得到结果。

```c++
class Solution {
public:
    int Add(int num1, int num2)
    {
        return num2?Add(num1^num2, (num1&num2)<<1):num1;
    }
};
```



5. **把字符串转换为整数**

思路：先将前面的空格去掉，再判断正负，再循环求结果。

```C++
class Solution {
public:
	int StrToInt(string str) {
		int i = 0;
		int flag = 0;
		int result = 0;
		while (str[i] == ' ')
			i++;
		if (str[i] == '-')
		{
			flag = 1;
			i++;
		}
		if (str[i] == '+')
			i++;
		while (str[i] != '\0')
		{
			if (str[i] < '0' || str[i] > '9')
				return 0;
			result = result * 10 + (str[i] - '0');
			i++;
		}
		return flag == 1 ? (-1)*result : result;
	}
};
```

6. **数组中只出现一次的数字。**

思路：

使用map统计数组里元素出现的次数。遍历map判断哪些出现了一次。输出结果。

```C++
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        map<int, int> m;
        vector<int> result;
        for(size_t i = 0; i < data.size(); i++)
        {
            ++m[data[i]];
        }
        for(size_t j = 0; j < data.size(); j++)
        {
            if(m[data[j]] == 1)
            {
                result.push_back(data[j]);
            }
        }
        *num1 = result[0];
        *num2 = result[1];
    }
};
```

7. 旋转字符串

思路：

方法一：按照空格逐=逐个翻转字符串，再整体翻转字符串。

```c++
#include <iostream>
#include <string>
using namespace std;

/*class Solution{
public:
	string LeftRotateString(string str, int n) {
		if (n < 0 || str.size() == 0)
			return "";
		int step = n % str.size();
		string tmp = str.substr(0, step);
		str.erase(0, n);
		return (str + tmp);
	}
};

int main()
{
	Solution s;
	string str = "abcdefg";
	string result;
	result = s.LeftRotateString(str, 7);
	cout << result << endl;
	system("pause");
	return 0;
}*/

class Solution {
public:
	string ReverseSentence(string str) {
		if (str.size() == 0)
			return "";
		size_t begin = 0;
		size_t end = 0;
		size_t i = 0;
		for (; i < str.size(); i++)
		{
			if (isspace(str[i]))
			{
				end = i - 1;
				while (begin < end)
					swap(str[begin++], str[end--]);
				begin = i + 1;
			}
		}
		begin = 0;
		end = str.size() - 1;
		while (begin < end)
			swap(str[begin++], str[end--]);
		return str;
	}
};

int main()
{
	string s = "student. a am I";
	Solution a;
	string result = a.ReverseSentence(s);
	cout << result << endl;
	system("pause");
	return 0;
}
```

思路二：

用一个临时字符串存单词每次将空格加单词重新拼接，即可得到逆置后的字符串。

```C++
class Solution {
public:
    string ReverseSentence(string str) {
        if(str.size() == 0)
            return "";
        string res = "";
        string tmp = "";
        for(size_t i = 0; i < str.size(); i++)
        {
            if(str[i] == ' ')
            {
                res = " "+tmp+res;
                tmp = "";
            }
            else{
                tmp += str[i];
            }
        }
        res = tmp + res;
        return res;
    }
};
```



8. 字符串替换。

   思路一：运用递归的思想，递归到最后一个节点，再把每个节点的值存到vector里返回。

   ```c++
   class Solution {
   public:
       vector<int> v;
   public:
       vector<int> printListFromTailToHead(ListNode* head) {
           if(head == NULL)
               return v;
           printListFromTailToHead(head->next);
           v.push_back(head->val);
           return v;
       }
   };
   ```

   思路二：先遍历一遍统计空格出现的次数，计算新的长度。两个指针一个指向新的末尾，一个指向旧的末尾。从后往前复制，遇到空格后面替换成%20。直到后面的指针追上前面的指针。

   ```c++
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
   
   ```

9. 重建二叉树的问题。

   思路：先序遍历的第一个节点就是根节点，在中序遍历中找到这个节点，节点左边就是左子树，右边就是右子树。将左子树先序，中序分别保存，右子树的先序，中序分别保存，递归构建二叉树。

   ```c++
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
   
   ```

10. 两个栈实现一个队列

    思路：每次入队列都放到栈1，出队列的时候判断栈2是否为空，如果为空将栈1的所有元素出栈入到栈2，再将栈2出栈。

    ```c++
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
    
    ```

11. 旋转数组里最小的值。

    思路一：排序 性能挫 O(n^2)

    思路二：从前往后找第一个小于第一个数字的值，就是最小值。 性能挫O(n^2)

    ```c++
    class Solution {
    public:
        int minNumberInRotateArray(vector<int> rotateArray) {
            int key = rotateArray[0];
            int i = 1;
            while(key <= rotateArray[i++]);
            return rotateArray[i-1];
        }
    };
    ```

    思路三: 二分法 时间复杂度O(logn)。

    

    12. 变态青蛙跳台阶

    思路：第一下跳一下还有f(n-1), 第一下跳两个还有f(n - 2), 第一下跳三个还有f(n - 3).....

    所以 f(n) = f(n - 1) + f(n - 2) + f(n - 3) + ... + f(0)

    ​	f(n - 1) = f(n - 2) + f(n - 3) + ... + f(0）

    所以 f(n) = 2*f(n - 1)

    ```C++
    class Solution {
    public:
        int jumpFloorII(int number) {
            if(number <= 2)
            {
                return number;
            }
            int tolNum = 1;
            for(int i = 2; i <= number; i++)
            {
               tolNum = tolNum * 2;
            }
            return tolNum;
        }
    };
    ```

    

    优化：

    ```C++
    class Solution {
    public:
        int jumpFloorII(int number) {
            if(number < 1)
            	return 0;
            return (1<<(n-1));
        }
    };
    ```

    

12. 二进制中一的个数

    思路：设置无符号标志位1，将1左移直至为零，每次按位与目标数，如果不为0，则说明对应位为1，计数器加一。

    ```C++
    class Solution {
    public:
         int  NumberOf1(int n) {
             int count = 0;
             unsigned int flag = 1;
             while(flag)
             {
                 if(n & flag)
                     count++;
                 flag = flag<<1;
             }
             return count;
         }
    };
    ```

13. 数值的整数次方

    思路：首先0不能做除数， 所以0的负数次方不可以，另外0的0次方无意义,还要注意的是浮点数不能直接比较。可以写出如下代码。

    ```c++
    class Solution {
    public:
        bool compare(double num, double comparedNum)
        {
            if((num - comparedNum) < 0.00000001 && (comparedNum - num) > -0.00000001)
            {
                return true;
            }
            return false;
        }
    
        double _power(double base, int exponent)
        {
            double result = 1.0;
            for(int i = 0; i < exponent; i++)
            {
                result *= base;
            }
            return result;
        }
    
        double Power(double base, int exponent) {
            if(( compare(base, 0.0) && exponent < 0 ) || ( compare(base, 0.0) && exponent == 0))
            {
                errorInput = true;
                return 0.0;
            }
            double result;
            if(exponent < 0)
            {
                int newExponent = abs(exponent);
                result = 1/_power(base, newExponent);
            }else
            {
                result = _power(base, exponent);
            }
            return result;
        }
    
    private:
        bool errorInput = false;
    };
    
    ```

14. 奇数位于前面偶数位于后面，不改变相对位置。

    思路：新建两个数组分别保存奇数和偶数。

    ```c++
    class Solution {
    public:
        void reOrderArray(vector<int> &array) {
            if(array.size() == 0)
            {
                return;
            }
            vector<int> oddArray;
            vector<int> evenArray;
            for(size_t i = 0; i < array.size(); i++)
            {
                if(array[i] % 2 == 0)
                {
                    evenArray.push_back(array[i]);
                }
                else
                {
                    oddArray.push_back(array[i]);
                }
            }
            oddArray.insert(oddArray.end(),  evenArray.begin(), evenArray.end());
            array.clear();
            array.insert(array.begin(),oddArray.begin(), oddArray.end());
        }
    
    };
    ```

    思路二：

    类似冒泡排序

    ```c++
    class Solution {
    public:
        void reOrderArray(vector<int> &array) {
            if(array.size() == 0)
                return;
            for(size_t i = 0; i < array.size(); i++)
            {
                for(size_t j = array.size()-1; j > i; j--)
                {
                    if(array[j]%2 == 1 && array[j - 1]%2 == 0)
                    {
                        swap(array[j], array[j - 1]);
                    }
                }
            }
        }
    };
    ```

15. 求链表的倒数第k个节点

    思路：快慢指针的问题，快指针先走k-1步，之后直到快指针指向尾快慢指针都走一步，最后慢指针指向的就是倒数第k个节点, 需要注意的是k的值超出链表长度和倒数第0个节点。

    ```c++
    class Solution {
    public:
        ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
            if(pListHead == NULL)
            {
                return NULL;
            }
            ListNode* cur = pListHead;
            size_t len = 0;
            while(cur != NULL)
            {
                len++;
                cur = cur->next;
            }
            if(k > len || k <= 0)
            {
                return NULL;
            }
            ListNode* fast = pListHead;
            ListNode* slow = pListHead;
            for(size_t i = 1; i < k; i++)
            {
                fast = fast->next;
            }
            while(fast->next != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
    
    };
    
    ```

    思路二：栈将节点指针存下来再出栈k - 1个元素，栈顶就是所求值。

    ```C++
    class Solution {
    public:
        ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
            if(pListHead == NULL)
                return NULL;
            ListNode* cur = pListHead;
            while(cur != NULL)
            {
                len++;
                cur = cur->next;
            }
            if(k > len || k <= 0)
                return NULL;
            stack<ListNode*> s;
            cur = pListHead;
            while(cur != NULL)
            {  
                s.push(cur);
                cur = cur->next;
            }
            for(size_t i = 1; i < k; i++)
            {
                s.pop();
            }
            return s.top();
        }
    private:
        size_t len = 0;
    };
    ```

16. 逆置单链表

    思路：每次将第一个节点的下一个节点放到开头知道第一个节点的下个节点为空。

    ```c++
    class Solution {
    public:
        ListNode* ReverseList(ListNode* pHead) {
            if(pHead == NULL)
                return NULL;
            ListNode* cur = pHead;
            ListNode* Next = NULL;
            while(cur->next != NULL)
            {
                Next = cur->next;
                cur->next = Next->next;
                Next->next = pHead;
                pHead = Next;
            }
            return pHead;
        }
    };
    ```

17. 合并两个有序链表

    思路一：不开辟空间的方法，直接用旧的链表。

    ```c++
    class Solution {
    public:
            ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
            {
                if(pHead1 == NULL && pHead2 != NULL)
                    return pHead2;
                else if(pHead1 != NULL && pHead2 == NULL)
                    return pHead1;
                else if(pHead1 == NULL && pHead2 == NULL)
                    return NULL;
                ListNode* newHead;
                ListNode* cur1 = pHead1;
                ListNode* cur2 = pHead2;
                if(cur1->val >= cur2->val)
                {     
                    newHead = cur2;
                    cur2 = cur2->next;
                }
                else
                { 
                    newHead = cur1;
                    cur1 = cur1->next;
                }
                ListNode* cur3 = newHead;
                while(cur1 != NULL && cur2 != NULL)
                {
                    if(cur1->val >= cur2->val)
                    {
                        cur3->next = cur2;
                        cur3 = cur3->next;
                        cur2 = cur2->next;
                    }
                    else
                    {
                        cur3->next = cur1;
                        cur3 = cur3->next;
                        cur1 = cur1->next;
                    }
                }
                if(cur1 == NULL)
                    cur3->next = cur2;
                else
                    cur3->next = cur1;
                return newHead;
            }
    };
    ```

    

    思路二：开辟新的空间

    ```c++
    
    class Solution {
    public:
        ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
        {
            if(pHead1 == NULL && pHead2 != NULL)
                return pHead2;
            else if(pHead2 == NULL && pHead1 != NULL)
                return pHead1;
            else if(pHead1 == NULL && pHead2 == NULL)
                return NULL;
            ListNode* cur1 = pHead1;
            ListNode* cur2 = pHead2;
            ListNode* newPhead = new ListNode(0);
            ListNode* cur3 = newPhead;
            while(cur1 != NULL && cur2 != NULL)
            {
                if(cur1->val > cur2->val)
                {
                    cur3->next = new ListNode(cur2->val);
                    cur3 = cur3->next;
                    cur2 = cur2->next;
                }
                else
                {
                    cur3->next = new ListNode(cur1->val);
                    cur3 = cur3->next;
                    cur1 = cur1->next;
                }
            }
            if(cur1 == NULL)
            {
                cur3->next = cur2;
            }
            else if(cur2 == NULL)
            {
                cur3->next = cur1;
            }
            ListNode* tmp = newPhead;
            newPhead = newPhead->next;
            delete tmp;
            return newPhead;
        }
    };
    ```

18. 排序之后相邻两数最大差值

    类似于桶排序的思想，建三个数组分别保存最大值最小值和是否有数据，然后求相邻桶之间的最大值即可。

19. 顺时针打印矩阵

    思路：知道左上角和右下角就可以打印一圈，然后右下角--， 左上角++，直到左上角的横或纵有一个大于右下的横纵坐标,需要考虑一个长方形的情况，也就是打印到里面成了一行或者一列。

    ```c++
    class Solution {
    public:
        void _printMatrix(vector<vector<int> > matrix, int ar, int ac, int br, int bc, vector<int>& result)
        {
            if(ar == br)
                for(int i = ac; i <= bc; i++)
                    result.push_back(matrix[ar][i]);
            else if(ac == bc)
                for(int i = ar; i <= br; i++)
                    result.push_back(matrix[i][ac]);
            else{
                for(int i = ac; i <= bc; i++)
                    result.push_back(matrix[ar][i]);
                for(int i = ar + 1; i <= br; i++)
                    result.push_back(matrix[i][bc]);
                for(int i = bc - 1; i >= ac; i--)
                    result.push_back(matrix[br][i]);
                for(int i = br - 1; i > ar; i--)
                    result.push_back(matrix[i][ac]);
            }
        }
        vector<int> printMatrix(vector<vector<int> > matrix) {
            int ar = 0;
            int ac = 0;
            int br = matrix.size()-1;
            int bc = matrix[0].size()-1;
            vector<int> result;
            while(ar <= br && ac <= bc)
            {
                _printMatrix(matrix, ar++, ac++, br--, bc--, result);
            }
            return result;
        }
    };
    ```

20. 顺时针90度旋转数组。

    思路：先交换外面一圈，再交换里面。

    ```c++
    void _orderPrint(vector<vector<int> >& v, int ar, int ac, int br, int bc)
    {
    	int times = bc - ac;
    	for (int i = 0; i < times; i++)
    	{
    		int tmp = v[ar][ac + i];
    		v[ar][ac + i] = v[br - i][ac];
    		v[br - i][ac] = v[br][bc - i];
    		v[br][bc - i] = v[ar + i][bc];
    		v[ar + i][bc] = tmp;
    	}
    }
    
    void orderPrint(vector<vector<int> >& v)
    {
    	int br = v.size() - 1;
    	int bc = v[0].size() - 1;
    	int ar = 0;
    	int ac = 0;
    	while (ar < br && ac < bc)
    	{
    		_orderPrint(v, ar++, ac++, br--, bc--);
    	}
    }
    
    int main()
    {
    	int arr[] = { 1,2,3 };
    	int arr2[] = { 4,5,6 };
    	int arr3[] = { 7,8,9 };
    	vector<int> v1(arr, arr + 3);
    	vector<int> v2(arr2, arr + 3);
    	vector<int> v3(arr3, arr + 3);
    	vector<vector<int> > v;
    	v.push_back(v1);
    	v.push_back(v2);
    	v.push_back(v3);
    
    	for (size_t i = 0; i < v.size(); i++)
    	{
    		for (size_t j = 0; j < v[0].size(); j++)
    			cout << v[i][j] << " ";
    		cout << endl;
    	}
    	cout<<endl;
    	orderPrint(v);
    	for (size_t i = 0; i < v.size(); i++)
    	{
    		for (size_t j = 0; j < v[0].size(); j++)
    			cout << v[i][j] << " ";
    		cout << endl;
    	}
    	system("pause");
    	return 0;
    }
    ```

21. 之字型打印矩阵

    思路：两个指针a和b，当b指向最右端继续向下指，当a指向最下端继续向右指，知道到达最后。

    ```C++
    void _zPrint(vector<vector<int> > v, int ar, int ac, int br, int bc, bool isUp)
    {
    	if (isUp)
    		while (ar >= br)
    			cout << v[ar--][ac++] << " ";
    	else
    		while (br <= ar)
    			cout << v[br++][bc--] << " ";
    }
    
    void zPrint(vector<vector<int> > v)
    {
    	int ar = 0;
    	int ac = 0;
    	int br = 0;
    	int bc = 0;
    	int lastr = v.size() - 1;
    	int lastc = v[0].size() - 1;
    	bool isUp = false;
    	while (br <= lastr)
    	{
    		_zPrint(v, ar, ac, br, bc, isUp);
    		ac = (ar == lastr ? ac + 1 : ac);
    		ar = (ar == lastr ? ar : ar + 1);
    		br = (bc == lastc ? br + 1 : br);
    		bc = (bc == lastc ? bc : bc + 1);
    		isUp = !isUp;
    	}
    }
    ```

22. 树的遍历

    ```c++
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
    ```

23. 二叉树的遍历，非递归版。

前序遍历：先将根节点入栈，每次出栈判断出栈元素的右子树是否为空，不为空入栈。再判断左子树是否为空，不为空，入栈。终止条件   while (!stack.empty())。

```c++
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
```

中序遍历：每次判断当前节点是否为空，不为空入栈，指针左移。为空，出栈，指针右移。

终止条件：while ( !stack.empty() || root != NULL)

```c++
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
```

后序遍历：仿照前面先序遍历的方法，只是先入左孩子再入右孩子，这样得到的顺序是中右左。将结果再入栈就得到了左右中的遍历顺序，即后序遍历。

```c++
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
```

24. 判断一个树是否为另一个树的子树。

思路：递归套递归。先判断root1和root2指向的val是否相等，如果相等，以这两个节点为跟进行比较。如果比较结果是不相等，递归从root1的左子树继续找，如果还不相等，递归从root1的右孩子继续找。

比较函数：如果root2==NULL, 说明找到了。如果root2  != NULL && root1 == NULL 说明不相等。如果中途节点的val不相等，表示不相等。递归比较左子树，右子树。

```c++
class Solution {
public:

        bool _HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
        {
            if(pRoot2 == NULL)
                return true;
            if(pRoot1 == NULL)
                return false;
            if(pRoot1->val != pRoot2->val)
                return false;
            return (_HasSubtree(pRoot1->left, pRoot2->left)&&_HasSubtree(pRoot1->right, pRoot2->right));
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
                    result = HasSubtree(pRoot1->left, pRoot2);
                }
                if(!result)
                {
                    result = HasSubtree(pRoot1->right, pRoot2);
                }
            }
            return result;
        }
};
```

25. 树的z形遍历

思路：两个栈，一个从左往右，一个从右往左入，谁空入谁，直到两个都空。

```C++
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
```

26. 包含min函数的栈

    思路：设置两个栈，其中一个栈存元素，一个栈存最小值。每次入栈，如果stack2为空，stack1和stack2同时入栈。如果stack2不为空,判断入栈元素小于stack2栈顶元素，两个栈同时入栈。否则只如stack1.

    出栈的时候，判断两栈顶是否相等，如果相等，同时出栈，否则只出stack1;

    ```c++
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
    ```

27. 搜索二叉树的后序遍历。

    思路：二叉搜索树的后序遍历最后一个数是根节点，从前往后遍历前面一定小于它，后面部分一定都大于它。

    那么从头到尾走一遍，如果每次i都能到达最后一个节点，那么这个序列就是二叉搜索树的后序遍历结果。

    ```c++
    class Solution {
    public:
        bool VerifySquenceOfBST(vector<int> sequence) {
            int size = sequence.size();
            if(size == 0)
                return false;
            while(--size)
            {
                int i = 0;
                while(sequence[i++] < sequence[size]);
                while(sequence[i++] > sequence[size]);
                if(i < size)
                    return false;
            }
            return true;
        }
    };            
    ```

28. 二叉树的层序遍历

    思路，一个队列，先将头节点入队列，然后出队列，左不为空，入左。右不为空，入右。

    ```c++
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
    ```

29. 二叉树中和为某一值的路径

    思路：递归遍历树的左右子树。期望值改为原期望值减去当前节点值。

    ```c++
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
    ```

30. 二叉搜索树转化为排序的双向链表。

    思路：中序遍历

    ```c++
    //递归版
    class Solution {
    public:
        void _Convert(TreeNode* pRootOfTree)
        {
            if(pRootOfTree == NULL)
                return;
            _Convert(pRootOfTree->left);
            v.push_back(pRootOfTree);
            _Convert(pRootOfTree->right);
        }
        
        TreeNode* Convert(TreeNode* pRootOfTree)
        {
            if(pRootOfTree == NULL)
                return NULL;
            _Convert(pRootOfTree);
            TreeNode* root = v[0];
            TreeNode* cur = root;
            for(size_t i = 1; i < v.size(); i++)
            {
                cur->right = v[i];
                v[i]->left = cur;
                cur = cur->right;
            }
            return root;
        }
    private:
        vector<TreeNode*> v;
    };
    
    //非递归版
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
    ```

31. 和为sum的两个数字。存在多对，按乘积最小输出。

    思路：头和尾两个指针 begin, end   离的越远乘积越小

    array[begin] + array[end] == sum     找到

    array[begin] + array[end] > sum        end--

    array[begin] + array[end] < sum        begin++

    ```C++
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
    ```

    32. 