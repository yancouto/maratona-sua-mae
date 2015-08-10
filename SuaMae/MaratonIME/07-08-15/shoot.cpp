#include <cstdio>
#include <algorithm>
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
ld eps = 1e-7;
int n;
ld p[15];
int hit[15];
ld allmiss;
ld memo[14][14][10000][14];
ld s(int ind, int t, int bm, int last) {
	int alive = __builtin_popcount(bm);
	if(alive == 1) return bm == (1 << ind);
	if(!(bm & (1 << ind))) return 0;
	if(last == t) return 0;
	ld &r = memo[ind][t][bm][last];
	//printf("heyo(%d, %d, %d) %Lf\n", ind, t, bm, r);
	if(r > -.5) return r;
	//puts("heyo2");
	//puts("heyo33");
	r = -1;
	ld ans = 0, maxval = -1;
	int anss = 0;
	for(int i = 0; i < n; i++) {
		if(!(bm & (1 << i))) continue;
		if(i == t) continue;
		int j, j2;
		int nbm = bm ^ (1 << i);
		for(j = t + 1; !(nbm & (1 << (j%n))); j++);
		ld ansv = p[t] * s(ind, j%n, nbm, 13);
		if(hit[t] == 100) ansv = s(ind, j%n, nbm, 13);
		ld anst = p[t] * s(t, j%n, nbm, 13);
		if(hit[t] == 100) anst = s(t, j%n, nbm, 13);
		if(anst > maxval + eps) {
			maxval = anst;
			ans = ansv;
			anss = 1;
		} else if(maxval >= anst - eps && maxval <= anst + eps) {
			ans = (ans * anss + ansv) / (anss + 1);
			anss++;
		}
	}
	int j2;
	for(j2 = t + 1; !(bm & (1 << (j2%n))); j2++);
	ans += (1. - p[t]) * s(ind, j2%n, bm, last == 13? t : last);
	ld am = 1;
	for(int i = 0; i < n; i++)
		if(bm & (1 << i))
			am *= (1. - p[i]);
	if(am >= 1 - eps) return r = 1;
	//printf("am = %Lf\n", am);
	r = ans / (1. - am);
	//printf("s(%d, %d, %d) = %Lf\n", ind, t, bm, r);
	return r;
}

int main() {
	int i, x, j, k, l;
	for_tests(t, tt) {
		scanf("%d", &n);
		allmiss = 1;
		for(i = 0; i < n; i++) {
			scanf("%d", &x);
			hit[i] = x;
			p[i] = x / 100.;
			allmiss *= (1 - p[i]);
			for(j = 0; j < n; j++)
				for(k = 0; k < (1 << n); k++)
					for(l = 0; l < 14; l++)
						memo[i][j][k][l] = -2;
		}
		//printf("allmiss %Lf\n", allmiss);
		if(allmiss >= 1 - eps) {
			for(i = 0; i < n; i++)
				printf("100.00 ");
			printf("\n");
			return 0;
		}
		for(i = 0; i < n; i++)
			printf("%.2Lf ", 100. * s(i, 0, (1 << n) - 1, 13));
		printf("\n");
	}
	return 0;
}
