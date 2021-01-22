#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int n,i,j,k,temp = INT_MIN;
    cin>>n;
    int *arr = new int[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>k;
    for(i=0;i<=n-k;i++){
        int t = arr[i];
        for(j=i+1;j<i+k;j++){
            t = max(t,arr[j]);
        }
        cout<<t<<' ';
    }
}