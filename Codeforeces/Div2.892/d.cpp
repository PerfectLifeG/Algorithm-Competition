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
void solve()
{
    int n;cin>>n;
    set<PII>st;
    for(int i=0;i<n;i++){
        int l,r,a,b;
        cin>>l>>r>>a>>b;
        st.insert({l,b});
    }
    vector<PII>v;
    for(auto i:st){v.push_back(i);}
    vector<PII>ans;
    int lst=0;
    for(int i=1;i<v.size();i++){
        if(v[i].x>v[lst].y){
            ans.push_back(v[lst]);
            lst=i;
        }else if(v[lst].y>=v[i].x&&v[lst].y<=v[i].y){
            v[lst].y=v[i].y;
        }
    }
    ans.push_back(v[lst]);
    int q;cin>>q;
    while(q--){
        int x;cin>>x;
        int l=-1,r=ans.size();
        while(l+1!=r){
            int mid=l+r>>1;
            if(x>ans[mid].y)l=mid;
            else r=mid;
        }
        if(r!=ans.size()&&ans[r].x<=x&&ans[r].y>=x)cout<<ans[r].y<<' ';
        else cout<<x<<' ';
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