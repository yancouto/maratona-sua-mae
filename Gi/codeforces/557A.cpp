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

int main(){
	int n, min1, max1, min2, max2, min3, max3;
	scanf("%d", &n);
	scanf("%d %d %d %d %d %d", &min1, &max1, &min2, &max2, &min3, &max3);
	int r1, r2, r3;
	r1 = min1; r2 = min2; r3 = min3;
	if(r1+r2+r3 < n){
		r1 = min(max1, r1 + n-(r1+r2+r3));
		if(r1+r2+r3 < n){
			r2 = min(max2, r2 + n-(r1+r2+r3));
			if(r1+r2+r3 < n){
				r3 = r3 + n - (r1+r2+r3);
			}
		}
	}
	printf("%d %d %d\n", r1, r2, r3); 
	return 0;
}
