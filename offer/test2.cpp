#include <iostream>
#include <vector>
using namespace std;

//面试题3,数组中查找数字在不在
//class Solution {
//public:
//    bool Find(int target, vector<vector<int> > array) {
//        int col = array[0].size();
//        int row = array.size();
//        int r = 0;
//        int c = col - 1;
//        while(r < row && c >= 0)
//        {
//            if(array[r][c] == target)
//            {
//                return true;
//
//            }
//            else if(array[r][c] < target)
//            {
//                r++;
//
//            }
//            else
//            {
//                c--;
//            }
//
//        }
//        return false;
//    }
//};
//

//面试题四
//数组存储字符串和常量字符串
//int main()
//{
//    char str1[] = "hello world";
//    char str2[] = "hello world";
//    if(str1 == str2)
//    {
//        cout<<"str1 is same as str2"<<endl;
//    }else
//    {
//        cout<<"str1 is not same as str2"<<endl;
//    }
//    const char* str3 = "hello world";
//    const char* str4 = "hello world";
//    if(str3 == str4)
//    {
//        cout<<"str3 is same as str4"<<endl;
//    }else
//    {
//        cout<<"str3 is not same as str4"<<endl;
//    }
//    return 0;
//}

//面试题四
//空格替换
//class Solution {
//public:
//    void replaceSpace(char *str,int length) {
//        if(str == NULL || length == 0)
//        {
//            return;
//        }
//        int space_count = 0;
//        for(int i = 0; i < length; ++i)
//        {
//            if(str[i] == ' ')
//            {
//                space_count++;
//
//            }
//
//        }
//        int new_length = length + space_count * 2;
//        char* p1 = &str[length-1];
//        char* p2 = &str[new_length-1];
//        while(p1 != p2)
//        {
//            if(*p1 == ' ')
//            {
//                p1--;
//                *p2 = '0';
//                *(p2 - 1) = '2';
//                *(p2 - 2) = '%';
//                p2-=3;
//            }
//            *p2 = *p1;
//            p1--;
//            p2--;
//        }
//    }
//};
//
//int main()
//{
//    char str[30] = "we are happy.";
//    cout<<str<<endl;
//    Solution a;
//    a.replaceSpace(str, 14);
//    cout<<str<<endl;
//    return 0;
//}
