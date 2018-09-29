#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int arr[] = {1,2,3,4,4,5,6,8,8,8,8,8,8};
    size_t size = sizeof(arr)/sizeof(int);
    vector<int> v(arr, arr+size);
    for(size_t i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    vector<int>::iterator it = unique(v.begin(), v.end());
    v.erase(it, v.end());
    for(size_t i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
