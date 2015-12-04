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

int n, m, i, j, ib, jb, ie, je;

int main() {
	char mat[55][55];
	scanf("%d %d", &n, &m);
	bool fst = true;
	for(i = 0; i < n; i++) 
		for(j = 0; j < m; j++) {
			scanf(" %c", &mat[i][j]);
			if(mat[i][j] == '*') { 
				if(fst) { ib = i; jb = j; fst = false; }
				ie = i; 
				je = max(je, j);
				jb = min(jb, j);
			}
		}
	for(i = ib; i <= ie; i++) {
		for(j = jb; j <= je; j++) 
			printf("%c", mat[i][j]);
		putchar('\n');
	}
	//xablau
	return 0;
}
