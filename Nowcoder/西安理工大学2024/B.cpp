#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    string a,b,c;
    getline(cin,a);
    getline(cin,b);
    getline(cin,c);
    map<array<string,3>,string>mp;
    mp[{"Vertebrates","Bird","Carnivores"}]="Eagle";
    mp[{"Vertebrates","Bird","Haunted Den"}]="Pigeons";
    mp[{"Vertebrates","Mamifero","Haunted Den"}]="People";
    mp[{"Vertebrates","Mamifero","Herbivorous"}]="Cow";
    mp[{"Invertebrates","Insect","Blood Devouring"}]="Fleas";
    mp[{"Invertebrates","Insect","Herbivorous"}]="Caterpillar";
    mp[{"Invertebrates","Wrinkle","Blood Devouring"}]="Leeches";
    mp[{"Invertebrates","Wrinkle","Haunted Den"}]="Worms";
    cout<<mp[{a,b,c}]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}