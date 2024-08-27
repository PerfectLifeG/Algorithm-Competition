#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int check(int a,int b){
    if(a==0)return 0;
    if(b==0)return 1;
    b%=2*a;
    return (check(b,abs(a-b))+1)%3;
}
void solve()
{
    int n;cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int lst=-1;
    for(int i=0;i<n;i++){
        if(a[i]==0&&b[i]==0)continue;
        int t=check(a[i],b[i]);
        if(lst!=-1&&lst!=t){
            no;
            return;
        }
        lst=t;
    }
    yes;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}