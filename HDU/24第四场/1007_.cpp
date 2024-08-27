#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(),(x).end()
using ll = long long;
using ull = unsigned long long;
typedef pair<int,int> PII;

const int N = 3e5 + 10, M = 1e6;
const int inf = 1e9;
int a[N],b[N];
mt19937 rd(time(0));

void solve() {
    int n,q;
    cin>>n>>q;
   // n=250000,q=250000;
    vector<int>a(n);
    vector<PII>b(n);
    multiset<int>se;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
       // a[i]=rd()%inf+1;
        sum+=a[i];
        se.insert(a[i]);
    }

    for(int i=0;i<n;i++){
        cin>>b[i].first;
// b[i].first=rd()%inf+1;
        b[i].second=i;
    }
    sort(b.begin(),b.end());
    while(q--)
    {
        int k;
        cin>>k;
       // k=rd()%n;
        int minn=*se.begin();
        int pos= upper_bound(b.begin(),b.end(), make_pair(minn,(int)0))-b.begin();
        for(int i=pos;i<n;i++){
            int p=(b[i].second-k+n)%n;
            if(b[i].first>a[p]){
                sum+=b[i].first-a[p];
                se.erase(se.lower_bound(a[p]));
                a[p]=b[i].first;
                se.insert(a[p]);
            }
        }
        cout<<sum<<"\n";
    }

}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("out.txt","w",stdout);
    int t = 2;
    cin >> t;
    while (t--) {
        solve();
    }
//    cout<<"YES\n";
    return 0;
}