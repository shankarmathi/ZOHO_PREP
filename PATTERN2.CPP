#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n+1;i++)
    {
        int x = i;
        for(int j=1;j<=n-i+1;j++)
        {
            cout<<x<<" ";
            x += n-j+1;
        }
        cout<<'\n';
    }
}