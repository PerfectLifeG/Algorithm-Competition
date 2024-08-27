#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;
    cin>>n>>m;
    unordered_map<string,string>mp;
    for(int i=0;i<n;i++){
        string a,b;
        cin>>a>>b;
        mp[a]=b;
    }
    while(m--){
        string a;cin>>a;
        cout<<mp[a]<<' ';
    }
    return 0;
}