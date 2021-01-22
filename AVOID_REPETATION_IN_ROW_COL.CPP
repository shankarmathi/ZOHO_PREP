#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string arr = "";
    char ch = 'a';
    for(int i=0;i<n;i++){
        arr += ch;
        ch++;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n+i;j++)
        {
            cout<<arr[j%n];
        }
        cout<<'\n';
    }
}