#include<bits/stdc++.h>

#define int long long
//#define endl '\n'
using namespace std;

typedef pair<int, int> pii;
typedef array<int, 3> a3;
typedef array<int, 4> a4;
const int inf = 1e15, mod = 998244353;
//const int N = 2e5+10;
int qmi(int a, int k) {
    int res = 1 % mod;
    while (k) {
        if (k & 1)res = res * a % mod;
        a = a * a % mod;
        k >>= 1;
    }
    return res;
}

double pow(double a, double k) {
    double res = 1;
    while (k--) {
        res *= a;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 2);

    unordered_map<int, int> vis;

    vector<int> lg(n + 2), rg(n + 2);


    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j&&a[i]!=0&&a[j]%a[i]==0){
                a[j]=0;
            }
        }
    }


    for (int i = 1; i <= n; i++) {
        // cout<<a[i]<<' ';
        vis[a[i]]++;
    }
    // return;

    for (int i = 1; i <= n; i++) {
        lg[i] = __gcd(lg[i - 1], a[i]);
    }

    for (int i = n ; i >= 1; i--) {
        rg[i] = __gcd(rg[i + 1], a[i]);
    }

    if (vis.count(lg[n])) {
        cout << n - 1 << endl;
        return;
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         if (i == j)continue;
    //         if(a[j]==0)continue;
    //         int G = __gcd(lg[i - 1], rg[i + 1]);
    //         if (a[i] % a[j] != 0 and G % (a[i] % a[j]) == 0) {
    //             cout << n << endl;
    //             return;
    //         }
    //     }
    // }



    for (int i = 1; i <= n; i++) {
        vis[a[i]]--;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if(a[j]==0)continue;
            vis[a[i] % a[j]]++;
            int G = __gcd(__gcd(lg[i - 1], rg[i + 1]), a[i] % a[j]);
            if (vis.count(G) and vis[G] > 0) {
                cout << n << endl;
                return;
            }
            vis[a[i] % a[j]]--;
        }
        vis[a[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        int G = __gcd(lg[i - 1], rg[i + 1]);
        if (a[i]&&G > a[i]) {
            cout << n << endl;
            return;
        }
    }

    for (int i = 1; i <= n; i++) {
        vis[a[i]]--;
        int G = __gcd(lg[i - 1], rg[i + 1]);
        if (vis.count(G) && vis[G] > 0) {
            cout << n << endl;
            return;
        }
        vis[a[i]]++;
    }

    cout << n + 1 << endl;
}

signed main() {
    int EL_PSY_KONGROO = 1;
    cin >> EL_PSY_KONGROO;
    while (EL_PSY_KONGROO--) {
        solve();
    }

    // system("PAUSE");
}
/*

100
5
2 2 2 2 3

*/