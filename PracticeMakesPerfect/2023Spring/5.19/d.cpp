#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
int a[N];
void 
void solve(){
    int n;cin>>n;
    int idx,idx2;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==n){
            idx=i;
        }
        if(a[i]==n-1){
            idx2=i;
        }
    }
    set<string>st;
    if(idx==0){
        string s="";
        for(int i=idx;i<n;i++){
            s+=('0'+a[i]);
            s+=' ';
        }
        for(int i=0;i<=idx2-1;i++){
            string t="";
            int k=0;
            for(int j=idx-1;k<=i;j--,k++){
                t+=('0'+a[j]);
                t+=' ';
            }
            for(int i=0;i<n;i++){
                
            }
            st.insert(s+t);
        }
    }
    cout<<(--st.end())<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}