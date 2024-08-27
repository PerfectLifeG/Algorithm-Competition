#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
const int N=100010;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m,k;cin>>n>>m>>k;
	stack<int>box;
	queue<int>pool;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		pool.push(a);
	}
	queue<int>ans;
	while(pool.size()||box.size()){
		int flag=0;
		if(box.size()){
			auto t=box.top();
			if(ans.size()){
				if(ans.back()>=t){
					ans.push(t);
					box.pop();
					flag=1;
				}
			}else{
				ans.push(t);
				box.pop();
				flag=1;
			}
		}
		if(!flag){
			if(pool.size()){
				auto t=pool.front();
				if(ans.size()){
					if(ans.back()>=t){
						ans.push(t);
						pool.pop();
						flag=1;
					}else{
						if(box.size()<m){
							box.push(t);
							pool.pop();
							flag=1;
						}
					}
				}else{
					ans.push(t);
					pool.pop();
					flag=1;
				}
			}
		}
		if(!flag||ans.size()==k){
			int fir=1;
			while(ans.size()){
				if(fir){cout<<ans.front();fir=0;}
				else cout<<' '<<ans.front();
				ans.pop();
			}
			cout<<endl;
		}
	}
	int fir=1;
	while(ans.size()){
		if(fir){cout<<ans.front();fir=0;}
		else cout<<' '<<ans.front();
		ans.pop();
	}
	return 0;
}