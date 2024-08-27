#include<bits/stdc++.h>
using namespace std;
// #define int long long
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
    int st,n,k;cin>>st>>n>>k;
    unordered_map<int,int>val;
    unordered_map<int,int>nx;
    for(int i=0;i<n;i++){
        int a,b,c;cin>>a>>b>>c;
        val[a]=b;
        nx[a]=c;
    }
    vector<int>neg;
    vector<int>l;
    vector<int>r;
    while(st!=-1){
        if(val[st]<0)neg.push_back(st);
        else if(val[st]<=k)l.push_back(st);
        else r.push_back(st);
        st=nx[st];
    }
    vector<int>ans;
    ans.insert(ans.end(),neg.begin(),neg.end());
    ans.insert(ans.end(),l.begin(),l.end());
    ans.insert(ans.end(),r.begin(),r.end());
    printf("%05d %d",ans[0],val[ans[0]]);
    for(int i=1;i<ans.size();i++){
        printf(" %05d\n%05d %d",ans[i],ans[i],val[ans[i]]);
    }
    cout<<' '<<-1<<endl;
}
signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}