#include <iostream>
#include <cmath>
using namespace std;
//青蛙跳台阶（想跳几级跳几级那种）
#if 0
class Solution {
public:
    int jumpFloor(int number) {
        if(number <= 2)
        {
            return number;
        }
        int f0 = 0;
        int f1 = 1;
        int tolNum = 0;
        for(int i = 1; i <= number; i++)
        {
            tolNum = f0 + f1;
            f0 = f1;
            f1 = tolNum;
        }
        return tolNum;
    }
};

//求浮点数的整数次方
//需要注意的是浮点数不能直接比较大小
//if(b - a > -0.0000001 && b - a < 0.0000001)
//   return true;


class Solution {
public:
    bool comPare(double num, double comParedNum)
    {
        if(num - comParedNum < 0.000001 && num - comParedNum > -0.000001)
        {
            return true;
        }
        else{
            return false;
        }
    }

    double _Power(double base, int exponent)
    {
        int result = 1.0;
        for(int i = 0; i < exponent; i++)
        {
            result *= base;
        }
        return result;
    }

    double Power(double base, int exponent) {
        errorInput = false;
        if(comPare(base, 0.0) && exponent < 0)
        {
            errorInput = true;
            return 0.0;
        }
        double result = 1.0;
        if(exponent < 0)
        {
            unsigned int ret = abs(exponent);
            result = _Power(base, ret);
            return 1/result;
        }
        else
        {
            result = _Power(base, exponent);
            return result;
        }
    }
private:
    bool errorInput = false;
};

//将数组的奇数放在前部分，偶数放在后部分，顺序不变，解法一。
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int size = array.size();
        int left = 0;
        int right = size - 1;
        int oddCount = 0;
        vector<int> new_array(size, 0);
        int index = 0;
        for(int i = 0; i < size; i++)
        {
            if(array[i] % 2 != 0)
            {
                oddCount++;
            }
        }
        for(int j = 0; j < size; j++)
        {
            if(array[j] % 2 != 0)
            {
                new_array[index++] = array[j];

            }
            else
            {
                new_array[oddCount++] = array[j];
            }
        }
        for(int m = 0; m < size; m++)
        {
            array[m] = new_array[m];
        }
    }
};
#endif
