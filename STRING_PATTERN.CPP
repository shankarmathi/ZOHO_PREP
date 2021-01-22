#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char arr[100];
    cin>>arr;
    int l = strlen(arr);
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<l-1-i;j++)
        {
            cout<<" ";
        }
        for(int j=0;j<=i;j++){
            cout<<arr[(j+(l/2))%l]<<" ";
        }
        cout<<'\n';
    }
}