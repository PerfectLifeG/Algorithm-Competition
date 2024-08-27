#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int f=-1;
    for(int i=0;i<8;i++){
        string s;
        cin>>s;
        if(f==-1){
            for(int j=0;j<8;j++){
                if(s[j]!='.'){
                    f=j;
                    // cout<<f<<endl;
                    cout<<s[f];
                    break;
                }
            }
        }else {if(s[f]!='.')cout<<s[f];}
        // cout<<s<<endl;
    }
    cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}