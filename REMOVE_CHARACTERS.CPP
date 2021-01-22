#include <iostream>

using namespace std;

int main()
{
    string str1,str2;
    cin>>str1>>str2;
    for(int i=0;i<str2.length();i++){
        for(int j=0;j<str1.length();j++){
            if(str1[j] == str2[i])
            {
                str1[j] = '*';   
            }
        }
    }
    string crr;
    for(int i=0;i<str1.length();i++){
        if(str1[i] != '*'){
            crr += str1[i];
        }
    }
    cout<<crr;
}