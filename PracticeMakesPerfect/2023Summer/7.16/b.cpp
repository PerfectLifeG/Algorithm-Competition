#include<iostream>
#include<algorithm>
#include<numeric>//accumulate(be,en,0)
#include<cstring>//rfind("string"),s.find(string,begin)!=s.npos,find_first _of(),find_last_of()
#include<string>//to_string(value),s.substr(int begin, int length);
#include<cstdio>
#include<cmath>
#include<vector>//res.erase(unique(res.begin(), res.end()), res.end()),reverse(q.begin(),q.end());
#include<queue>//priority_queue(big)  /priority_queue<int, vector<int>, greater<int>> q(small)
#include<stack>
#include<map>//unordered_map
#include<set>//iterator,insert(),erase(),lower(>=)/upper_bound(>)(value)/find()return end()
#include<unordered_map>
#include<unordered_set>
#define int long long//__int128 2^127-1(GCC)
#define PII pair<int,int>
using namespace std;
const int inf = 0x3f3f3f3f, N = 1e5 + 5;
int a[N];
int c[N];
void add(int x, int y)
{
    for (; x <= N; x += x & -x) c[x] += y;
}
int ask(int x) {
    int ans = 0;
    for (; x; x -= x & -x) ans += c[x];
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        add(l, 1);
        add(r + 1, -1);
    }
    vector<PII>q;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int p = ask(i);
        q.push_back({ p,a[i] });
        sum += p * a[i];
    }
    sort(q.begin(), q.end(), greater<PII>());
    for (auto w:q) {
        int f = w.first, s = w.second;
        if (k - s >= 0) {
            k -= s;
            sum -= f * s;
        }
        else {
            int nm = k;
            sum -= nm * f;
            k = 0;
        }
        if (k == 0) break;
    }
    cout << sum;
}
/*
4 2 2
1 2 3 4
1 4
3 4
*/