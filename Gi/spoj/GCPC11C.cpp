//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

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

int n, h, rV;
int dg[10005], seen[10005];
vector<int> g[10005], ot;

int ord_top(queue<int> f) {
   int recheck=0, missing=0;
   while(!f.empty()) {
      if(f.size()>1) missing=1;  
      int v=f.front();
      ot.pb(v);
      f.pop();
      seen[v]=1;
      rV++;
      for(int i=0; i<g[v].size(); i++) {
         int u=g[v][i];
         if(seen[u]) continue;
         dg[u]--;
         if(!dg[u]) 
            f.push(u);
      }  
   }
   if(rV!=n) recheck=1;
   return (recheck?2:(missing));
}

int main() {
   int t;
   scanf("%d", &t);
   while(t--) {
      queue<int> f;
      memset(dg, 0, sizeof dg);
      memset(seen, 0, sizeof seen);
      ot.clear();
      scanf("%d%d", &n, &h);
      for(int i=0; i<n; i++)
         g[i].clear();
      for(int i=0; i<h; i++) {
         int u, v;
         scanf("%d%d", &u, &v);
         u--; v--;
         g[u].pb(v);
         dg[v]++;
      }
      for(int i=0; i<n; i++)
         if(dg[i]==0) 
            f.push(i);
         
      rV=0;
      int ans=ord_top(f);
      if(ans==2)
         printf("recheck hints\n");
      else if(ans)
         printf("missing hints\n");
      else {
         for(int i=0; i<ot.size(); i++)
            printf("%d ", ot[i]+1);
         printf("\n");
      } 
   }
   return 0;
}
