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

string v[2][30000];
int sz[2]; char s[30];
char g[5][10][10];
void gen(int p, int j) {
	if(j == 5) {
		s[5] = 0;
		v[p][sz[p]++] = s;
		return;
	}
	for(int i = 0; i < 6; i++) {
		s[j] = g[p][j][i];
		if(i == 0 || g[p][j][i-1] != g[p][j][i])
			gen(p, j + 1);
	}
}

int main() {
	int p, i, j, k;
	for_tests(t, tt) {
		scanf("%d", &k);
		sz[0] = sz[1] = 0;
		for(p = 0; p < 2; p++)
			for(i = 0; i < 6; i++)
				for(j = 0; j < 5; j++)
					scanf(" %c", &g[p][j][i]);
		for(p = 0; p < 2; p++)
			for(j = 0; j < 5; j++) {
				//printf("%.6s\n", g[p][j]);
				sort(g[p][j], g[p][j] + 6);
				//printf("%.6s\n\n", g[p][j]);
			}
		gen(0, 0);
		gen(1, 0);
		for(i = 1; i < sz[0]; i++)
			assert(v[0][i - 1] <= v[0][i]);
		for(i = 1; i < sz[1]; i++)
			assert(v[1][i - 1] <= v[1][i]);
		j = p = 0;
		for(i = 0; i < sz[0]; i++) {
			while(j < sz[1] && v[1][j] < v[0][i]) j++;
			if(j < sz[1] && v[0][i] == v[1][j]) v[0][p++] = v[0][i];
		}
		if(k <= p) printf("%s\n", v[0][k - 1].c_str());
		else puts("NO");
	}
}
