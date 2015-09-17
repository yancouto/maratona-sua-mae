#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
const int oo = 1000000000;

int T, w, n;
int memo[35][1005];
pii v[35];

int solve(int i, int t) {
	if(t > T) return -oo; 
	if(i == n) return 0;
	int &m = memo[i][t];
	if(m != -1) return m;
	m = solve(i + 1, t);
	m = max(m, v[i].snd + solve(i + 1, t + 3 * w * v[i].fst)); 
	return m;
}

vector<int> ans;
void build(int i, int t) {
	if(t > T) return ; 
	if(i == n) return ;
	int m = solve(i, t);
	if(m == solve(i + 1, t)) build(i + 1, t);
	else {
		ans.pb(i);
		build(i + 1, t + 3 * w * v[i].fst);
	}
}

int main() {
	int tt = 1;
	while(scanf("%d %d", &T, &w) != EOF) {
		if(tt > 1) putchar('\n');
		memset(memo, -1, sizeof memo);
		scanf("%d", &n);
		for(int i = 0; i < n; i++) 
			scanf("%d %d", &v[i].fst, &v[i].snd);
		printf("%d\n", solve(0, 0));	
		build(0, 0);
		printf("%d\n", ans.size());
		for(int i = 0; i < ans.size(); i++) 
			printf("%d %d\n", v[ans[i]].fst, v[ans[i]].snd);
		ans.clear();
		tt++;
	}
	return 0;
}
