#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int MAX = 505;
const int oo = 100000000;
const int ndir = 8;

int n, m, bi, bj, ei, ej;
int tab[MAX][MAX];

bool isOK(int i, int j) { return i >= 0 && i < m && j >= 0 && j < n && tab[i][j]; }
int diri[ndir] = {1, -1, 1, 1, 0, 0, -1, -1};
int dirj[ndir] = {0, 0, 1, -1, 1, -1, 1, -1};

struct Quad {
	int i, j, tot, ch;
	Quad() {}
	Quad(int i, int j, int t, int c) : i(i), j(j), tot(t), ch(c) {}
	bool operator <(const Quad &e) const {
		if(e.ch == ch) return e.tot < tot;
		return e.ch < ch;
	}
};

int mark[MAX][MAX];
Quad dik() {
	priority_queue<Quad> pq;
	pq.push(Quad(bi, bj, 1, 0));
	while(!pq.empty()) {
		Quad no = pq.top(); 
		pq.pop(); 
		if(mark[no.i][no.j]) continue;
		mark[no.i][no.j] = 1;
		if(no.i == ei && no.j == ej) return no;
		for(int i = 0; i < ndir; i++) {
			int x = no.i + diri[i];
			int y = no.j + dirj[i];
			if(!isOK(x, y)) continue;
			if(mark[x][y]) continue;
			pq.push(Quad(x, y, no.tot+1, no.ch+(tab[no.i][no.j]!=tab[x][y])));			
		}
	}
	return Quad(0, 0, oo, oo);
}

int main() {
	char c;
	scanf("%d %d", &m, &n);
	scanf("%d %d %d %d", &bi, &bj, &ei, &ej);
	bi--; bj--; ei--; ej--;
	for(int	i = 0; i < m; i++)
		for(int j = 0; j < n; j++) {
			scanf(" %c", &c);
			tab[i][j] = c - '0';
		}
	Quad ans = dik();
	if(ans.ch == oo && ans.tot == oo) puts("0 0");
	else printf("%d %d\n", ans.tot, ans.ch);
	return 0;
}
