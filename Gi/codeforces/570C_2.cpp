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
#define oo 1000000000
char s[3000005];
set<pii> st;
int ans;

void solve(int pos){
	set<pii>::iterator it;
	it = st.lower_bound(pii(pos, oo)); --it;
	int ini = it->fst;
	int fim = it->snd;
	ans -= max(0, fim-ini-1);
	ans += max(0, pos-1-ini);
	ans += max(0, fim-pos-2);
	st.erase(it);
	st.insert(pii(ini, pos));
	st.insert(pii(pos+1, fim)); 
}

int main(){
	int j, n, m;
	scanf("%d %d", &n, &m);
	scanf("%s", s);
	st.insert(pii(0, n));
	ans = n-1;
	for(int i = 0; i < n; i++){
		if(s[i] == '.') continue;
		solve(i);
	}
	for(int i = 0; i < m; i++) {
		int pos; char c;
		scanf("%d %c", &pos, &c); 
		pos--;
		if(s[pos] == '.' && c != '.') solve(pos);
		else if(s[pos] != '.' && c == '.') {
			set<pii>::iterator it, it2;
			it = st.lower_bound(pii(pos, oo));
			it2 = it; it--;
			pii p1 = *it;
			pii p2 = *it2;
			st.erase(it); st.erase(it2);
			ans -= max(0, p1.snd - p1.fst - 1);
			ans -= max(0, p2.snd - p2.fst - 1);
			ans += max(0, p2.snd - p1.fst - 1);
			st.insert(pii(p1.fst, p2.snd));
		}
		s[pos] = c;
		printf("%d\n", ans);
	}

	return 0;
}
