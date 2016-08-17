#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define lld I64d
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int main() {
	int i, j, n;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++) {
		scanf("%d", &k[i]);
		for(j = 0; j < k[i]; j++) {
			scanf("%d", &a[i][j]);
			oc[a[i][j]].insert(i);
		}
	}
}
