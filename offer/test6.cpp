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
#endif
