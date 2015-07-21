//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>
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

ull n, k;
vector<ull> p, exp;

void gen_prime() {
   ull N = k;
   if(N%2 == 0) {
      p.pb(2);
      ull c = 0;
      while(N%2 == 0) {
         c++;
         N/=2;
      }
      if(c != 0) exp.pb(c);
   }
   for(ull i=3; i*i <= k; i+=2) {
      if(N%i == 0) {
         p.pb(i);
         ull c = 0;
         while(N%i == 0) {
            c++;
            N/=i;
         }
         if(c != 0) exp.pb(c);
      }
   }
   if(N > 2) {
      p.pb(N);
      exp.pb(1);
   }
}

ull min(ull a, ull b) {
   if(a < b) return a;
   return b;
}

int main() {
   int t;
   scanf("%d", &t);
   while(t--) {
      scanf("%llu %llu", &n, &k);
      p.clear();
      exp.clear();
      gen_prime();
  
      ull ans = ULLONG_MAX;
      ull ov = ULLONG_MAX;
      for(ull i=0; i<p.size(); i++) {
         ull pr = p[i];
         ull count = 0;
         while(n/pr) {
            count += n/pr;
            if(pr > ov/p[i]) break; //checa overflow
            pr *= p[i];
         }
         ans = min(ans, count/exp[i]);
      }
      printf("%llu\n", ans);  
   }
   return 0;
}
