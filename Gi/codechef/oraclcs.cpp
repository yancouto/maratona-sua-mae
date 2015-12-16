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
const int N = 110;

void show(int mm[N][N], int n, int m) {
	puts("---------------------");
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			printf("%d ", mm[i][j]);
		putchar('\n');
	}
}

int main() {
	for_tests(t, tt) {
		int n, m, i, j;
		vector<int> p[N];
		char s[N][N];
		scanf("%d", &n); 
		for(i = 0; i < n; i++) scanf("%s", s[i] + 1);
		m = strlen(s[0] + 1) + 1;
			
	}
	return 0;
}
