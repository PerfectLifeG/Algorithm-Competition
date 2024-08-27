#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int main(){
	stack<int>s;
	queue<int>q;
	int n,m,k;cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		q.push(a);
	}
	queue<int>ans;
	while(q.size()||s.size()){
		int flag=0,flag2=0;
		if(s.size()){
			int t=s.top();
			if(ans.size()==0){
				ans.push(t);
				flag=1;
				s.pop();
			}else{
				if(t<=ans.back()){
					ans.push(t);
					flag=1;
					s.pop();
				}
			}
		}
		if(q.size()&&!flag){
			int t=q.front();
			if(ans.size()==0){
				ans.push(t);
				q.pop();
				flag2=1;
			}else{
				if(t<=ans.back()){
//					cout<<t<<'.'<<ans.front()<<endl;
					ans.push(t);
					flag2=1;
					q.pop();
				}else{
					if(s.size()<m){
						s.push(t);
						flag2=1;
						q.pop();
					}
				}
			}
		}
		if(!flag&&!flag2||ans.size()==k){
			cout<<ans.front();
			ans.pop();
			while(ans.size()){
				cout<<' '<<ans.front();
				ans.pop();
			}
			cout<<endl;
		}
	}
	if(ans.size()){
		cout<<ans.front();
		ans.pop();
		while(ans.size()){
			cout<<' '<<ans.front();
			ans.pop();
		}
		cout<<endl;
	}
	return 0;
}
