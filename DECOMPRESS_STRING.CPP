#include <iostream>

using namespace std;

int main()
{
    string arr;
    cin>>arr;
    int i = 0,l = arr.length();
    while(i < l)
    {
        char ch = arr[i++];
        int count = 0;
        while(isdigit(arr[i]))
        {
            count = count*10 + (arr[i++]-'0');
        }
        while (count--)
        {
            cout<<ch;
        }
        
    }
}