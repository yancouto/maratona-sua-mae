#include <cstdio>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
inline int count_1s(int x) { return __builtin_popcount(x); }
inline int count_1s(ull x) { return __builtin_popcountll(x); }
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000;
inline ull mod(ull x) { return x % modn; }
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif
int n;
int p[1009][2];

ull dist(int i, int j) {
	return ull(p[i][0] - p[j][0]) * ull(p[i][0] - p[j][0]) + ull(p[i][1] - p[j][1]) * ull(p[i][1] - p[j][1]);
}
int tempo;
int a[1000000];
inline int aa(ull x) { return mod(x * 4457 + 6449); }
int b[1000000];
inline int bb(ull x) { return mod(x * 7829 + 6547); }
int c[1000000];
inline int cc(ull x) { return mod(x * 18301 + 27647); }
int d[1000000];
inline int dd(ull x) { return mod(x * 36833 + 7); }
int e[1000000];
inline int ee(ull x) { return mod(x * 43867 + 73259); }
int siz;
void insert(ull x) {
	if(a[aa(x)] == tempo && b[bb(x)] == tempo && c[cc(x)] == tempo && d[dd(x)] == tempo && e[ee(x)] == tempo) return;
	a[aa(x)] = tempo;
	b[bb(x)] = tempo;
	c[cc(x)] = tempo;
	d[dd(x)] = tempo;
	e[ee(x)] = tempo;
	siz++;
}

int main() {
	int i, j; tempo = 0;
	for_tests(t, tt) {
		printf("Case %d: ", tt);
		scanf("%d", &n);
		for(i = 0; i < n; i++)
			scanf("%d %d", &p[i][0], &p[i][1]);
		siz = 0;
		tempo++;
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++)
				if(i != j) {
					insert(dist(i, j));
				}
		}
		printf("%d\n", siz + 1);
	}
	return 0;
}