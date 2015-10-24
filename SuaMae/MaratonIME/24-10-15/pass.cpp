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

int k, sz[2];
char g[2][7][7];
string v[2][8000];
char s[6];


void pre(int j, int op) {
	if(j == 5) {
		s[j] = '\0';
		v[op][sz[op]++] = string(s);
		return;
	}
	for(int i = 0; i < 6; i++) {
		s[j] = g[op][j][i];
		pre(j+1, op);
	}
}

int main() {
	for_tests(t, tt) {
		int i, j, r;
		sz[0] = sz[1] = 0;
		scanf(" %d", &k);
		for(r = 0; r < 2; r++)
			for(i = 0; i < 6; i++)
				for(j = 0; j < 5; j++)
					scanf(" %c", &g[r][j][i]);
		for(r = 0; r < 2; r++)
			for(j = 0; j < 5; j++) 
				sort(g[r][j], g[r][j] + 6);
		pre(0, 0); 
		pre(0, 1); 
		for(i = 1; i < sz[0]; i++)
			assert(v[0][i-1] <= v[0][i]);
		for(i = 1; i < sz[1]; i++)
			assert(v[1][i-1] <= v[1][i]);
		sz[0] = unique(v[0], v[0] + sz[0]) - v[0];
		printf("%d %d\n", sz[0], sz[1]);
		j = 0; 
		for(i = 0; i < sz[0]; i++) {
			while(j < sz[1] && v[1][j] < v[0][i]) j++;
			if(j < sz[1] && v[1][j] == v[0][i]) k--;
			if(!k) break;
		}
		if(!k) printf("%s\n", v[0][i].c_str());
		else printf("NO\n");
	}
	return 0;
}
