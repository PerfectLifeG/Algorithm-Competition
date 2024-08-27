#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005;
int root[N];
int find(int a){
    if(root[a]==a)return a;
    return root[a]=find(root[a]);
}
void merge(int a,int b){
    int ra=find(a),rb=find(b);
    if(ra<rb)swap(ra,rb);
    root[ra]=rb;
}
void solve(){
	int n,m;cin>>n>>m;
    vector<array<int,3>>v;
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        v.push_back({c,a,b});
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++)root[i]=i;
    int ans=0;
    for(int i=0;i<m;i++){
        cout<<v[i][0]<<' '<<v[i][1]<<' '<<v[i][2]<<endl;
        int x=v[i][1],y=v[i][2];
        if(find(x)!=find(y)){
            merge(x,y);
            ans+=v[i][0];
        }
    }
    cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _=1;
	cin>>_;
	while(_--)solve();
}
