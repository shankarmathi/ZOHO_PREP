#include <iostream>

using namespace std;

int main()
{
    string arr,brr;
    cin>>arr>>brr;
    int l1 = arr.length(),l2 = brr.length();
    if(l2 > l1)
    {
        cout<<-1;
    }
    else
    {
        int i = 0;
        while( i <= l1-l2)
        {
            if(arr[i] == brr[0]){
                int j = 1,x = i;
                i++;
                while(i < l1 && j < l2 && arr[i] == brr[j]){
                    i++;
                    j++;
                }
                if(j == l2){
                    cout<<x;
                    return 0;
                }
            }
            else{
                i++;
            }
        }
    }
    cout<<-1;   
}