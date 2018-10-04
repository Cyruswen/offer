#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <queue>
using namespace std;

#if 0
//顺时针打印矩阵

void _orderPrint(vector<vector<int> > v, int ar, int ac, int dr, int dc)
{
    for(int i = ac; i <= dc; i++)
    {
        cout<<v[ar][i]<<" ";
    }
    for(int i = ar+1; i <= dr; i++)
    {
        cout<<v[i][dc]<<" "; 
    }
    for(int i = dc - 1; i >= ac; i--)
    {
        cout<<v[dr][i]<<" ";
    }
    for(int i = dr - 1; i > ar; i--)
    {
        cout<<v[i][ac]<<" ";
    }
    cout<<endl;
}

void orderPrint(vector<vector<int> > v)
{
    int dr = v.size()-1;
    int dc = v[0].size()-1;
    int ar = 0;
    int ac = 0;
    while(dr >= ar && dc >= ac)
    {
        _orderPrint(v, ar++, ac++, dr--, dc--);
    }
}

int main()
{
    int arr[] = {1,2,3,4,5};
    vector<int> v(arr, arr+5);
    vector<vector<int> > v2;
    v2.push_back(v);
    v2.push_back(v);
    v2.push_back(v);
    v2.push_back(v);
    v2.push_back(v);
    orderPrint(v2);
    return 0;
}
#endif

#if 0
//旋转数组


void _orderPrint(vector<vector<int> >& v, int ar, int ac, int br, int bc)
{
    int times = bc - ac;
    for(int i = 0; i < times; i++)
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
    int br = v.size()-1;
    int bc = v[0].size()-1;
    int ar = 0;
    int ac = 0;
    while(ar < br && ac < bc)
    {
        _orderPrint(v, ar++, ac++, br--, bc--);
    }
}

int main()
{
    int arr[] = {1,2,3};
    int arr2[] = {4,5,6};
    int arr3[] = {7,8,9};
    vector<int> v1(arr, arr+3);
    vector<int> v2(arr2, arr+3);
    vector<int> v3(arr3, arr+3);
    vector<vector<int> > v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    for(size_t i = 0; i < v.size(); i++)
    {
        for(size_t j = 0; j < v[0].size(); j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }

    orderPrint(v);
    for(size_t i = 0; i < v.size(); i++)
    {
        for(size_t j = 0; j < v[0].size(); j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
#endif

#if 0

void _zPrint(vector<vector<int> > v, int ar, int ac, int br, int bc, bool isUp)
{
    if(isUp)
        while(ar >=  br)
            cout<<v[ar--][ac++]<<" ";
    else
        while(br <= ar)
            cout<<v[br++][bc--];
}

void zPrint(vector<vector<int> > v)
{
    int ar = 0;
    int ac = 0;
    int br = 0;
    int bc = 0;
    int lastr = v.size()-1;
    int lastc = v[0].size()-1;
    bool isUp = false;
    while(ar != lastr)
    {
        _zPrint(v,ar ,ac ,br ,bc , isUp);
        ar = (ar == lastr ? ar : ar+1);
        ac = (ar == lastr ? ac+1 : ac);
        br = (bc == lastc ? br+1 : br);
        bc = (bc == lastc ? bc : bc+1);
        isUp = !isUp;
    }
}

int main()
{
    int arr[] = {1,2,3};
    int arr2[] = {4,5,6};
    int arr3[] = {7,8,9};
    vector<int> v1(arr, arr+3);
    vector<int> v2(arr2, arr+3);
    vector<int> v3(arr3, arr+3);
    vector<vector<int> > v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    for(size_t i = 0; i < v.size(); i++)
    {
        for(size_t j = 0; j < v[0].size(); j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
    zPrint(v);
    return 0;
}
#endif

#if 1
class Solution {
public:
    void _printMatrix(vector<vector<int> > matrix, int ar, int ac, int br, int bc, vector<int>& result)
    {
        for(int i = ac; i <= bc; i++)
            result.push_back(matrix[ar][i]);
        for(int i = ar + 1; i <= br; i++)
            result.push_back(matrix[i][bc]);
        for(int i = bc - 1; i >= ac; i--)
            result.push_back(matrix[br][i]);
        for(int i = br - 1; i > ar; i--)
            result.push_back(matrix[i][ac]);
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

int main()
{
    int arr[] = {1,2,3};
    int arr2[] = {4,5,6};
    int arr3[] = {7,8,9};
    vector<int> v1(arr, arr+3);
    vector<int> v2(arr2, arr+3);
    vector<int> v3(arr3, arr+3);
    vector<vector<int> > v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    for(size_t i = 0; i < v.size(); i++)
    {
        for(size_t j = 0; j < v[0].size(); j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
    Solution a;
    vector<int> vv = a.printMatrix(v);
    for(size_t i = 0; i < vv.size(); i++)
        cout<<vv[i]<<" ";
    cout<<endl;
    return 0;
}
#endif
