#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n-2;i++){
        for(int j=0;j<n-2-i;j+=2){
            if(arr[j] < arr[j+2]){
                swap(arr[j],arr[j+2]);
            }
        }
    }
    for(int i=1;i<n-2;i++){
        for(int j=1;j<n-2-i;j+=2){
            if(arr[j] > arr[j+2]){
                swap(arr[j],arr[j+2]);
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}