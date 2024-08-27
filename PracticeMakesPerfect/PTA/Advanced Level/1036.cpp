#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n;cin>>n;
    pair<string,string> M;
    pair<string,string> F;
    int m=101,f=-1;
    for(int i=0;i<n;i++){
        string a,b,c;int d;
        cin>>a>>b>>c>>d;
        if(b=="M"){
            if(d<m){
                m=d;
                M={a,c};
            }
        }else{
            if(d>f){
                f=d;
                F={a,c};
            }
        }
    }
    if(m==101||f==-1){
        if(f!=-1){
            cout<<F.x<<' '<<F.y<<endl;
        }else cout<<"Absent"<<endl;
        if(m!=101){
            cout<<M.x<<' '<<M.y<<endl;
        }else cout<<"Absent"<<endl;
        cout<<"NA"<<endl;
    }else{
        cout<<F.x<<' '<<F.y<<endl;
        cout<<M.x<<' '<<M.y<<endl;
        cout<<f-m<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}