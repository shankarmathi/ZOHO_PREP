#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin>>n;
    int mid = n/2;
    if(n%2)
    {
        m = mid+1;
    }
    else
    {
        m = mid;
    }
    for(int i=-mid;i<=mid;i++){
        if(i!=0)
        {
            for(int j=-mid;j<=mid;j++){
                if(j != 0)
                {
                    cout<<max(abs(i),abs(j))+m<<" ";
                }
            }
            cout<<'\n';
        }
    }
}