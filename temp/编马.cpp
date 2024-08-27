#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    string name[20]={"","知识学爆","直升机暴打劳大","咸鱼翻身之粘锅了","cf代打，1000分以上的不接","φ²","对对对","君子不器","没拿奖就怪领队","重生之我在PTA打汪汪队","青梅煮酒队","...运行超时...","你看就我写的队","做的全队","宿舍长说的都","不争馒头争口气","新人实践队","沉着冷静队"};
    int p=1;
    cout<<"\t\"solutions\": {\n";
    for(int i=1;i<=17;i++){
        int n;cin>>n;
        for(int j=0;j<n;j++){
            int id;cin>>id;
            int wa;cin>>wa;
            for(int k=0;k<wa;k++){
                printf("\t\"%d\": {\n",p++);
                printf("\t\t\"user_id\": \"%d\",\n",i);
                printf("\t\t\"problem_index\": \"%d\",\n",id);
                printf("\t\t\"verdict\": \"WA\",\n");
                printf("\t\t\"submitted_seconds\": 1\n");
                cout<<"\t},\n";
            }
            int h,m;
            cin>>h>>m;
            int ti=h*60+m;

            printf("\t\"%d\": {\n",p++);
            printf("\t\t\"user_id\": \"%d\",\n",i);
            printf("\t\t\"problem_index\": \"%d\",\n",id);
            printf("\t\t\"verdict\": \"AC\",\n");
            printf("\t\t\"submitted_seconds\": %d\n",ti);
            cout<<"\t},\n";

        }
    }
    cout<<"\t},\n";

    cout<<"\t\"users\": {\n";
    for(int i=1;i<=17;i++){
        printf("\t\"%d\": {\n",i);
        cout<<"\t\t\"name\": \""<<name[i]<<"\",\n";
        cout<<"\t\t\"is_exclude\": true\n";
        cout<<"\t},\n";
    }
    cout<<"\t}\n";


}
signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int _=1;
    cout<<"{\n";
    cout<<"\t\"contest_name\": \"2024中国民航大学计算机学院编程马拉松\",\n";
    cout<<"\t\"problem_count\": 26,\n";
    cout<<"\t\"frozen_seconds\": 3600,\n";
    while(_--)solve();
    cout<<"}\n";
    return 0;
}