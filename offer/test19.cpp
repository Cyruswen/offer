#include <iostream>
#include <vector>
using namespace std;

class Sort
{
public:
    int Partation(vector<int>& v, int begin, int end)
    {
        if(end - begin <=1 )
            return begin;
        int left = begin;
        int right = end - 1;
        int tmp = v[right];
        while(left < right)
        {
            while(left < right && v[left] <= tmp)
                left++;
            while(left < right && v[right] >= tmp)
                right--;
            if(left < right)
                swap(v[left], v[right]);
        }
        swap(v[left], v[end-1]);
        return left;
    }

    void _QuickSort(vector<int>& v, int begin, int end)
    {
        if(end - begin <= 1)
            return;
        int mid = Partation(v, begin, end);
        _QuickSort(v, begin, mid);
        _QuickSort(v, mid+1, end);
    }

    void QuickSort(vector<int>& v)
    {
        _QuickSort(v, 0, v.size());
    }
};

int main()
{
    Sort sort;
    int arr[] = {1,2,4,3,5,8,7,5};
    vector<int> v(arr, arr+8);
    sort.QuickSort(v);
    for(size_t i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
