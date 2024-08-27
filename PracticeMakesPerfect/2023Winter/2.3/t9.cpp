#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    string s;cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='u')break;
    }
    cout<<s;
    return 0;
}