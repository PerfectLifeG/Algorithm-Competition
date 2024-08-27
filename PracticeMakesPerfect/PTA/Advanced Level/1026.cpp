#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin()+1,x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
struct Node{
    int arr,ti,f;
    bool operator<(const Node& n)const{
        return arr<n.arr;
    }
};
void solve(){
    int mm;cin>>mm;
    vector<Node>v(mm+1);
    for(int i=1;i<=mm;i++){
        int h,m,s,ti,f;
        scanf("%d:%d:%d %d %d",&h,&m,&s,&ti,&f);
        int sum=h*3600+m*60+s;
        ti=min(ti,120);
        v[i]={sum,ti,f};
    }
    sort(all(v));

    int n,k;cin>>n>>k;
    priority_queue<PII,vector<PII>,greater<PII>>q;
    vector<int>book(n+1);
    vector<int>cnt(n+1);
    unordered_map<int,int>mp;
    for(int i=0;i<k;i++){
        int a;cin>>a;
        book[a]=1;
    }

    queue<int>wait;
    queue<int>vip;
    vector<PII>ans;
    set<int>st;
    set<int>st_v;
    for(int i=1;i<=n;i++){st.insert(i);if(book[i])st_v.insert(i);}
    int i=1;
    while(i<=mm){
        if(v[i].arr>=21*3600)break;
        if(q.size()){
            auto t=q.top();
            if(t.x>=21*3600)break;
        }
        if(v[i].arr==q.top().x){
            while(q.size()&&v[i].arr==q.top().x){
                if(book[q.top().y])st_v.insert(q.top().y);
                st.insert(q.top().y);
                q.pop();
            }
            i++;
            vector<int>temp;
            vector<int>v_temp;
            while(i<=m&&v[i].arr==q.top().x){if(v[i].f)v_temp.push_back(i);temp.push_back(i);i++;}
            if(v_temp.size()&&st_v.size()){
                q.push({max(8*3600,v[i].arr)+v[i].ti*60,*st_v.begin()});
                ans.push_back({v[i].arr,max(8*3600,v[i].arr)});
                cnt[*st_v.begin()]++;
                if(st.find(*st_v.begin())!=st.end())st.erase(*st_v.begin());
                st_v.erase(st_v.begin());
            }else if(){

            }
        }
        else if(st.size()||v[i].arr>q.top().x){
            while(q.size()&&v[i].arr>q.top().x){
                if(book[q.top().y])st_v.insert(q.top().y);
                st.insert(q.top().y);
                q.pop();
            }
            while(v[i].f&&st_v.size()){
                q.push({max(8*3600,v[i].arr)+v[i].ti*60,*st_v.begin()});
                ans.push_back({v[i].arr,max(8*3600,v[i].arr)});
                cnt[*st_v.begin()]++;
                if(st.find(*st_v.begin())!=st.end())st.erase(*st_v.begin());
                st_v.erase(st_v.begin());
            }
            while(){
                q.push({max(8*3600,v[i].arr)+v[i].ti*60,*st.begin()});
                ans.push_back({v[i].arr,max(8*3600,v[i].arr)});
                cnt[*st.begin()]++;
                if(st_v.find(*st.begin())!=st_v.end())st_v.erase(*st.begin());
                st.erase(st.begin());
            }
            i++;
        }else{
            while(v[i].arr<q.top().x&&i<=mm){
                if(v[i].f)vip.push(i);
                wait.push(i);
                i++;
            }

            while(wait.size()){
                auto tt=wait.front();
                while(mp[tt]){
                    wait.pop();
                    if(!wait.size())break;
                    tt=wait.front();
                }
                if(!wait.size())break;

                auto t=q.top();
                q.pop();
                if(book[t.y]&&vip.size()){
                    tt=vip.front();
                    vip.pop();
                    q.push({v[tt].ti*60+t.x,t.y});
                    ans.push_back({v[tt].arr,t.x});
                    cnt[t.y]++;
                    mp[tt]=1;
                }else{
                    tt=wait.front();
                    wait.pop();
                    q.push({v[tt].ti*60+t.x,t.y});
                    ans.push_back({v[tt].arr,t.x});
                    cnt[t.y]++;
                }
            }
        }
    }
    for(auto i:ans){
        printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",i.x/3600,i.x%3600/60,i.x%3600%60,i.y/3600,i.y%3600/60,i.y%3600%60,(int)round(1.0*(i.y-i.x)/60));
    }
    cout<<cnt[1];
    for(int i=2;i<=n;i++)cout<<' '<<cnt[i];
}
signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}