#include<bits/stdc++.h>
 
using namespace std;
int h1[10], h2[10],s1[10];
int a1[10], a2[10],s2[10];
int n, m;
//p2 A，s2 B
double p1, p2, sum;
void bfs(int a, double ps, int c, int d) {
	//cout << ps << "???" << a << endl;
//	cout<<c<<"???"<<d<<endl;
	if (c == 0 && d == 0) {
		sum += ps;
		return ;
	}
	if (c == 0) {
		p2 += ps;
		return ;
	}
	if (d == 0) {
		p1 += ps;
		return ;
	}
	//a->b;
	if (a == 0) {
		int t = 0;
		//左边第一个活着的
		for (int i = 1; i <= n; i++)
			if (h1[i]>0&&(t==0||s1[t]>s1[i])) {
				t = i;
				//break;
			}
			s1[t]++;
			//cout<<t<<"!!!"<<endl;
		//攻击组合h2:B,h1:A
	//n1 A,m1 B
		int n1 = c, m1 = d;
		for (int i = 1; i <= m; i++) {
			if(h2[i]<=0)continue;
				h2[i] -= a1[t];	//s1[t]++;
				h1[t] -= a2[i];//s2[i]++;
				if (h1[t] <= 0) n1--;
				if (h2[i] <= 0) m1--;
				bfs(1 - a, ps * 1.0 / d, n1, m1);
				if (h1[t] <= 0) n1++;
				if (h2[i] <= 0) m1++;
				h2[i] += a1[t]; //s1[t]--;
				h1[t] += a2[i];	//s2[i]--;
		}
		s1[t]--;
	
	} 
	//b->a
	else {
		//左边第一活着的
		int t = 0;
		for (int i = 1; i <= m; i++)
			if (h2[i]>0&&(t==0||s2[t]>s2[i])) {
				t = i;
			//	break;
			}
			s2[t]++;
		int n1 = c, m1 = d;
		//依次攻击a中活着的
		for (int i = 1; i <= n; i++) {
			if (h1[i]>0) {
				h1[i] -= a2[t];//
				h2[t] -= a1[i];//s1[i]++;
				if (h1[i] <= 0) n1--;
				if (h2[t] <= 0) m1--;
				bfs(1 - a, ps * 1.0 / c, n1, m1);
				if (h1[i] <= 0) n1++;
				if (h2[t] <= 0) m1++;
				//st[i]=st2[t]=0;
				h1[i] += a2[t];//s2[t]--;
				h2[t] += a1[i];//s1[i]--;
			}
		}
		s2[t]--;
	}
}
int main () {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> h1[i], a1[i] = h1[i];
	for (int i = 1; i <= m; i++)cin >> h2[i], a2[i] = h2[i];
	if (n < m)bfs(1, 1, n, m);
	else if (n > m)bfs(0, 1, n, m);
	else {
		bfs(1, 0.5, n, m);
		bfs(0, 0.5, n, m);
	}
	cout<<
	cout<<p1<<endl<<p2<<endl<<sum<<endl;
}