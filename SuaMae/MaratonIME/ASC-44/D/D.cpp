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

struct cmp {
	bool operator () (char *a, char *b) {
		int eq = 0;
		for(int i = 0; i < 4; i++)
			eq += a[i] == b[i];
		if(eq >= 2) return false;
		return strncmp(a, b, 4) < 0;
	}
};

void mrk(ull b[], int i) {
	b[i >> 6] |= (1 << (i & 63));
}
int calc(ull bi[], ull bj[]) {
	int eq = 0;
	for(int g = 0; g < 7813; g++)
		eq += __builtin_popcountll(bi[g] & bj[g]);
	return eq;
}
ull bl[102][7815];


char str[102][20009];
int block[102], sz[102];
int eq[102][102];
int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int n, i, j, k;
	fgets(str[0], sizeof str[0], stdin);
	sscanf(str[0], "%d", &n);
	map<char*, int, cmp> s;
	for(i = 0; i < n; i++) {
		fgets(str[i], sizeof str[i], stdin);
		sz[i] = strlen(str[i]);
		str[i][--sz[i]] = 0;
		for(j = 0; j < sz[i]; j += 4)
			s[str[i] + j] = 0;
	}
	i = 0;
	for(auto &e : s)
		e.snd = i++;
	for(i = 0; i < n; i++)
		for(j = 0; j < sz[i]; j += 4)
			mrk(bl[i], s[str[i] + j]);
	int si, sj, p = -1;
	for(i = 0; i < n; i++)
		for(j = i; j < n; j++) {
			eq[j][i] = eq[i][j] = calc(bl[i], bl[j]);
			if(eq[i][j] > p) p = eq[i][j], si = i, sj = j;
		}
	block[si] = block[sj] = 1;
	for(i = 2; i < n / 2; i++) {
		int p = -1;
		for(j = 0; j < n; j++) {
			if(block[j]) continue;
			for(k = 0; k < n; k++) {
				if(!block[i]) continue;
				if(eq[j][k] > p) p = eq[j][k], si = j;
			}
		}
		block[si] = 1;
	}
	for(i = 0; i < n; i++)
		if(block[i]) puts("block");
		else puts("random");
}
