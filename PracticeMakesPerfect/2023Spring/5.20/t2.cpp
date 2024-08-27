#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int a,b,c;cin>>a>>b>>c;
    if(b>a&&c>a){
        cout<<"*^_^*";
    }else if(b>a&&c<=a){
        cout<<"T_T";
    }else if(b<=a&&c>a){
        cout<<"-_-#";
    }else cout<<"-_-";
    return 0;
}