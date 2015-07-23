//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
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
#ifndef ONLINE_JUDGE
#	define debug(args...) {fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");}
#else
#	define debug(args...) {}
#endif
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
char a[200005], b[200005];
int na, nb;

bool comp(int ia, int fa, int ib, int fb) {
   if(ia == fa) return a[ia] == b[ib];
   if((fa-ia+1) % 2 == 1) {
      int k = ib;
      for(int i = ia; i <= fa; i++)
         if(a[i] != b[k++]) return false;
      return true;
   }
   int ma = (ia+fa) / 2;
   int mb = (ib+fb) / 2;
   return ((comp(ia, ma, ib, mb) && comp(ma+1, fa, mb+1, fb)) || (comp(ia, ma, mb+1, fb) && comp(ma+1, fa, ib, mb)));
}

int main() {
   scanf("%s %s", a, b);
   na = strlen(a);
   nb = strlen(b);
   if(comp(0, na-1, 0, nb-1))
      puts("YES");
   else
      puts("NO");
   return 0;
}
