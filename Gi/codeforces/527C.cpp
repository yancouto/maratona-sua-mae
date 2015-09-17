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

int abs(int a) { if(a < 0) return -a; return a; }

struct Comp {
	bool operator()(pii a, pii b) {
		if(abs(a.snd - a.fst) == abs(b.snd - b.fst)) {
			if(a.fst == b.fst) 
				return a.snd > b.snd;
			return a.fst > b.fst;
		}
		return abs(a.snd - a.fst) > abs(b.snd - b.fst);
	}
};

int w, h, n;
set<int> ver, hor;
set<pii, Comp> parv, parh;

int main() {
	scanf("%d %d %d", &w, &h, &n);
	ver.insert(0); ver.insert(h);
	hor.insert(0); hor.insert(w);
	parv.insert(make_pair(0, h));
	parh.insert(make_pair(0, w));
	for(int i = 0; i < n; i++) {
		int x; char c; scanf(" %c %d", &c, &x);
		set<int> :: iterator it, itt;
		set<pii> :: iterator it1, it2;
		if(c == 'V') {
			hor.insert(x);
			it = hor.lower_bound(x);
			itt = it; it++; itt--;
			int l = (*itt), r = (*it); 
			it1 = parh.lower_bound(make_pair(l, r));
			parh.erase(it1);
			parh.insert(make_pair(l, x));
			parh.insert(make_pair(x, r));
		}
		else {
			ver.insert(x);
			it = ver.lower_bound(x);
			itt = it; it++; itt--;
			int l = (*itt), r = (*it); 
			it2 = parv.lower_bound(make_pair(l, r));
			parv.erase(it2);
			parv.insert(make_pair(l, x));
			parv.insert(make_pair(x, r));
		}
	    it1 = parv.begin();
	    it2 = parh.begin();
		printf("%lld\n",(ll)abs(it1->snd - it1->fst) * abs(it2->snd - it2->fst));
	}
	return 0;
}
