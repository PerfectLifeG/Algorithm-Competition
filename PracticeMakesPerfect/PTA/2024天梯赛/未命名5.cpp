#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define endl '\n'
const int N=100010;
set<int>v[N];
int p=-1;
int mx;
int flag=1;
vector<int>ans;
void dfs(int t,int fa){
     int f=0;
    ans.push_back(t);
    for(auto j:v[t]){
        if(j==fa)continue;
        dfs(j,t);
         f=1;
    }
    if(f){
    mx=max(mx,(int)v[t].size());
	    if(p==-1){
	        p=v[t].size();
	    }else{
	        if(p!=v[t].size()){
	            flag=0;
	        }
	    }
	}
}

int main(){
	int n;cin>>n;
    int root;
    for(int i=1;i<=n;i++){
        int fa;cin>>fa;
        if(fa==0){
            root=i;
            continue;
        }
        v[fa].insert(i);
    }
    dfs(root,root);
    cout<<mx<<' ';
    if(flag)cout<<"yes\n";
    else cout<<"no\n";
    for(int i=0;i<ans.size();i++){
        if(i)cout<<' ';
        cout<<ans[i];
    }
}
