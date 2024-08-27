#include<bits/stdc++.h>
using namespace std;
const int N = 110;
const int INF = 0x3f3f3f3f;
int m, n;
int level[N], g[N][N];
int book[N];
int d[N];
int dijkstra(int a, int b){//总共n+1个点 艹。。。
    memset(d, 0x3f, sizeof d);
    memset(book, 0, sizeof book);
    d[0] = 0;
    for(int k = 1; k <= n; k++){
        int mn = INF; int t;
        for(int i = 0; i <= n; i++){
            if(book[i] == 0 && d[i] < mn){
                mn = d[i];
                t = i;
            }
        }
        book[t] = 1;
        if(t == 1) return d[1];
        for(int i = 0; i <= n; i++){
            if(book[i] == 0 && level[i] >= a && level[i] <= b)
            d[i] = min(d[i], d[t] + g[t][i]);
        }
    }
    return d[1];
}
int main(){
    cin >> m >> n;
    memset(g, 0x3f, sizeof g);
    for(int i = 0; i <= n; i++) g[i][i] = 0;
    for(int i = 1; i <= n; i++){
        int cnt;
        scanf("%d%d%d", &g[0][i], &level[i], &cnt);
        while(cnt--){
            int id, price;
            scanf("%d%d", &id, &price);
            g[id][i] = price;
        }
    }

    int mn = INF;
    for(int i = level[1] - m; i <= level[1]; i++){
        mn = min(mn, dijkstra(i, i + m));
    }
    cout << mn;
    return 0;
}