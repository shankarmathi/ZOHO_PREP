#include <iostream>

using namespace std;

struct pairs
{
    int num;
    int fact;
};

/*
1 15
3 5
*/

int factorial(int num)
{
    int ans = 0;
    for(int i=1;i*i<=num;i++)
    {
        if(num%i == 0)
        {
            if(num/i == i){
                ans += 1;
            } 
            else{
                ans += 2;
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    struct pairs *p = new pairs[n];
    for(int i=0;i<n;i++)
    {
        cin>>p[i].num;
        int x = factorial(p[i].num);
        p[i].fact = x;
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(p[j].fact < p[j+1].fact)
            {
                pairs q = p[j];
                p[j] = p[j+1];
                p[j+1] = q;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<p[i].num<<" ";
    }
}