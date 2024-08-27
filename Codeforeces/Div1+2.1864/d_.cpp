#include <bits/stdc++.h>
#define de(a) cout << #a << " = " << a << "\n";
#define deg(a) cout << #a << " = " << a << " ";
#define int long long
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define PII pair<int, int>
using namespace std;
constexpr int N = 3000 + 10;
using LL = long long;

constexpr LL INF = 1e18;
int n, m, k;
int a[N][N];
char s[N][N];
int dg[2 * N];
int udg[2 * N];

void solve(int Case) {

	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];

	for (int i = 0; i <= 2 * n + 10; i++) {
		dg[i] = udg[i] = 0;
	}

	int ans = 0;
	vector<vector<int>> d((n + 10), vector<int>(n + 10));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = (dg[i + j] + udg[n - i + j] + (i == 0? 0 : d[i - 1][j])) & 1;
			cout<<i<<' '<<j<<' '<<dg[i + j]<<' '<<udg[n - i + j]<<' '<<(i == 0? 0 : d[i - 1][j])<<endl;
			if (d[i][j] & 1) s[i][j] ^= 1;
			if (s[i][j] == '1') {
				ans++;
				d[i][j]++;
				dg[i + j]++;
				udg[j - i + n]++;
			}
		}	
	}

	cout << ans << "\n";
}

signed main() {
	cin.tie(0)->ios::sync_with_stdio(false);

	int T = 1;
	cin >> T; cin.get();

	int Case = 0;
	while (++Case <= T) {
		solve(Case);;
	}

	return 0;
}