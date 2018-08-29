#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#if 0
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int size = rotateArray.size();
        if(size == 0)
        {
            return 0;
        }
        int beg = 0;
        int end = size - 1;
        int mid = 0;
        while(rotateArray[beg] >= rotateArray[end])
        {
            if(end - beg == 1)
            {
                mid = end;
                break;
            }
            mid = (beg + end)/2;
            if(rotateArray[beg] == rotateArray[end] && rotateArray[beg] == rotateArray[mid])
            {
                return getMin(rotateArray);
            }
            else if(rotateArray[mid] > rotateArray[beg])
            {
                beg = mid;
            }
            else
            {
                end = mid;
            }
        }
        return rotateArray[mid];

    }
    int getMin(vector<int> rotateArray)
    {
        return *min_element(rotateArray.begin(), rotateArray.end());
    }
};

int main()
{
    vector<int> rotateArray;
    rotateArray.push_back(1);
    rotateArray.push_back(1);
    rotateArray.push_back(1);
    rotateArray.push_back(0);
    rotateArray.push_back(1);
    Solution s;
    int minnum = s.minNumberInRotateArray(rotateArray);
    cout<<minnum<<endl;
    return 0;
}
#endif
int fibonacii(int n)
{
    if(n <= 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    return fibonacii(n - 1) + fibonacii(n - 2);
}

int main()
{
    int n = fibonacii(2);
    cout<<n<<endl;
    return 0;
}
