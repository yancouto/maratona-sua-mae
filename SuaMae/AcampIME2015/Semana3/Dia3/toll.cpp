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
#ifndef ONLINE_JUDGE
#	define debug(args...) {fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");}
#else
#	define debug(args...) {}
#endif
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
int n;
vector<int> adj[257];

struct no {
	int v;
	int item;
	no() {}
	no(int a, int b) : v(a), item(b) {}
	bool operator < (const no& o) const { return item < o.item; }
};

int seen[256], tempo;
bool poss(int st, int end, char from, char to) {
	tempo++;
	priority_queue<no> pq;
	pq.push(no(from, st));
	while(!pq.empty()) {
		no x = pq.top();
		pq.pop();
		if(x.item < 0) return false;
		if(x.v == to) return x.item >= end;
		if(seen[x.v] == tempo) continue;
		seen[x.v] = tempo;
		for(int v : adj[x.v])
			if(seen[v] < tempo) {
				if(v >= 'a' && v <= 'z') pq.push(no(v, x.item - 1));
				else pq.push(no(v, x.item - (x.item + 19) / 20));
			}
	}
	return false;
}

int main() {
	int i, j, x, t = 0;
	char c1, c2;
	while(true) {
		scanf("%d", &n);
		if(n == -1) return 0;
		for(i = 0; i < 256; i++) adj[i].clear();
		for(i = 0; i < n; i++) {
			scanf(" %c %c", &c1, &c2);
			adj[c1].pb(c2);
			adj[c2].pb(c1);
		}
		scanf("%d %c %c", &x, &c1, &c2);
		int l = 0, r = 1000000;
		while(l < r) {
			int mid = (l + r) / 2;
			if(poss(mid, x, c1, c2)) r = mid;
			else l = mid + 1;
		}
		printf("Case %d: %d\n", ++t, l);
	}
}
