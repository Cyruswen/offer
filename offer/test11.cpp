#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <string>
#include <stack>
using namespace std;

#if 0
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
#endif

#if 0
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
        array.insert(array.begin(), oddArray.begin(), oddArray.end());
    }

};
#endif

#if 0
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
        if(k > len)
        {
            return NULL;
        }
        ListNode* fast = pListHead;
        ListNode* slow = pListHead;
        for(size_t i = 0; i < k-1; i++)
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
#endif

#if 0

bool cmp(int a, int b)
{
    return a > b;
}

int main(){
    int arr[] = {5,3,2,6,1,8,7};
    size_t size = sizeof(arr)/sizeof(int);
    vector<int> v(arr, arr+size);
    sort(v.begin(), v.end(), cmp);
    for(size_t i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
#endif

#if 1

struct student
{
public:
    student(int a, int b)
    :_id(a),_age(b)
    {}

public:
    int _id;
    int _age;
};

class cmp
{
public:
    bool operator()(student& a, student& b)
    {
        return a._id > b._id;
    }
};


int main()
{
    /*int arr[] = {4,3,2,6,5,1,9,8};
    size_t size = sizeof(arr)/sizeof(int);
    vector<int> v(arr, arr+size);
    priority_queue<int, vector<int>, cmp> p;
    for(size_t i = 0; i < v.size(); i++)
    {
        p.push(v[i]);
    }*/
    student* a = new student(1, 17);
    student* b = new student(18, 30);
    student* c = new student(9, 8);
    priority_queue<student, vector<student>, cmp> p;
    p.push(*a);
    p.push(*b);
    p.push(*c);
    while(!p.empty())
    {
        cout<<"id="<<p.top()._id<<" "<<"age="<<p.top()._age<<endl;
        p.pop();
    }
    return 0;
}
#endif
