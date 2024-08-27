#include<bits/stdc++.h>
using namespace std;
int root[11000];
int find(int a){
    if(root[a]==a)return a;
    return root[a]=find(root[a]);
}
void merge(int a,int b){
    int ra=find(a),rb=find(b);
    if(ra>rb)swap(ra,rb);
    root[rb]=ra;
}
int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<=n;i++)root[i]=i;
    int ru[n+1]={};
    vector<int>v[n+1];
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        ru[b]++;
        v[a].push_back(b);
        merge(a,b);
    }
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(ru[i]==0){
            q.push(i);
        }
    }
    vector<int>ans;
    int mx=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        if(mx>ru[i]){
            mx=ru[i];
            ans.clear();
            ans.push_back(i);
        }else if(mx==ru[i]){
            ans.push_back(i);
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans[0];
    for(int i=1;i<ans.size();i++){
        cout<<' '<<ans[i];
    }cout<<endl;

    int t=find(1);
    for(int i=1;i<=n;i++){
        if(find(i)!=t){
            cout<<"No\n";
            return 0;
        }
    }
    
    int cnt=0;
    vector<int>an;
    while(q.size()){
        auto t=q.front();
		if(q.size()!=1){
            cout<<"No\n";
            return 0;
        }
        q.pop();
        an.push_back(t);
        cnt++;
        for(auto j:v[t]){
            if(--ru[j]==0){
                q.push(j);
            }
        }
    }
    if(cnt!=n){
        cout<<"No\n";
        return 0;
    }
    cout<<"Yes\n";
    cout<<an[0];
    for(int i=1;i<an.size();i++){
         cout<<' '<<an[i];   
    }
}
