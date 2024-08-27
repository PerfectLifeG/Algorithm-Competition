#include<bits/stdc++.h>
using namespace std;
const int N=100000;
char a[N];
char b[N];
int main(){
    gets(a);
    gets(b);
    for(int i=0;i<strlen(a);i++){
        int flag=1;
        for(int j=0;j<strlen(b);j++){
            if(a[i]==b[j]){
                flag=0;break;
            }
        }
        if(flag)cout<<a[i];
    }
    return 0;
}