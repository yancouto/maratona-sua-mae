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

int l, v1, v2, t, s;

//int solve(double a) {
//	double le = v1, ri = v2;
//	int k = 0;
//	while(ri - le > t) {
//		k++;
//		double v = le + (ri - le) * a;
//		double ks = double(k)  * double(s);
//		double x = v * ks;
//		if(x > l) x = l;
//		if(x / ks <= le) return INT_MAX;
//		le = x / ks;
//	}
//	return k;
//}
//
//int solve2(double a) {
//	double le = v1, ri = v2;
//	int k = 0;
//	while(ri - le > t) {
//		k++;
//		double v = le + (ri - le) * a;
//		double ks = double(k)  * double(s);
//		double x = v * ks;
//		if(x > l) {
//			x = l;
//			if(ri - (x / ks) > t) return INT_MAX;
//			if((x / ks) - le
//		}
//		ri = x / ks;
//	}
//	return k;
//}

bool ok(ll k) {
	if(ll(t) * k - ll(v2) >= 0) return true;
	return log(l) >= log(s) + log(k) + log(ll(v2) - ll(t) * k);
}

int main() {
	for_tests(tn, tt) {
		scanf("%d %d %d %d %d", &l, &v1, &v2, &t, &s);
		if(v2 - v1 <= t) { puts("0"); continue; }
		int le = 1, ri = (v2 - v1) / t;
		if(ri == 1) {
			if(ll(t) * ll(s) - ll(v2) * ll(s) + ll(l) >= 0) puts("1");
			else puts("impossible");
			continue;
		}
		if(ri * t == (v2 - v1)) ri--;
		int k1 = v2 / t;
		int k2 = (v2 + t - 1) / t;
		int o1, o2;
		if(le <= k1 && k2 <= ri) {
			o1 = k1; o2 = k2;
		} else if(ri < k2) {
			o1 = o2 = ri;
		} else {
			o1 = o2 = le;
		}
		if(ok(o1) && ok(o2)) printf("%d\n", ri);
		else puts("impossible");
	}
}
