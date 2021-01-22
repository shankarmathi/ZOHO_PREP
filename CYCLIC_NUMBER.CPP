#include <iostream>
#include <string>

using namespace std;

int main()
{
    string arr,brr;
    cin>>arr>>brr;
    string crr = arr+arr;
    int l1 = crr.length(),l2 = arr.length();
    for(int i=0;i<=l1-l2;i++){
        int f = 0;
        for(int j=0;j<l2;j++){
            if(brr[j] != crr[i+j]){
                f = 1;
            }
        }
        if(f == 0){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
}

/*
#include<stdio.h>
int main()
{
long long int num1 , num2 , power , nod , rotate;
scanf("%lld%lld",&num1 , &num2);
power = 1;
nod = 0;
while(num1 / power)
{
power *= 10;
nod++;
}
power /= 10;
rotate = num1;
while(rotate != num2 && nod)
{
rotate = (rotate%10)*power + (rotate/10);
nod--;
}
if(rotate == num2 && nod != 0 )
printf("Yes");
else
printf("No");
return 0;
}
*/