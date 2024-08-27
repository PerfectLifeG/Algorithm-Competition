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
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
#define int long long//__int128 2^127-1(GCC)
#define PII pair<int,int>
using namespace std;
const int inf = 0x3f3f3f3f, N = 5e5 + 5;
int a[N], ne[N];
bool st[N];
gp_hash_table<int, PII>q;
int maxx = 0;
set<int>se;
int cnt1 = 0;
void dfs(int x,int cnt) {
 if (st[x] == true) {
  cnt1 = cnt - 1;
  return;
 }
 st[x] = true;
 if (se.find(a[x]) == se.end()) {
  q[a[x]].first = 0, q[a[x]].second = 0;
 }
 se.insert(a[x]);
 if (q[a[x]].second == 0) {
  q[a[x]].first = cnt, q[a[x]].second = cnt;
 }
 else {
  maxx = max(maxx, cnt - q[a[x]].second);
  q[a[x]].second = cnt;
 }
 dfs(ne[x], cnt + 1);
 if (cnt == 1) {
  for (auto w: se) {
   maxx = max(maxx, cnt1 - (q[w].second - q[w].first));
  }
 }
}
signed main()
{
 ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);
 int n;
 cin >> n;
 for (int i = 1; i <= n; i++) {
  cin >> a[i];
 }
 for (int i = 1; i <= n; i++) {
  cin >> ne[i];
 }
 for (int i = 1; i <= n; i++) {
  if (!st[i]) {
   se.clear();
   dfs(i, 1);
  }
 }
 cout << maxx << '\n';
}