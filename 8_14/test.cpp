#include <iostream>
using namespace std;
class Solution {
public:
    void replaceSpace(char *str) {
        char arr[] = {0};
        int i = 0;
        char* temp = str;
        while(*temp != '0')
        {
            while(!isspace(*temp))
            {
                arr[i++] = *temp;
                temp++;
            }
            arr[i] = '%';
            arr[i + 1] = '2';
            arr[i + 2] = '0';
            temp++;

        }
        arr[i] = *temp;
        str = arr;
        cout<<str<<endl;
    }
};

int main()
{
    Solution a;
    char str[] = "we are happy";
    a.replaceSpace(str);
}
