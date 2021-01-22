#include <iostream>

using namespace std;

int main()
{
    string arr,brr;
    cin>>arr>>brr;
    int i = 0,j = 0,l1 = arr.length(),l2 = brr.length();
    while(i<l1 && j<l2)
    {
        if(arr[i] != brr[j]){
            cout<<arr[i]<<","<<brr[j]<<" ";
        }
        i++;
        j++;
    }
}