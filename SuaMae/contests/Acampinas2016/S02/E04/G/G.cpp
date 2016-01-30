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
const int N = 200000, M = (200063 / 64), SQ = 500, Q = N / SQ;

ull pre[3][SQ][M];
int a[3][N], p[3][N];
ull o[3][M];
const int sz = 64 * M;


int main() {
	int i, j, sq, n, k;
	scanf("%d", &n);
	for(j = 0; j < 3; j++)
		for(i = 0; i < n; i++) {
			scanf("%d", &a[j][i]); a[j][i]--;
			p[j][a[j][i]] = i;
		}
	for(j = 0; j < 3; j++)
		for(sq = 0; sq < SQ; sq++)
			for(i = 0; i < (sq + 1) * (N / SQ); i++)
				pre[j][sq][a[j][i] >> 6] |= (1ull << (a[j][i] & 63));
	ull tot = 0;
	for(i = 0; i < n; i++) {
		for(j = 0; j < 3; j++) {
			const int pos = p[j][i];
			if(pos / Q) for(k = 0; k < M; k++) o[j][k] = pre[j][(pos / Q) - 1][k];
			else for(k = 0; k < M; k++) o[j][k] = 0ull;
			for(k = Q * (pos / Q); k < pos; k++)
				o[j][a[j][k] >> 6] |= (1ull << (a[j][k] & 63));
		}
		for(k = 0; k < M; k++) {
			o[0][k] &= (o[1][k] & o[2][k]);
			tot += __builtin_popcountll(o[0][k]);
		}
	}
	printf("%llu\n", tot);
}
