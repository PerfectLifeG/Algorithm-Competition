#include<bits/stdc++.h>
using namespace std;
const int N=20;
// char c1[N];
char c2[N];
int main(){
    string c1;
    cin>>c1;
    // scanf("%s",c1);
    // cout<<c1.back();
    char c;
    int flag=0;
    int i=0;
    getchar();
    while((c=getchar())!='\n'){c2[i++]=c;if(i!=1&&c!='0'&&c!='\n')flag=1;}
    if(c2[0]=='0'&&c2[1]=='\0'){
        cout<<"PLMM";
    }
    else if(c2[0]>'5'||(c2[0]=='5'&&flag==1)){
        cout<<"Happy birthday to MFGG";
    }
    else if(c2[0]=='5'&&flag==0&&(c1.back()-'0')%2!=0&&c1.back()!='0'&&c1.front()!='0'){
        cout<<"Happy birthday to MFGG";
    }else cout<<"Happy birthday to YXGG";
    return 0;
}