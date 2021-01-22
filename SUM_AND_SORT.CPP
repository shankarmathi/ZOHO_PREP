#include <iostream>
#include <cmath>

using namespace std;

struct abc
{
    int first;
    int second;
};

int main(){
    int n;
    cin>>n;
    struct abc arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
        arr[i].second = 0;
        double x = sqrt(arr[i].first);
        int y = x;
        if(x == y){
            arr[i].second += 5;
        }
        if(arr[i].first%4 == 0 && arr[i].first%6 == 0){
            arr[i].second += 4;
        }
        if(arr[i].first % 2 == 0){
            arr[i].second += 3;
        }
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j].second > arr[j+1].second){
                struct abc x = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = x;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i].first<<" "<<arr[i].second<<'\n';
    }
}