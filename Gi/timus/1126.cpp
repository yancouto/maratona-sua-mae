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
	int m, a;
	vector<int> v;
	map<int, int> mp;
	map<int, int>::iterator it;
	scanf("%d", &m);
	while(42) {
		scanf("%d", &a);
		if(a == -1) break;
		v.pb(a);
		if(v.size() <= m)
			mp[a]++;
	}
	v.pb(-1);
	int lst = 0;
	for(int i = m; i < v.size(); i++) {
		it = mp.end(); --it;
		printf("%d\n", it->fst);
		mp[v[lst]]--; 
		if(mp[v[lst]] == 0) mp.erase(v[lst]);
		lst++;
		mp[v[i]]++;;
	}
	return 0;
}
