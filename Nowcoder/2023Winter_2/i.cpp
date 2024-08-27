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
const int INF=0x3f3f3f3f;
void solve(){
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int a,b,c,d;cin>>a>>b>>c>>d;
    int s[5];
    for(int i=0;i<5;i++){
        cin>>s[i];
    }
    vector<int>tmp;
    tmp.push_back(a-1);
    tmp.push_back(a);
    tmp.push_back(b);
    tmp.push_back(c);
    tmp.push_back(d);
    tmp.push_back(d+1);
    sort(all(v));
    int ans=-1e18;
    for(auto t:tmp){
        for(int i=0;i<n;i++){
            int res=0;
            int h=v[i]-t;
            int pre=0,lst;
            lst=lower_bound(v.begin(),v.end(),a+h)-v.begin();
            res+=s[0]*(lst-pre);
            pre=lst;
            
            lst=lower_bound(v.begin(),v.end(),b+h)-v.begin();
            res+=s[1]*(lst-pre);
            pre=lst;
            
            lst=lower_bound(v.begin(),v.end(),c+h)-v.begin();
            res+=s[2]*(lst-pre);
            pre=lst;
            
            lst=upper_bound(v.begin(),v.end(),d+h)-v.begin();
            res+=s[3]*(lst-pre);
            if(lst<n)res+=s[4]*(n-lst);

            ans=max(ans,res);
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}