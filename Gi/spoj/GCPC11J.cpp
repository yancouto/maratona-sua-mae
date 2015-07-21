//#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
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

int seen[100005], dist[100005];
vector<int> g[100005];

int bfs(int o) {
   int u;
   queue<int> l;
   l.push(o);
   while(!l.empty()) {
      u=l.front();
      seen[u]=1;
      l.pop();
      for(int i=0; i<g[u].size(); i++) {
         int v=g[u][i];
         if(!seen[v])
            l.push(v);
      }  
   }
   memset(seen, 0, sizeof seen);
   l.push(u);
   dist[u]=0;
   int v;
   while(!l.empty()) {
      v=l.front();
      l.pop();
      seen[v]=1;
      for(int i=0; i<g[v].size(); i++) {
         int x=g[v][i];
         if(!seen[x]) {
            dist[x] = dist[v]+1;
            l.push(x);
         }
      }
   }
   
   return (dist[v]+1)/2;
}

int main() {
   int n, t;
   int dgin[100005];
   scanf("%d", &t);
   while(t--) {
      memset(dgin, 0, sizeof dgin);
      memset(seen, 0, sizeof seen);
      memset(dist, 0, sizeof dist);
      scanf("%d", &n);
      for(int i=0; i<n; i++)
         g[i].clear();
      for(int i=0; i<n-1; i++) {
         int u, v;
         scanf("%d%d", &u, &v);
         g[u].push_back(v);
         g[v].push_back(u);
         dgin[v]++;
      }
      int o;
      for(o=0; o<n && dgin[o]!=0; o++);
      printf("%d\n", bfs(o));
   }
   return 0;
}
