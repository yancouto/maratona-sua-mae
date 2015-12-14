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
const int MAX = 105;

int id[MAX], sz[MAX];
map<int, int> mp;

int find(int v) {
	if(v == id[v]) return v;
	return id[v] = find(id[v]);
}

void join(int x, int y) {
	x = find(x); y = find(y);
	if(x == y) return;
	if(sz[x] > sz[y]) swap(x, y);
	sz[x] += sz[y];
	id[y] = x;
}

int abs(int x) {
	if(x < 0) return -x;
	return x;
}

int main() {
	for_tests(t, tt) {
		int n, k, dig; 
		scanf("%d %d", &n, &k);
		mp.clear();
		for(int i = 0; i < n; i++)
			sz[i] = 1, id[i] = i;
		for(int i = 0; i < n; i++) {
			scanf("%d", &dig);
			mp[i] = dig;
		}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++) {
				int n1 = mp[i], n2 = mp[j];
				if(find(i) == find(j)) continue;
				if(abs(n1-n2) <= k) join(i, j);
				
			}	
		int mark[MAX];
		memset(mark, 0, sizeof mark);
		for(int i = 0; i < n; i++) 
			mark[find(i)] = 1;
		int ans = 0;
		for(int i = 0; i < n; i++) 
			ans += mark[i];
		printf("Case #%d: %d\n", tt, ans);
	}
	return 0;
}
