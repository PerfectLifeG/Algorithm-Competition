#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int dp[205][5005], ndp[205][5005];

int main(){

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    string s;
    cin >> s;
    const int n = s.size();
    int c0 = count(s.begin(), s.end(), '0');
    int c1 = n - c0;
    int cnt[2] = {0};
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if (s[i] != s[j]){
                cnt[s[i] - '0'] += 1;
            }
        }
    }

    const int delta1 = n, delta2 = c0 * c1;
    memset(dp, 0x3f, sizeof dp);
    memset(ndp, 0x3f, sizeof ndp);
    dp[delta1][delta2] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= 2 * delta1; j++){
            for(int k = 0; k <= 2 * delta2; k++){
                ndp[j][k] = dp[j][k];
            }
        }
        if (s[i] == '0'){
            for(int j = 0; j + 1 <= 2 * delta1; j++){
                for(int k = 0; k + i <= 2 * delta2; k++){
                    ndp[j + 1][k + i] = min(ndp[j + 1][k + i], dp[j][k] + 1);
                }
            }
        }
        else{
            for(int j = 1; j <= 2 * delta1; j++){
                for(int k = i; k <= 2 * delta2; k++){
                    ndp[j - 1][k - i] = min(ndp[j - 1][k - i], dp[j][k]);
                }
            }
        }
        swap(dp, ndp);
    }
    cout << dp[delta1][delta2 - (cnt[0] - cnt[1]) / 2] << '\n';

}