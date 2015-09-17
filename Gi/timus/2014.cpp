#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

struct Date {
	int v, d, m, h, mm;
	Date() {}
	Date(int v, int d, int m, int h, int mm) : v(v), d(d), m(m), h(h), mm(mm) {}
	bool operator < (const Date &a) const {
		return d * 25 * 65 + m * 35 * 25 * 65 + h * 65 + mm < a.d * 25 * 65 + a.m * 35 * 25 * 65 + a.h * 65 + a.mm;
	}
};

pll segt[300005];
vector<Date> info, ss;
map<Date, int> mp;
ll mmin(ll a, ll b) { if(a < b) return a; return b; }
ll mmax(ll a, ll b) { if(a > b) return a; return b; }

void update(int no, int b, int e, int pos, int x){
	if(b == e){
		if(x > 0) segt[no] = make_pair(x, 0);
		else segt[no] = make_pair(0, x);
		return ;
	}
	int mid = (b + e) / 2;
	if(pos <= mid) update(2*no, b, mid, pos, x);
	else update(2*no+1, mid+1, e, pos, x);
	pll bef = segt[2*no], aft = segt[2*no+1];
	pll now;
	now.fst = aft.fst + mmax(bef.fst + aft.snd, 0);
	now.snd = bef.snd + mmin(bef.fst + aft.snd, 0);
	segt[no] = now;
}

int main(){
	int n, d, m, h, mm, v;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d.%d %d:%d",	&v, &d, &m, &h, &mm);
		info.pb(Date(v, d, m, h, mm));
		ss.pb(Date(v, d, m, h, mm));
	}
	sort(ss.begin(), ss.end());
	for(int i = 0; i < ss.size(); i++) mp[ss[i]] = i + 1;
	for(int i = 0; i < info.size(); i++) {
		update(1, 1, n + 1, mp[info[i]], info[i].v);
		printf("%lld\n", segt[1].snd);
	}
	return 0;
}

