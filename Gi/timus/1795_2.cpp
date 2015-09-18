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
map<string, int> mp;
queue<pii> wt;

void check() {
	pii cur = wt.front();
	ans++;
	if(cur.snd == pro[cur.fst] || !pro[cur.fst]) {
		pro[cur.fst] = 0;
		wt.pop();
	}
}

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
	bool put = false;
	for(int i = 0; i < n; i++) {
		scanf("%d %s %s", &am, of, s);
		int ind = mp[string(s)];
		int x = pro[ind];
		ans++;
		put = false;
		if(am <= pro[ind]) pro[ind] -= am;
		else if(pro[ind]) put = true;
		bool bef = false;
		if(!wt.empty()) {
			bef = true;
			check();
		}
		if(put) { 
			wt.push(pii(ind, x));
			if(bef) check();	
		}
	}
	printf("%d\n", ans);
	return 0;
}
