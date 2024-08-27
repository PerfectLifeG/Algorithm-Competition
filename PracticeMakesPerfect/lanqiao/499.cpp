#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int pre[N];
int nx[N];
int temp[30];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    string s;cin>>s;
    memset(temp,-1,sizeof temp);
    for(int i=0;i<s.size();i++){
        pre[i]=temp[s[i]-'a'];
        temp[s[i]-'a']=i;
    }
    for(int i=0;i<30;i++)temp[i]=s.size();
    for(int i=s.size()-1;i>=0;i--){
        nx[i]=temp[s[i]-'a'];
        temp[s[i]-'a']=i;
    }
    int ans=0;
    for(int i=0;i<s.size();i++){
        ans+=(i-pre[i])*(nx[i]-i);
    }
    cout<<ans;
    return 0;
}