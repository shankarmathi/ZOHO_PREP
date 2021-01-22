#include <iostream>

using namespace std;

int check_palin(string arr)
{
    int s = 0,e = arr.length()-1;
    while(s <= e)
    {
        if(arr[s] != arr[e]){
            return 0;
        }
        s++;
        e--;
    }
    return 1;
}

int main()
{
    string arr,words;
    getline(cin,arr);
    for(int i=0;i<arr.length();i++)
    {
        if(arr[i] != ' ')
        {
            words += arr[i];
        }
        else
        {
            int x = check_palin(words);
            if(!x){
                cout<<words<<' ';
            }
            words = "";
        }
    }
    int x = check_palin(words);
    if(!x){
        cout<<words<<" ";
    }
}