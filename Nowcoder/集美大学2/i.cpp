#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=1005;
const int mod=998244353;
deque<int>q[N];
void solve(){
    int n,m;cin>>n>>m;
    vector<char>a(n+1);
    for(int i=1;i<=n;i++){cin>>a[i];q[i].push_back(i);}

    while(m--){
        int op;cin>>op;
        if(op==1){
            int x,y;cin>>x>>y;
            while(q[x].size()){
                q[y].push_back(q[x].back());
                q[x].pop_back();
            }
        }else if(op==2){
            int x,y;cin>>x>>y;
            while(q[x].size()){
                q[y].push_back(q[x].front());
                q[x].pop_front();
            }
        }else{
            int x;cin>>x;
            vector<int>v;
            while(q[x].size()){
                v.push_back(q[x].back());
                q[x].pop_back();
            }
            for(auto i:v)q[i].push_back(i);
        }
    }

    for(int i=1;i<=n;i++){
        stack<int>st;
        vector<string>ans;
        int cnt=0;
        int flag=1;
        while(q[i].size()){
            if(a[q[i].front()]=='('){
                st.push(q[i].front());
                q[i].pop_front();
                cnt++;
            }
            else if(a[q[i].front()]==')'){
                q[i].pop_front();
                if(!cnt){flag=0;break;}
                string t="";
                while(st.size()&&a[st.top()]!='('){
                    t+=a[st.top()];
                    st.pop();
                }
                if(st.size()==0){
                    flag=0;break;
                }
                st.pop();
                cnt--;
                reverse(all(t));
                if(t!="")ans.push_back(t);
            }else {
                st.push(q[i].front());
                q[i].pop_front();
            }
        }
        if(st.size()){
            string t;
            while(st.size()){
                if(a[st.top()]=='('){
                    flag=0;
                    break;
                }
                t+=a[st.top()];
                st.pop();
            }
            reverse(all(t));
            ans.push_back(t);
        }
        if(!flag)cout<<-1<<endl;
        else if(!ans.size())cout<<0<<endl;
        else {
            cout<<ans.size()<<' ';
            for(auto i:ans)cout<<i<<' ';
            cout<<endl;
        }
    }    

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}