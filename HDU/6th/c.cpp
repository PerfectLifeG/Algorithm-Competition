#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=310;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int a[N],pre[N];
int pp[N];
unordered_map<int,int>mm;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    for(int i=1;i<=300;i++){
    	pp[i]=i*i;
    	mm[i*i]=1;
    }
    int cnt=0;
    for(int i=0;i<=n-1;i++)
    {
    	for(int j=i+1;j<=n;j++){
    		cout<<j<<' '<<i<<pre[j]-pre[i]<<'\n';
    		if(mm.count(pre[j]-pre[i])){
    			cnt++;
    		}
    	}
    }
    cout<<cnt<<'\n';
    int maxx=0;
    for(int i=1;i<=n;i++)
    {
    	cout<<i<<"----\n";
    	int res;
    	map<int,int>mp;
    	for(int j=0;j<=i-1;j++)
    	{
    		for(int k=i;k<=n;k++)
    		{
    			res=pre[k]-pre[j];
    			mp[res]++;
    		}
    	}
    	for(auto j:mp)
    	{
    		int w=j.first;
    		int s=j.second;
    		cout<<"-------------\n";
    		cout<<w<<' '<<s<<'\n';
    		if(mm.count(w)) continue;
    		for(int i=1;i<=300;i++){
    			if(mm.count(w-a[i]+i)){
    				maxx=max(maxx,s);
    			}
    		}
    	}
    }
    cout<<cnt+maxx<<'\n';
}