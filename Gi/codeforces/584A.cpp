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

int main() {
	int  n, t;
	scanf("%d %d", &n, &t);
	if(t == 10) {
		if(n == 1) { printf("-1\n"); return 0; }
		printf("1");
		for(int i = 1; i < n; i++)
			printf("0");
		printf("\n");
	}
	else {
		for(int i = 0; i < n; i++)
			printf("%d", t);
		putchar('\n');
	}
	return 0;
}
