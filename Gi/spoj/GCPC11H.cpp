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
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

int n, t;
int c[100005][2][2];
ull memo[100005][2][2];

ull solve(int i, int be, int fst) {
   ull &m = memo[i][be][fst];
   if(m != -1) return m;
   if(i == n-1) m = c[i][!be][fst];
   else m = min(solve(i + 1, 0, fst) + c[i][!be][0], solve(i + 1, 1, fst) + c[i][!be][1]);
   return m; 
}

void build(int i, int be, int fst) {
   if(be) printf("B");
   else printf("F");
   if(i == n-1) return;
   int ans = solve(i, be, fst);
   if(ans == solve(i + 1, 0, fst) + c[i][!be][0])
      build(i + 1, 0, fst);
   else
      build(i + 1, 1, fst);
   return;
}

int main() {
   int tt;
   scanf("%d", &tt);
   while(tt--) {
      scanf("%d%d", &n, &t);
      ull tme=0;
      int x;
      for(int i=0; i<n; i++) {
         scanf("%d", &x);
         tme+=x;
         for(int k=0; k<2; k++)
            for(int j=0; j<2; j++) {
               memo[i][k][j]=-1;
               scanf("%d", &c[i][k][j]);
            }
      }
      if(tme>t) printf("IMPOSSIBLE\n");
      else { 
         ull ans1 = solve(0, 0, 0);
         ull ans2 = solve(0, 1, 1);
         if(ans1+tme > t && ans2+tme > t)
            printf("IMPOSSIBLE");
         else if(ans1 < ans2)
            build(0, 0, 0);
         else
            build(0, 1, 1);     
         printf("\n");
      }
   }   
   return 0;
}
