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

vector<int> adj[4090];
int d[112345];
int maux[112345][10];
int aux(int pos, int D) {
	if(maux[pos][D]) return maux[pos][D];
	for(int dig = d[pos]; dig <= D; dig++)
		if(d[pos + dig + D + 2] == dig)
			return maux[pos][D] = pos + dig + D + 2;
	return maux[pos][D] = -1;
}

map<int, int> seen[4009];
int solve(int pos, int i) {
	if(seen[i].count(pos)) return seen[i][pos];
	for(int dig = d[pos]; ; dig++) {
		int nx = aux(pos, dig);
		if(nx < 0) continue;
		int tot = 0;
		for(int v : adj[i])
			tot += solve(nx + tot, v);
		if(d[nx + tot] == dig)
			return seen[i][pos] = nx + tot - pos;
	}
}

void build(int pos, int i) {
	for(int dig = d[pos]; ; dig++) {
		int nx = aux(pos, dig);
		if(nx < 0) continue;
		int tot = 0;
		for(int v : adj[i])
			tot += solve(nx + tot, v);
		if(d[nx + tot] == dig) {
			printf("%d,%d:", nx, nx + tot);
			tot = 0;
			for(int v : adj[i]) {
				build(nx + tot, v);
				tot += solve(nx + tot, v);
			}
			return;
		}
	}
}

int st[4009], sn;
char s[4009];
int main() {
	scanf("%s", s);
	int n = strlen(s), i;
	vector<int> o;
	for(i = 0; i < n; i++) {
		if(s[i] == ')') { sn--; continue; }
		if(sn) adj[st[sn - 1]].pb(i);
		else o.pb(i);
		st[sn++] = i;
	}
	for(i = 1; i < 112345; i++)
		d[i] = d[i / 10] + 1;
	d[0] = 1;
	int tot = 0;
	for(int v : o)
		tot += solve(tot, v);
	tot = 0;
	for(int v : o) {
		build(tot, v);
		tot += solve(tot, v);
	}
	putchar('\n');
}
