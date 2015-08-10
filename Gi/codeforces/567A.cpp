
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

ull c[100005];
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%lld", &c[i]);
	for(int i = 0; i < n; i++){
		if(i == 0)
			printf("%lld ", c[i+1]-c[i]);
		else if(i == n-1)
			printf("%lld ", c[i]-c[i-1]);
		else
			printf("%lld ", min(c[i]-c[i-1], c[i+1]-c[i]));  
		printf("%lld\n", max(c[i]-c[0], c[n-1]-c[i]));
	}
	return 0;
}
