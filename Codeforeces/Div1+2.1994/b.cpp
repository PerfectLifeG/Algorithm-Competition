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
    int n;cin>>n;
    string s1,s2;cin>>s1>>s2;
    if(s1[0]=='0'&&s2[0]=='1'){
        no;
        return;
    }else if(s1[0]=='1'){
        yes;
        return;
    }else {
        int f1=n+1;
        int f2=n+1;
        for(int i=0;i<n;i++){
            if(s1[i]=='1'){f1=i;break;}
        }
        for(int i=0;i<n;i++){
            if(s2[i]=='1'){f2=i;break;}
        }
        if(f2>=f1)yes;
        else no;
    }
    // for(int i=0;i<n;i++){
    //     if(s1[i]!=s2[i]){
    //         if(s1[0]==s1[i])
    //     }
    // }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}