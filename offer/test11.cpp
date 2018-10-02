#include <iostream>
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
