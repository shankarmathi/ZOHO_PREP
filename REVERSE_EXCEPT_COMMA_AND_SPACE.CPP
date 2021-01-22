#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char arr[1000];
    scanf("%[^\n]s",arr);
    int s = 0,e = strlen(arr)-1;
    while (s < e)
    {
        while(!isalnum(arr[s]))
        {
            s++;
        }
        while(!isalnum(arr[e]))
        {
            e--;
        }
        if(s < e)
        {
            swap(arr[s],arr[e]);
            s++;
            e--;
        }
    }
    cout<<arr;
}