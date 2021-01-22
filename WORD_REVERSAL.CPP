#include <iostream>
#include <cstring>

using namespace std;

string rev(string arr,int i,int j,string brr,string crr)
{
    if(i == j)
    {
        return brr + crr;
    }
    if(arr[i] != ' ')
    {
        return rev(arr,i+1,j,brr+arr[i],crr);
    }
    else
    {
        return rev(arr,i+1,j,"",brr+crr);
    }
    
}

int main()
{
    string arr;
    getline(cin,arr);
    cout<<rev(arr,0,arr.length()-1,"","");    
}