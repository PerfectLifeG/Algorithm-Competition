#include <bits/stdc++.h>
using namespace std;
const int N = 1500 + 5;
int a[N][N], b[N][N];
int num1[N][N], num2[N][N];
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n - 1; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++)
		{
			a[i][j] = s[j - 1] - '0';
		}
	}
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= m-1; j++)
		{
			b[i][j] = s[j - 1] - '0';
		}
	}
	int idx = 0;
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] == 1) {
				idx++;
				while (a[i][j] == 1 && j <= m) {
					num1[i][j] = idx;
					j++;
				}
			}
		}
	}
	for (int i = 1; i <= m - 1; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (b[j][i] == 1) {
				idx++;
				while (b[j][i] == 1 && j <= n) {
					num2[j][i] = idx;
					j++;
				}
			}
		}
	}
	vector<vector<int>>q(idx + 5);
	vector<int>in(idx + 5);
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (num1[i][j] == num1[i][j + 1])
			{
				if (num2[i][j] && !num2[i + 1][j]) {
					q[num2[i][j]].push_back(num1[i][j]);
					in[num1[i][j]]++;
				}
				else if (!num2[i][j] && num2[i + 1][j]) {
					q[num2[i + 1][j]].push_back(num1[i][j]);
					in[num1[i][j]]++;
				}
			}
		}
	}
	for (int i = 1; i <= m - 1; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (num2[j][i] == num2[j + 1][i]) {
				if (num1[j][i] && !num1[j][i + 1]) {
					q[num1[j][i]].push_back(num2[j][i]);
					in[num2[j][i]]++;
				}
				else if (!num1[j][i] && num1[j][i + 1]) {
					q[num1[j][i + 1]].push_back(num2[j][i]);
					in[num2[j][i]]++;
				}
			}
		}
	}
	queue<int>que;
	int cnt = idx;
	for (int i = 1; i <= idx; i++) {
		if (in[i] == 0) {
			que.push(i);
			cnt--;
		}
	}
	while (que.size())
	{
		int t = que.front();
		que.pop();
		for (auto w : q[t])
		{
			in[w]--;
			if (in[w] == 0) {
				que.push(w);
				cnt--;
			}
		}
	}
	if (cnt == 0) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
}

