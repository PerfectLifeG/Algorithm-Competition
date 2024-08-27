#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int m;
void solve(){
    int ac,time;
    cin>>ac>>time;
    vector<string>pro(m+1);
    vector<string>book(m+1);
    vector<int>a_(m+1);
    vector<int>b_(m+1);
    vector<int>wc(m+1);
    vector<PII>w;
    int cnt1=0;
    int cnt2=0;
    int v=0;
    for(int i=1;i<=m;i++){
        cin>>book[i];
        if(book[i]=="?"){
            cin>>a_[i]>>b_[i];
            cnt1++;
            // if(b_[i]>a_[i])v+=(b_[i]-a_[i])*20;
            w.push_back({b_[i]-1,i});
        }else if(book[i]=="+"){
            cnt2++;
            cin>>pro[i];
            int n=0;
            int a=-1,b=-1;
            for(auto j:pro[i]){
                if(j=='/'){
                    if(a==-1)a=n;
                    else b=n;
                    n=0;
                    continue;
                }
                n=n*10+(j-'0');
            }
            b=n;
            time=time-(a-1)*20-b;
        }else if(book[i]=="-"){
            cin>>pro[i];
        }
        // cout<<i<<' '<<time<<endl;
    }
    // cout<<time<<endl;
    sort(all(w),[&](PII a,PII b){
        if(a.x==b.x)return a.y>b.y;
        return a.x>b.x;
    });
    int guo=ac-cnt2;
    if(guo<0||guo>cnt1){
        no;
        return;
    }
    int mx=0;
    for(int i=0;i<w.size();i++){
        if(i<guo){
            mx+=w[i].x;
            book[w[i].y]='+';
            v+=(b_[w[i].y]-a_[w[i].y])*20;
        }
        else {
            pro[w[i].y]=to_string(b_[w[i].y]);
            book[w[i].y]='-';
        }
    }
    
    if(time<240*guo+v||time>299*guo+mx*20){
        no;
        return;
    }
    time-=guo*240;
    int t=time/20;
    // cout<<time<<' '<<t<<endl;
    for(int i=0;i<guo;i++){
        if(w[i].x>t){
            wc[w[i].y]=t;
            time-=t*20;
            t=0;
            break;
        }
        t-=w[i].x;
        time-=20*w[i].x;
        wc[w[i].y]=w[i].x;
    }
    // cout<<time<<' '<<t<<endl;
    // if(time)
    for(int i=0;i<guo;i++){
        // cout<<i<<' '<<w[i].x<<' '<<w[i].y<<endl;
        if(b_[w[i].y]-a_[w[i].y]>=wc[w[i].y]+1){
            no;
            return;
        }
        if(59>=time){
            // wcc[i]=time+240;
            // cout<<wc[w[i].y]<<endl;
            pro[w[i].y]=to_string(wc[w[i].y]+1)+"/"+to_string(time+240);
            time=0;
        }
        if(!time)continue;
        pro[w[i].y]=to_string(wc[w[i].y]+1)+"/299";
        time-=59;
    }
    yes;
    for(int i=1;i<=m;i++){
        cout<<book[i]<<' '<<pro[i]<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;cin>>m;
    while(_--)solve();
    return 0;
}