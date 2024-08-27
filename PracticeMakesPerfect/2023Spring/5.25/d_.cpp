#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    int cnt=count(s.begin(),s.end(),'(');
    if(cnt!=n-cnt){
        cout<<-1<<endl;
        return;
    }
    vector<int>ans(n,2);
    stack<int>st;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            st.push(i);
        }else if(st.size()){
            ans[st.top()]=1;
            ans[i]=1;
            st.pop();
        }
    }
    if(*max_element(ans.begin(),ans.end())==2){
        while(st.size()){
            st.pop();
        }
        ans.assign(n,2);
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                st.push(i);
            }else if(st.size()){
                ans[st.top()]=1;
                ans[i]=1;
                st.pop();
            }
        }
    }
    cout<<*max_element(ans.begin(),ans.end())<<endl;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}