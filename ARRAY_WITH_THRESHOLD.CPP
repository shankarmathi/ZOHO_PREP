#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int t,ans = 0;
    cin>>t;
    for(int i=0;i<n;i++){
        ans += arr[i]/t;
        if(arr[i]%t){
            ans += 1;
        }
    }
    cout<<ans;
}