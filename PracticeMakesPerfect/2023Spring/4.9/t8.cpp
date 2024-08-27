#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100010,INF=1e12;
#define lowbit(x) x&-x
int n,m,k;
int tr[N];
int a[N];
void add(int t,int x){
	for(int i=t;i<=n;i+=lowbit(i)){
		tr[i]+=x;
	}
}
int query(int x){
	int sum=0;
	for(int i=x;i;i-=lowbit(i)){
		sum+=tr[i];
	}
	return sum;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		add(i,a[i]);
	}
	while(m--){
		int op,l,r;
		scanf("%lld%lld%lld",&op,&l,&r);
		if(op==1){
			for(int i=l;i<=r;i++){
				if(a[i]<=k){
					add(i,lowbit(a[i]));
					a[i]+=lowbit(a[i]);
				}
			}
		}else{
			printf("%lld\n",query(r)-query(l-1));
		}
	}
	return 0;
}