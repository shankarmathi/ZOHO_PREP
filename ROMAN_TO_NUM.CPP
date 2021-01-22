#include <iostream>

using namespace std;

int getval(char ch)
{
    switch (ch)
    {
    case 'I':
    return 1;
    case 'V':
    return 5;
    case 'X':
    return 10;
    case 'L':
    return 50;
    case 'C':
    return 100;
    case 'D':
    return 500;
    case 'M':
    return 1000;
    }
    return 0;
}

int main()
{
    string arr;
    cin>>arr;
    int ans = 0;
    for(int i=0;arr[i];){
        int x = getval(arr[i]);
        if(arr[i+1])
        {
            int y = getval(arr[i+1]);
            if(x >= y)
            {
                ans += x;
                i++;
            }
            else
            {
                ans += (y-x);
                i += 2;
            }
        }
        else{
            ans += x;
            i++;
        }
    }
    cout<<ans;
}