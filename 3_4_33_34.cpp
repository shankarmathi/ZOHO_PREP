#include <iostream>
#include <vector>

using namespace std;

int main()
{
    unsigned long long int n;
    cin>>n;
    unsigned long long int arr[n];
    arr[0] = 3;
    arr[1] = 4;
    unsigned long long int i = 2,j = 0,s = 0,e = 1;
    while(i <= n)
    {
        for(j=s;j<=e && i <= n;j++)
        {
            arr[i++] = arr[j]*10LL + 3;
            arr[i++] = arr[j]*10LL + 4;
        }
        s = e + 1;
        e = i - 1;
    }
    cout<<arr[n-1];
}