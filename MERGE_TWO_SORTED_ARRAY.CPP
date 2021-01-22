#include <iostream>

using namespace std;

int main()
{
    int n1,n2;
    cin>>n1;
    int arr[n1];
    for(int i=0;i<n1;i++){
        cin>>arr[i];
    }
    cin>>n2;
    int brr[n2];
    for(int i=0;i<n2;i++){
        cin>>brr[i];
    }
    int crr[n1+n2];
    int i=0,j=0,k=0;
    while(i < n1 && j < n2){
        if(arr[i] == brr[j]){
            crr[k++] = arr[i];
            i++;j++;
        }
        else if(arr[i] < brr[j]){
            crr[k++] = arr[i++];
        }
        else{
            crr[k++] = brr[j++];
        }
    }
    while(i < n1){
        crr[k++] = arr[i++];
    }
    while(j < n2){
        crr[k++] = brr[j++];
    }
    for(i=0;i<k;i++){
        cout<<crr[i]<<" ";
    }
}