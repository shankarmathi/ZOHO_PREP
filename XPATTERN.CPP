#include <iostream>

using namespace std;

int main()
{
    string arr;
    cin>>arr;
    int l = arr.length();
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            if(i == j){
                cout<<arr[i]<<" ";
            }
            else if(i+j == l-1){
                cout<<arr[l-1-i]<<" ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<'\n';
    }
}