//#include <bits/stdc++.h>
#include<cstdio>
#include<algorithm>
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
#ifndef ONLINE_JUDGE
#	define debug(args...) {fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");}
#else
#	define debug(args...) {}
#endif
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

int main() {
   int a, b, c, d, e, f;
   scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
   printf("%d\n", (a+b+c)*(a+b+c) - (a*a+c*c+e*e)); 
   return 0;
}
