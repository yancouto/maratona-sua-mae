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
const int N = 20009, Q = 5009;
int S[N], sz[N];
int find(int i) {
	if(S[S[i]] != S[i]) S[i] = find(S[i]);
	return S[i];
}
void join(int a, int b) {
	if((a = find(a)) == (b = find(b))) return;
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	S[b] = a;
}
int a[Q], b[Q]; char op[Q];
int p[N], bad[N];

int main() {
	int i, n, k;
	for_tests(t, tt) {
		scanf("%d %d", &n, &k);
		for(i = 0; i < n; i++) {
			scanf("%d", &p[i]); p[i]--;
			S[i] = i; sz[i] = 1;
		}
		memset(bad, 0, sizeof bad);
		for(i = 0; i < k; i++) {
			scanf(" %c %d", &op[i], &a[i]); a[i]--;
			if(op[i] == 'C') bad[a[i]]++;
			else {
				scanf("%d", &b[i]);
				b[i]--;
			}
		}
		for(i = 0; i < n; i++)
			if(p[i] >= 0 && !bad[i])
				join(i, p[i]);
		int ok[Q], on = 0;
		for(i = k - 1; i >= 0; i--) {
			if(op[i] == 'C') {
				bad[a[i]]--;
				if(!bad[a[i]] && p[a[i]] >= 0) { join(a[i], p[a[i]]); }
			} else
				ok[on++] = (find(a[i]) == find(b[i]));
		}
		printf("Case #%d:\n", tt);
		while(on)
			puts(ok[--on]? "YES" : "NO");
	}
}
