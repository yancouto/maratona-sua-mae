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
int n;
int dist[102];
char d[103][103];
int bfs(int s, int t) {
	memset(dist, -1, sizeof dist);
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	while(!q.empty()) {
		int x = q.front(); q.pop();
		for(int i = 0; i < n; i++) {
			if(d[x][i] == 'N') continue;
			if(dist[i] != -1) continue;
			q.push(i); dist[i] = dist[x] + 1;
			if(i == t) return dist[i];
		}
	}
	return -1;
}
int r;
double memo[10004][102];
double solve(int m, int k) {
	if(m < 0) return 0;
	if(k == 0) return 1;
	double &p = memo[m][k];
	if(p > -.5) return p;
	p = 0;
	for(int i = 1; i <= r; i++)
		p += solve(m - i, k - 1);
	p /= r;
	return p;
}

int main() {
	int i, j, c, a, b, m;
	for_tests(t, tt) {
		scanf("%d %d", &n, &r);
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				scanf(" %c", &d[i][j]);
		for(i = 0; i < 10003; i++)
			for(j = 0; j < n; j++)
				memo[i][j] = -1;
		scanf("%d", &c);
		printf("Case %d\n", tt);
		for(i = 0; i < c; i++) {
			scanf("%d %d %d", &a, &b, &m);
			int d = bfs(--a, --b);
			printf("%.6f\n", solve(m, d));
		}
		putchar('\n');
	}

}
