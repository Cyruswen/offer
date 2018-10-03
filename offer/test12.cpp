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
