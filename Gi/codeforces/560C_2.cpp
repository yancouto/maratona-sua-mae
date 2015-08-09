
//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
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

ull a, b, c, d, e, f;

ull calc(ull side){
	if(side == 1) return 1;
	return 2*side - 1 + calc(side-1);
}

int main(){
	scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f);
	printf("%lld\n", calc(f+a+b) - calc(b) - calc(f) - calc(d));  
	return 0;
}
