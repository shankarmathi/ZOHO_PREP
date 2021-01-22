#include <iostream>

using namespace std;

int main()
{
    int n,num;
    cin>>n;
    num = n;
    int arr[n+n-1][n+n-1] = {0};
    int top = 0,bottom = n+n-2,left = 0,right = n+n-2;
    while(1)
    {
        if(left > right)
        {
            break;
        }
        for(int i=left;i<=right;i++)
        {
            arr[top][i] = num;
        }
        top++;
        if(top > bottom)
        {
            break;
        }
        for(int i=top;i<=bottom;i++){
            cout<<1;
            arr[i][right] = num;
        }
        right--;
        if(left > right)
        {
            break;
        }
        for(int i=right;i>=left;i--)
        {
            arr[bottom][i] = num;
        }
        bottom--;
        if(top > bottom)
        {
            break;
        }
        for(int i=bottom;i>=top;i--){
            arr[i][left] = num;
        }
        left++;
        num--;
    }
    cout<<'\n';
    for(int i=0;i<n+n-1;i++)
    {
        for(int j=0;j<n+n-1;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }
}