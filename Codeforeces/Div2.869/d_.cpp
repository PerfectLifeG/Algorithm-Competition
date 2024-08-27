#include <bits/stdc++.h>
using namespace std;

const int N = 2010, M = N * 2;

int head[N], e[M], ne[M], idx;
int deg[N];
int q[N], dist[N], p[N];
bool vis[N];

void add(int v, int w) {
    e[idx] = w, ne[idx] = head[v], head[v] = idx++;
}

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    idx = 0;
    memset(head, -1, sizeof(head));
    memset(deg, 0, sizeof(deg));
    while (m--) {
        int v, w;
        scanf("%d %d", &v, &w);
        add(v, w), add(w, v);
        deg[v]++, deg[w]++;
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i] >= 4) {  // 只有度数至少为4的点才有可能是鱼图的特殊点
            for (int j = head[i]; j != -1; j = ne[j]) { // 枚举所有的边，删去这条边跑bfs
                memset(dist, 0x3f, sizeof(dist));
                dist[i] = 0;
                int hh = 0, tt = -1;
                q[++tt] = i;
                memset(p, 0, sizeof(p));
                while (hh <= tt) {
                    int t = q[hh++];
                    for (int k = head[t]; k != -1; k = ne[k]) {
                        if (t == i && e[k] == e[j] || t == e[j] && e[k] == i) continue; // 跳过删除的边
                        if (dist[e[k]] > dist[t] + 1) {
                            dist[e[k]] = dist[t] + 1;
                            p[e[k]] = t;    // 记录从哪个点转移过来的
                            q[++tt] = e[k];
                        }
                    }
                }
                if (dist[e[j]] < 0x3f3f3f3f) {  // 存在从i到e[j]的路径，说明存在环
                    memset(vis, 0, sizeof(vis));
                    int t = e[j];
                    vector<vector<int>> ans({{i, e[j]}});
                    while (p[t]) {  // 把环上所有点标出来
                        vis[t] = true;
                        ans.push_back({t, p[t]});
                        t = p[t];
                    }
                    int cnt = 2;    // 找两个不在环上的点
                    for (int k = head[i]; k != -1; k = ne[k]) {
                        if (!vis[e[k]]) {
                            ans.push_back({i, e[k]});
                            if (--cnt == 0) break;
                        }
                    }
                    if (!cnt) { // 存在环且存在两个不在环上的点，则存在鱼图
                        printf("YES\n%d\n", ans.size());
                        for (auto &p : ans) {
                            printf("%d %d\n", p[0], p[1]);
                        }
                        return;
                    }
                }
            }
        }
    }
    printf("NO\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }

    return 0;
}