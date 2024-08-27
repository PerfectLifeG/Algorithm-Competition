#include<bits/stdc++.h>
//#define int long long
#define pii pair<int,int>
using namespace std;

const int mod = 998244353;

int qmi(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = (long long)ans * a % mod;
        a = (long long)a * a % mod;
        b >>= 1;
    }
    return ans;
}

vector<int> pw(10000001);

void init() {
    pw[0] = 1; 
    for (int i = 1; i <= 10000000; i++) {
        pw[i] = (long long)pw[i - 1] * i % mod;
    }
}

void solve() {
    int ans = 0;
    int n, k; 
    cin >> n >> k;
    if (k == 0) {
        ans = (long long)pw[n] * n % mod;
    }
    int inv = qmi(pw[k], mod - 2);
    int now = (long long)inv * (n - (1 + k)) % mod;
    int a = 2;
    for (int i = 0, cnt = (n - (1 + k)); cnt > 0; i++, cnt--) {
        long long x = (long long)now * pw[n - i - 1] % mod;
        long long y = (long long)a * pw[i + k] % mod;
        ans += x * y % mod;
        if (ans >= mod) ans -= mod;
        now = (now - inv + mod) % mod;
        a = (a + i + i + 4) % mod;
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    init();
    int t = 1;
    cin >> t;
    while (t--) solve();
}