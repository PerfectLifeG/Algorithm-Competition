#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int a,b,c;cin>>a>>b>>c;
    int n=a+b+c;
    if(a==0&&b==0){
        no;
        return;
    }
    if(b==0&&a>c){
        cout<<2*c+1<<endl;
        return;
    }
    if(b==0&&a<=c){
        no;
        return;
    }
    if(c==0){
        if(a==b){
            no;
            return;
        }
        if(a>b){
            cout<<2*b+1<<endl;
            return;
        }
        int mn=min(a,b);
        cout<<n<<end;
    }

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}