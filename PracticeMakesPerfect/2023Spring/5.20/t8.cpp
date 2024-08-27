#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    unordered_map<string,string>mp;
    for(int i=0;i<n;i++){
        string a,b;cin>>a>>b;
        mp[a]=b;
        mp[b]=a;
    }
    set<string>st;
    int m;cin>>m;
    unordered_map<string,int>mp2;
    for(int i=0;i<m;i++){
        string a;cin>>a;
        mp2[a]++;
        if(mp.count(a)&&mp2.count(mp[a])){
            st.insert(a);
        }
    }
    cout<<st[0];
    for(int i=1;i<st.size();i++){
        cout<<' '<<st[i];
    }
    cout<<endl;
    return 0;
}