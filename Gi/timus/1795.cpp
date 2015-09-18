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

int n, m;
int ans = 0;
int pro[1005];

struct husb {
	int i, v, w;
	husb(int i, int v, int w) : i(i), v(v), w(w) {}
};

map<string, int> mp;
deque<husb> line;

int main() {
	char s[30], of[5];
	int am;
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		scanf("%d %s %s", &am, of, s);
		mp[string(s)] = i + 1;
		pro[i+1] = am;
	}
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %s %s", &am, of, s);
		int ind = mp[string(s)];
		line.pb(husb(ind, am, 0)); 
	}
	line.pb(husb(-1, 0, 0));
	while(42) {
		husb cur = line.front();
		line.pop_front();
		if(cur.i == -1) break; 
		ans++;
		if(!pro[cur.i]) continue;
		if(cur.v <= pro[cur.i]) pro[cur.i] -= cur.v;
		else if((!cur.w && cur.v > pro[cur.i]) || (cur.w && cur.w != pro[cur.i])) {
			cur.w = pro[cur.i];
			if(line.size()) {
				husb aux = cur;
				cur = *(line.begin());
				*(line.begin()) = aux;
			}
			line.push_front(cur);
		}
		else if(cur.w && cur.w == pro[cur.i]) 
			pro[cur.i] = 0;
	}
	printf("%d\n", ans);
	return 0;
}
