#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[10],b[10];
int x_a[10],x_b[10];
int c_a[10],c_b[10];
double a_win=0,p=0,b_win=0;
void dfs(bool flag,double x)
{
	int cnt=0;
	int ff=0,at=1e18;
	if(flag){
		for(int i=1;i<=n;i++){
			if(x_a[i]>0){
				cnt++;
				if(c_a[i]<at){
					ff=i;
					at=c_a[i];
				}
			}
		}
		int cnt_1=0;
		for(int i=1;i<=m;i++){
			if(x_b[i]>0){
				cnt_1++;
			}
		}
		double x2=x/(1.0*(cnt_1));
		if(cnt==0||cnt_1==0){
			if(cnt==0&&cnt_1==0){
				p+=x;
			}else if(cnt==0){
				b_win+=x;
			}else if(cnt_1==0){
				a_win+=x;
			}
		}else{
			for(int i=1;i<=m;i++){
				if(x_b[i]>0){
					x_b[i]-=a[ff];
					x_a[ff]-=b[i];
					c_a[ff]++;
					dfs(false,x2);
					x_b[i]+=a[ff];
					x_a[ff]+=b[i];
					c_a[ff]--;
				}
			}
		}
	}else{
		for(int i=1;i<=m;i++){
			if(x_b[i]>0){
				cnt++;
				if(c_b[i]<at){
					ff=i;
					at=c_b[i];
				}
			}
		}
		int cnt_1=0;
		for(int i=1;i<=n;i++){
			if(x_a[i]>0){
				cnt_1++;
			}
		}
		double x2=x/(1.0*(cnt_1));
		if(cnt==0||cnt_1==0){
			if(cnt==0&&cnt_1==0){
				p+=x;
			}else if(cnt==0){
				a_win+=x;
			}else if(cnt_1==0){
				b_win+=x;
			}
		}else{
			for(int i=1;i<=n;i++){
				if(x_a[i]>0){
					x_a[i]-=b[ff];
					x_b[ff]-=a[i];
					c_b[ff]++;
					dfs(true,x2);
					x_a[i]+=b[ff];
					x_b[ff]+=a[i];
					c_b[ff]--;
				}
			}
		}
	}
	
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x_a[i]=a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
		x_b[i]=b[i];
	}
	if(n<m){
		dfs(false,1);
	}else if(n>m){
		dfs(true,1);
	}else{
		dfs(true,0.5);
		dfs(false,0.5);
	}
	cout<<fixed<<setprecision(16)<<a_win<<'\n'<<b_win<<'\n'<<p<<endl;
}