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

char A[1010], B[1010];
int n;
int prep[1010][1010], memo[1010][1010];

void pre() {
   for(int i=n; i >= 0; i--)
      prep[i][n] = prep[n][i] = 0;
   for(int i=n-1; i >= 0; i--) {
      for(int j=n-1; j >= 0; j--) {
         if(abs(A[i]-B[j]) <= 1)
            prep[i][j] = 1 + prep[i+1][j+1];
         else
            prep[i][j] = 0;
      }
   }  
}

int solve() {
   for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++) 
         if(prep[i][j]*2 >= n) return 1;
   return 0;
}

int main() {
   int t;
   scanf("%d", &t);
   while(t--) {
      scanf("%d", &n);
      scanf("%s %s", A, B);
      pre();
      if(solve())
         puts("POSITIVE");
      else
         puts("NEGATIVE");
   }
   return 0;
}
