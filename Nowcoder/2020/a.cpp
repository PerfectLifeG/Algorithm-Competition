#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    string aa,bb;
    while(cin>>aa>>bb){
        int n;
        int na=aa.size();
        int nb=bb.size();
        if(aa.size()>bb.size()){
            n=aa.size();
        }
        else 
            n=bb.size();
        n*=2;
        int f=1;
        for(int i=0;i<n;i++){
            if(aa[i%na]>bb[i%nb]){
                cout<<'>'<<endl;
                f=0;
                break;
            }else if(aa[i%na]<bb[i%nb]){
                f=0;
                cout<<'<'<<endl;
                break;
            }
        }
        if(f)
        cout<<'='<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}