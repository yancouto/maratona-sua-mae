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
const int MAX = 26;

int N, np;
int v[MAX], p[MAX], cur[MAX], prec[2000][MAX];

int half(int n) { return n/2 + (n%2); }

bool comp(int i, int j) { return v[i] > v[j]; }

void add_comb() {
	for(int k = 0; k < half(N); k++)
		prec[np][k] = cur[k];  
	np++;
}

void brute(int i, int j) {
	if(i == half(N)) { add_comb(); return; }
	if(j == N) return;
	cur[i] = p[j];
	brute(i + 1, j + 1);
	brute(i, j + 1);
}

void show() {
	int i, j;
	for(i = 0; i < np; i++) {
		for(j = 0; j < half(N); j++)
			printf("%d ", prec[i][j]);
		putchar('\n');
	}
}

bool is_distinct(int i, int j) {
	bool seen[MAX];
	memset(seen, 0, sizeof seen);
	for(int k = 0; k < half(N); k++) {
		if(seen[prec[i][k]] || seen[prec[j][k]] || prec[i][k] == prec[j][k])
			return false;
		seen[prec[i][k]] = seen[prec[j][k]] = true;
	}
	return true;
}

int main() {
	int i, j, ii, jj;
	ll ans, sumi, sumj;
	while(42) {
		scanf("%d", &N);
		if(!N) break;
		ll tot = 0;
		for(i = 0; i < N; i++) {
			scanf("%d", &v[i]);
			p[i] = i; tot += v[i];
		}
		sort(p, p + N, comp); 
		brute(0, 0); show();
		for(i = 0; i < np; i++)
			for(j = i + 1; j < np; j++) {
					
			}
		printf("%lld\n", tot - ans);
	}
	return 0;
}
