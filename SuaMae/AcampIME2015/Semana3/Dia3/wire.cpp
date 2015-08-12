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
const int MAX = 1009;
int ci[MAX], cj[MAX], cr[MAX], cb[MAX];
int n, m, k;
int line[300000];

bool inside(ll i, ll j, ll ci, ll cj, ll cr) {
	return ((i-ci)*(i-ci))+((j-cj)*(j-cj)) <= cr*cr;
}

int getleft(int i, int ci, int cj, int cr) {
	int l = 0, r = cj;
	while(l < r) {
		int mid = (l + r) / 2;
		if(inside(i, mid, ci, cj, cr)) r = mid;
		else l = mid + 1;
	}
	return l;
}

int getright(int i, int ci,  int cj, int cr) {
	int l = cj, r = m;
	while(l < r) {
		int mid = (l + r + 1) / 2;
		if(inside(i, mid, ci, cj, cr)) l = mid;
		else r = mid - 1;
	}
	return l;
}

int main() {
	int i, j, x;
	scanf("%d %d %d", &m, &n, &k);
	for(i = 0; i < k; i++) {
		scanf("%d %d %d %d", &ci[i], &cj[i], &cr[i], &cb[i]);
		ci[i]--; cj[i]--;
	}
	int mb = 0, ms = 0;
	for(i = 0; i < n; i++) {
		memset(line, 0, sizeof line);
		for(j = 0; j < k; j++) {
			if(abs(i - ci[j]) > cr[j]) continue;
			line[getleft(i, ci[j], cj[j], cr[j])] += cb[j];
			line[getright(i, ci[j], cj[j], cr[j])+1] -= cb[j];
		}
		int b = 0;
		for(j = 0; j < m; j++) {
			b += line[j];
			if(b > mb) {
				mb = b;
				ms = 1;
			} else if(b == mb) ms++;
		}
	}
	printf("%d\n%d\n", mb, ms);

}
