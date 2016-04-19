#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 100005;

map<int, int> mp;
map<int, vector<int> > w, d;
vector<int> aux, a[N];
pii v[N];
int lb[N];

int main() {
	int i, j, x, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++) 
		scanf("%d %d", &v[i].x, &v[i].y);
	sort(v, v + n);
	for(i = 0; i < n; i++) {
		mp[v[i].y-v[i].x]++;
		d[v[i].y-v[i].x].pb(i);
	}
	for(i = 0; i < n; i++) {
		scanf("%d", &x);
		mp[x]--;
		if(mp[x] < 0) { puts("NO"); return 0; } 
		w[x].pb(i);
	}
	for(i = -N; i <= N; i++) {
		aux = d[i];
		if(aux.empty()) continue;
		for(j = 0; j < aux.size(); j++)
			lb[aux[j]] = w[i][j];
	}
	for(i = 0; i < n; i++) 
		a[v[i].x].pb(lb[i]);
	for(i = 0; i < n; i++) {
		for(j = 0; j < a[i].size(); j++)
			if(a[i+1].size() > j && a[i][j] > a[i+1][j]) { puts("NO"); return 0; }
			else if(a[i].size() > j + 1 && a[i][j] > a[i][j+1]) { puts("NO"); return 0; }
	}
	puts("YES");
	int ans[N];
	for(i = 0; i < n; i++)
		ans[lb[i]] = i;
	for(i = 0; i < n; i++)
		printf("%d %d\n", v[ans[i]].x, v[ans[i]].y); 
	return 0;
}
