#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
double cost[24];
struct Node{
    int mon;
    int day;
    int h;
    int m;
    string f;
    bool operator<(const Node& n)const{
        if(mon!=n.mon){
            return mon<n.mon;
        }else if(day!=n.day){
            return day<n.day;
        }else if(h!=n.h){
            return h<n.h;
        }else if(m!=n.m){
            return m<n.m;
        }else return f>n.f;
    }
};
int tim;
double tot;
double sum;
void check(int a,int b,int c,int d,int e,int f){
    tim=0;
    tot=0;
    if(a==d){
        for(int i=b+1;i<=e-1;i++){
            tot+=cost[i]*60;
        }
        if(b==e){
            tot+=cost[b]*(f-c);
            tim+=f-c;
        }
        else {
            tot+=cost[b]*(60-c);
            tot+=cost[e]*(f);
            tim+=60-c+f+(e-b-1)*60;
        }
    }else{
        for(int i=b+1;i<=23;i++){
            tot+=cost[i]*60;
        }
        for(int i=0;i<=e-1;i++){
            tot+=cost[i]*60;
        }
        tot+=60*sum*(d-a-1);
        tot+=cost[b]*(60-c);
        tot+=cost[e]*(f);
        tim+=60-c+f+(e+24-b-1)*60+24*60*(d-a-1);
    }
}
void solve(){
    for(int i=0;i<24;i++){cin>>cost[i];cost[i]*=0.01;sum+=cost[i];}
    int n;cin>>n;
    map<string,vector<Node>>mp;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        int a,b,c,d;
        scanf("%d:%d:%d:%d",&a,&b,&c,&d);
        string f;cin>>f;
        mp[s].push_back({a,b,c,d,f});
    }
    for(auto [s,v]:mp){
        sort(all(v));
        int ok=1;
        int flag=0;
        Node pre;
        double ans=0;
        for(auto t:v){
            if(t.f=="on-line"){
                pre=t;
                flag=1;
                continue;
            }
            if(t.f=="off-line"&&flag){
                check(pre.day,pre.h,pre.m,t.day,t.h,t.m);
                if(ok){
                    cout<<s<<' ';
                    printf("%02d\n",pre.mon);
                    ok=0;
                }
                printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n",pre.day,pre.h,pre.m,t.day,t.h,t.m,tim,tot);
                ans+=tot;
                flag=0;
            }
        }
        if(!ok)
        printf("Total amount: $%.2lf\n",ans);
    }
}
signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}