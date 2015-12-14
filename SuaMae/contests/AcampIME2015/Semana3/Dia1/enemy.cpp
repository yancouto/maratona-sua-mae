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
inline int count_1s(int x) { return __builtin_popcount(x); }
inline int count_1s(ull x) { return __builtin_popcountll(x); }
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
int en, n, m;
int si, sj, ei, ej;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int g[1003][1003];
struct pos {
	int i, j;
	pos() {}
	pos(int ii, int jj) : i(ii), j(jj) {}
	pos walk(int d) { return pos(i + dir[d][0], j + dir[d][1]); }
	bool legal() { return i >= 0 && i < n && j >= 0 && j < m; }
};

struct no {
	pos p;
	int dist;
	no() {}
	no(pos pp, int d) : p(pp), dist(d) {}
};
int seen[1003][1003], tempo;

inline int& s(pos &p) { return seen[p.i][p.j]; }
inline int& at(pos &p) { return g[p.i][p.j];  }

void guards(queue<no> &q) {
	while(!q.empty()) {
		no x = q.front();
		q.pop();
		for(int i = 0; i < 4; i++) {
			no y(x.p.walk(i), x.dist + 1);
			if(!y.p.legal()) continue;
			if(at(y.p) <= y.dist) continue;
			at(y.p) = y.dist;
			q.push(y);
		}
	}
}

int poss(int md) {
	if(g[si][sj] < md) return false;
	queue<no> q;
	q.push(no(pos(si, sj), 0));
	while(!q.empty()) {
		no x = q.front();
		q.pop();
		//printf("looking at (%d, %d)\n", x.p.i, x.p.j);
		if(x.p.i == ei && x.p.j == ej) return x.dist + 1;
		for(int i = 0; i < 4; i++) {
			no y(x.p.walk(i), x.dist + 1);
			if(!y.p.legal()) continue;
			if(s(y.p) == tempo) continue;
			if(at(y.p) < md) continue;
			s(y.p) = tempo;
			q.push(y);
		}
	}
	return 0;
}

int main() {
	int i, j, a, b;
	for_tests(t, tt) {
		scanf("%d %d %d", &en, &m, &n);
		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++)
				g[i][j] = INT_MAX;
		scanf("%d %d %d %d", &sj, &si, &ej, &ei);
		queue<no> q;
		for(i = 0; i < en; i++) {
			scanf("%d %d", &a, &b);
			q.push(no(pos(b, a), 0));
			g[b][a] = 0;
		}
		guards(q);
		//for(i = 0; i < n; i++) {
		//	for(j = 0; j < m; j++)
		//		printf("%d ", g[i][j]);
		//	printf("\n");
		//}
		int l = 0, r = 3000;
		while(l < r) {
			tempo++;
			int mm = (l + r + 1) / 2;
			if(poss(mm)) l = mm;
			else r = mm - 1;
		}
		tempo++;
		printf("%d %d\n", l, poss(l) - 1);
	}
	return 0;
}
