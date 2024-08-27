#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define endl '\n'
typedef pair<int, int> pii;
typedef unsigned long long ull;

mt19937_64 rnd(time(0));

const int N = 1e6 + 10, mod = 1e9 + 7;
const int inf = 1e18;

int get(int l, int r) {
    return rnd() % (r - l + 1) + l;
}


void solve() {
    int n, m;
//    n = get(3,100);
//    m = get(0, n - 2);
    cin >> n >> m;
    if (m == n - 2) {
        cout << "-1\n";
        return;
    }

    int tn = n - m;
    int len = tn / 3;
    vector<int> ans;
    if (tn % 3 == 2) {
        ans.push_back(tn / 3 * 3 + 1);
    }
    for (int i = 0; i < len; i++) {
        ans.push_back(2 * len + 1 + i);
        ans.push_back(1 + i);
        ans.push_back(len + 1 + i);
    }
    if (tn % 3 == 1) {
        ans.push_back(tn / 3 * 3 + 1);
    } else if (tn % 3 == 2) {
        ans.push_back(tn / 3 * 3 + 2);
    }
    if (ans.size() % 3 == 0 && ans.size() != 0) {
        swap(ans[ans.size() - 2], ans[ans.size() - 3]);
    }

    for (int i = tn + 1; i <= n; i++)
        ans.push_back(i);
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
//    int sum = 0;
//    for (int i = 0; i + 2 < ans.size(); i++) {
//        if (ans[i] + ans[i + 1] + ans[i + 2] - max({ans[i], ans[i + 1], ans[i + 2]}) > max({ans[i], ans[i + 1], ans[i + 2]})) {
//            sum++;
//        }
//    }
//    if (sum != m) {
//        cout << n << ' ' << m << '\n';
//    }


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
//    for (int i = 3; i <= 500; i++) {
//        n = i;
//        for (int j = 0; j <= n - 2; j++) {
//            m = j;
//            solve();
//        }
//    }
//    t = 100;
    while (t--) solve();
    return 0;
}