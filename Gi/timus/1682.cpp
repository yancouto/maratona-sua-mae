#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
#define MAX_N 200010

vector<int> op[MAX_N], op2[MAX_N];
int id[MAX_N], sz[MAX_N];

int find(int i) {
	if(id[i] != i) id[i] = find(id[i]);
	return id[i];
}

bool join(int i, int j) {
	int x = find(i);
	int y = find(j);
	if(x == y) return true;
	if(sz[x] > sz[y]) { sz[x] += sz[y]; id[y] = x; }
	else { sz[y] += sz[x]; id[x] = y; }
	return false;
}

int main() {
	ll k; scanf("%lld", &k);
	for(ll i = 1; i < MAX_N; i++) {
		id[i] = i; 
		sz[i] = 1;
		set<int> cur;			
		int aux = (i * i) % k;
		for(int x = 0; x < op[aux].size(); x++) 
			cur.insert(op[aux][x]);
		aux = i % k;
		for(int x = 0; x < op2[aux].size(); x++) 
			cur.insert(op2[aux][x]);
		if(!cur.empty()) {
			set<int> :: iterator x;
			for(x = cur.begin(); x != cur.end(); ++x) {
				if(join(i, (*x))) { 
					printf("%d\n", i); 
					return 0; 
				}
			}
		}
		op[(k - (i % k)) % k].pb(i);
		op2[(k - ((i * i) % k)) % k].pb(i);
	}
	printf("-1\n");
	return 0;
}
