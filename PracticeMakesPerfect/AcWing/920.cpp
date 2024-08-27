#include<bits/stdc++.h>
using namespace std;
const int N = 510;
const int INF = 0x3f3f3f3f;
int m,n;
int st=1,ed;
int g[N][N];
int stop[N];
int d[N];
queue<int> q;
void bfs(){
    memset(d, 0x3f, sizeof d);
    q.push(st);d[st] = 0;
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        if(t == ed)return;//第一次到就是最短
        for(int i = 1; i <= n;i ++ ){
            if(g[t][i] == 0)continue;
            if(d[i] > d[t] + 1){
                d[i] = d[t] + 1;
                q.push(i);
            }
        }
    }

}
int main(){
    cin >> m >> n;
    ed=n;
    string line;
    getline(cin, line);//吃回车
    while (m--)
    {
        getline(cin, line);
        stringstream ssin(line);
        int cnt = 0, p;
        while(ssin >> p) stop[cnt++] = p;
        for(int i = 0; i < cnt; i ++ ){
            for(int j = i+1; j < cnt; j ++ ){
                g[stop[i]][stop[j]] = 1;
            }
        }
    }
    bfs();
    if(d[ed] > INF/2) cout << "NO";
    else cout << d[ed] - 1;//没有任何问题  同一条线最多只坐一次所以d[ed]一定最短
    return 0;
}