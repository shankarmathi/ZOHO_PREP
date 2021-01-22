#include <iostream>

using namespace std;

int reversee(int num)
{
    int ans = 0;
    while(num)
    {
        ans = ans*10 + num%10;
        num = num/10;
    }
    return ans;
}

int main()
{
    int num;
    cin>>num;
    while(num != reversee(num))
    {
        num += reversee(num);
    }
    cout<<num;
}