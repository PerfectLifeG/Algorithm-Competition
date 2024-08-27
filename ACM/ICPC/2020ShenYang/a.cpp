#include <bits/stdc++.h>
using namespace std;
int n;
#define pb push_back
#define V vector
set<string>s;
V<V<int>>q;
V<int>v;
int ans;
void dfs(int u)//rÎª0£¬bÎª1£» 
{
	if(u==n+1)
	{
		int i,j;
		int res=0;
		int sum[n+1]={0};
		for(i=1;i<v.size();i++)
		{
			sum[i]=sum[i-1]+(v[i]==0);
		}
		for(i=1;i<=n;i++)
		{
			for(j=i;j<=n;j++)
			{
				int tp=sum[j]-sum[i-1];
				if(tp&1)res++;
			}
		}
		if(ans<res)
		{
			ans=res;
			string t;
			s.clear();
			for(i=1;i<=n;i++)
			{
				if(v[i])t+="b";
				else t+="r";
			}
			s.insert(t);
		}
		else if(ans==res)
		{
			string t;
			for(i=1;i<=n;i++)
			{
				if(v[i])t+="b";
				else t+="r";
			}
			s.insert(t);
		}
		return ;
	}
	v.pb(1);
	dfs(u+1);
	v.pop_back();
	v.pb(0);
	dfs(u+1);
	v.pop_back();
}
int main()
{
	v.pb(0);
	int i,j;
	scanf("%d",&n);
	dfs(0);
	int sz=s.size();
	cout<<ans<<" "<<sz<<"\n";
	for(auto z:s)
	{
		int sum[n+1]={0};
		z="0"+z;
		for(j=1;j<z.size();j++)
		{
			sum[j]=sum[j-1]+(z[j]=='r');
		}
		for(j=1;j<z.size();j++)
		{
			cout<<sum[j]%2;
		}
		puts("");
	}
}