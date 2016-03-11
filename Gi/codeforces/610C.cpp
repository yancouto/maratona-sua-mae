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
const int N = 520;

char r[N][N];

int main() {
	int i, j, b, k;
	scanf("%d", &k);
	r[0][0] = r[0][1] = r[1][0] = '+';
	r[1][1] = '*'; b = 2;
	for(int kk = 2; kk <= k; kk++) {
		for(i = 0; i < b; i++)
			for(j = 0; j < b; j++) {
				r[i+b][j] = r[i][j+b] = r[i][j];
				if(r[i][j] == '+') r[i+b][j+b] = '*';
				else r[i+b][j+b] = '+';
			}
		b *= 2;
	}
	int tot = pow(2, k);
	for(i = 0; i < tot; i++) {
		for(j = 0; j < tot; j++)
			printf("%c", r[i][j]);
		putchar('\n');
	}
	return 0;
}
