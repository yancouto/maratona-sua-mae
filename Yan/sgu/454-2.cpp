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
bool bl[9][9];
int iv[9][9], ih[9][9], x[100], cur[100], sz[100], cs[100], bm[100];
int n, m;
char g[9][9];

int w[100][8], st[10], sn;
void pre2(int i, int sz, int sum) {
	w[sum][sz]++;
	if(sz == 5 || i == 10) {
		do {

		} while(next_permutation(st, st + sz));
		return;
	}
	pre2(i + 1, sz, sum);
	st[sn++] = i;
	pre2(i + 1, sz + 1, sum + i);
	sn--;
}


char s[10];
int main() {
	srand(time(NULL));
	int i, j;
	pre();
	pre2(1, 0, 0);
	for(j = 1; j <= 45; j++) {
		int cur = 1;
		printf("[%2d] ", j);
		for(i = 1; i <= 5; i++) {
			cur *= i;
			printf("%5d ", w[j][i] * cur);
		}
		putchar('\n');
	}
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++) {
			iv[i][j] = i * 6 + j; ih[i][j] = i * 6 + j + 50;
			scanf("%s", s);
			if(s[0] != '.') bl[i][j] = true, g[i][j] = '_';
			else {
				st[sn++] = pii(i, j);
				iv[i][j] = iv[i - 1][j]; ih[i][j] = ih[i][j - 1];
				nv[i][j] = 10*nv[i - 1][j];
				sz[iv[i][j]]++; sz[ih[i][j]]++;
			}
			if(isdigit(s[0])) x[iv[i][j]] = atoi(s);
			if(isdigit(s[3])) x[ih[i][j]] = atoi(s + 3);
		}
	random_shuffle(st, st + sn);
	bt(0);
}
