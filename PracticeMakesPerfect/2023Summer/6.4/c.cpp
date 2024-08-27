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
void solve(){
    int a,b;cin>>a>>b; 
    vector<vector<int>>v(a+1,b+1);
    int t=a*b;
    for(int i=1;i<=a;i++){
        for(int j=0;j<b;j++){
            v[i].push_back(t--);
        }
    }
    if(b&1){
        int t=2;
        for(int i=0;i<a;i++){
            if(t>a)break;
            for(int j=0;j<b;j++){
                cout<<v[t][j]<<' ';
            }
            t+=2;
            cout<<endl;
        }
        t=1;
        for(int i=0;i<a;i++){
            if(t>a)break;
            for(int j=0;j<b;j++){
                cout<<v[t][j]<<' ';
            }
            t+=2;
            cout<<endl;
        }
        for(int i=0;i<b;i++){
            cout<<v[a][i]<<" "; 
        }
        cout<<endl;
    }
    else{
        for(int i=1;i<=a;i++){
            for(int j=0;j<b;j++){
                cout<<v[i][j]<<' ';
            }
            cout<<endl;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}