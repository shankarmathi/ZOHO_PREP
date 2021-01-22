#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string arr;
    long long int num;
    cin>>num;
    while (num)
    {
        int x = num%26;
        if(x == 0)
        {
            x = 26;
            num--;
        }
        char ch = x + 64;
        arr = ch + arr;
        num /= 26;
    }
    
    cout<<arr;
}