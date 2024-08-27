#include<bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200005;
void solve(){
	int n,k;cin>>n>>k;
    //vector<PII>v;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        mp[a]+=b;
    }
    vector<PII>v;
    for(auto i:mp){v.push_back(i);}
                       //cout<<i<<' '<<j<<endl;}
    int ans=0;
    for(int i=v.size()-1;i>=1;){
    	//cout<<v[i].x<<' '<<v[i].y<<endl;
        if(v[i].y==0)continue;
        int x=k-v[i].y%k;
        int sum=0;
        //int j=i-1;
        int j=i-1;
        while(j>=1&&sum!=x){
            if(sum+v[j].y<x){
                sum+=v[j].y;
                v[j].y=0;
                j--;
            }else{
                v[j].y-=x-sum;
                sum=x;
                break;
            }
        }
        ans+=v[i].y/k*v[i].x+(bool)(v[i].y%k)*v[i].x;
    	i=j;
	}
   if(v[0].y!=0)
    ans+=v[0].y/k*v[0].x+(bool)(v[0].y%k)*v[0].x;
    cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _=1;
	cin>>_;
	while(_--)solve();
}
