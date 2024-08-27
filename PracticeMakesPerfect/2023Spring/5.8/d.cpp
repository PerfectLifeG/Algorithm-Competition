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
int cnt[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,k;cin>>n>>k;
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        cnt[a]++;
        cnt[b]++;
    }
    for(int i=1;i<=n;i++){
        
    }
    return 0;
}