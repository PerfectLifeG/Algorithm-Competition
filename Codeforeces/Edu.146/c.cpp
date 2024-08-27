#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n,s1,s2;cin>>n>>s1>>s2;
    vector<PII>a(n+1);
    vector<int>ans1;
    vector<int>ans2;
    for(int i=0;i<n;i++){
        int t;cin>>t;a[i]={t,i+1};
    }
    sort(all(a),[&](PII c,PII b){
        return c.x>b.x;
    });
    int n1=s1,n2=s2;
    for(int i=0;i<n;i++){
        if(n1>n2){
            ans2.push_back(a[i].y);
            n2+=s2;
        }else if(n1<n2){
            ans1.push_back(a[i].y);
            n1+=s1;
        }else if(s1>s2){
            ans2.push_back(a[i].y);
            n2+=s2;
        }else{
            n1+=s1;
            ans1.push_back(a[i].y);
        }
    }
    cout<<ans1.size()<<' ';
    for(auto i:ans1)cout<<i<<' ';cout<<endl;
    cout<<ans2.size()<<' ';
    for(auto i:ans2)cout<<i<<' ';cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}