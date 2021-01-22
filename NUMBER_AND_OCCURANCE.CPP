#include <iostream>

using namespace std;

int main()
{
    int n,i,j,k=0,num;
    cin>>n;
    int *arr = new int[n];
    int *hash = new int[n];
    for(i=0;i<n;i++)
    {
        cin>>num;
        int f = 0;
        for(j=0;j<k;j++){
            if(arr[j] == num)
            {
                f = 1;
                hash[j]++;
            }
        }
        if(f == 0)
        {
            arr[k] = num;
            hash[k] = 1;
            k++;
        }
    }
    for(int i=0;i<k;i++){
        cout<<arr[i]<<" "<<hash[i]<<'\n';
    }
}