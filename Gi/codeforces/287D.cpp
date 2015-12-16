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

int n, i, j, p[3000010];

int main() {
	scanf("%d", &n);
	for(i = 1; i <= n; i++) p[i] = i;
	for(i = 2; i <= n; i++) {
		int cur = p[i-1], ncur;
		for(j = i - 1; j <= n + i - 2; j += i) {
			ncur = p[j + i];
			if(j + i <= n + i - 2) p[j + i] = cur;
			else p[n + i - 1] = cur;
			cur = ncur;
		}
	}
	for(i = 1; i <= n; i++) printf("%d ", p[n-1+i]);
	putchar('\n');
	return 0;	
}
