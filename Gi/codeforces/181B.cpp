#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

pii p[3005];
int c[3000][3000];

int main() {
	int n, i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d %d", &p[i].x, &p[i].y);
		c[p[i].x + 1000][p[i].y + 1000] = 1;
	}
	int ans = 0;
	for(i = 0; i < n; i++) {
		for(j = i + 1; j < n; j++) {
			if((p[i].x + p[j].x) % 2 || (p[i].y + p[j].y) % 2) continue; 				
			if(c[(p[i].x + p[j].x) / 2 + 1000][(p[i].y + p[j].y) / 2 + 1000]) ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
