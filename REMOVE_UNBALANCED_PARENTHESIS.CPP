#include <iostream>

using namespace std;

struct p  
{
    char bracket;
    int index;
};


int main()
{
    string arr;
    cin>>arr;
    int x = 0,l = arr.length(),top = -1;
    struct p stack[l];
    struct p unbalance[l];
    for(int i=0;i<l;i++)
    {
        if(arr[i] == '(')
        {
            stack[++top] = {'(',i};
        }
        else{
            if(arr[i] == ')')
            {
                if(top == -1){
                    unbalance [x++] = {')',i};
                }
                else{
                    top--;
                }
            }
        }
    }
    for(int i=0;i<x;i++){
        arr[unbalance[i].index] = '*';
    }
    for(int i=0;i<=top;i++)
    {
        arr[stack[i].index] = '*';
    }
    for(int i=0;i<l;i++)
    {
        if(i != '*')
        {
            cout<<arr[i];
        }
    }
}