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

int h, w;
int d, f, b;
int tab[55][55];
int acc[55][55];

void pre() {
	memset(acc, 0, sizeof acc);
	for(int i = 1; i <= h; i++) {
		for(int j = 1; j <= w; j++) 
			acc[i][j] = acc[i-1][j] + acc[i][j-1] - acc[i-1][j-1] + tab[i][j];
	}
}

void show() {
	for(int i = 1; i <= h; i++) {
		for(int j = 1; j <= w; j++)
			printf("%d ", acc[i][j]);
		putchar('\n');
	}
}


int main() {
	int t; scanf("%d", &t);
	while(t--) {
		memset(tab, 0, sizeof tab);
		scanf("%d %d", &w, &h);
		scanf("%d %d %d", &d, &f, &b);
		for(int i = 1; i <= h; i++) 
			for(int j = 1; j <= w; j++) {
				char c; scanf(" %c", &c);
				if(c == '.') tab[i][j] = 1;
			}
		pre();
		int ans = acc[h][w] * f;
		for(int i = 2; i < h; i++)
			for(int j = 2; j < w; j++) 
				for(int ii = i; ii < h; ii++)
					for(int jj = j; jj < w; jj++) {
						int sz = (ii - i + 1) * (jj - j + 1);
						int hv = acc[ii][jj] - acc[i-1][jj] - acc[ii][j-1] + acc[i-1][j-1];
						int cost = (sz - hv) * d;
						cost += (acc[h][w] - hv) * f;
						cost += 2 * (ii - i + 1) * b + 2 * (jj - j + 1) * b;
						if(i == 2 && j == 2 && ii == 3 && jj == 4) {
							printf("sz %d hv %d cavei %d preenchi %d borda %d cost %d\n", sz, hv, sz-hv, acc[h][w]-hv, 2 * (ii-i+1) + 2 * (jj-j+1), cost);
						}
						ans = min(ans, cost);
					}
		printf("%d\n", ans);
	}
	return 0;
}
