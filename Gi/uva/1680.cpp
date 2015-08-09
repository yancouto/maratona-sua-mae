#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#define inf 1000000000

using namespace std;

char s[1003];
int memo[1003][1003];
int n;

int solve (int i, int j) {
   if (i >= j) return 0;
   int &m = memo[i][j];
   if (m != -1) return m;

   int ans = inf;
   if (s[i] == s[j])
      ans = solve(i+1, j-1);
   else {
      ans = min(ans, 1 + solve(i+1, j));
      ans = min(ans, 1 + solve(i, j-1));
      ans = min(ans, 1 + solve(i+1, j-1));
   }
   return m = ans;
}

int main () {
   int t;
   scanf("%d", &t);
   int c = 0;
   while (t--) {
      memset(memo, -1, sizeof(memo));
      scanf("%s", s);
      n = strlen(s);
      printf("Case %d: %d\n", ++c, solve(0, n-1));            
   }
   return 0;
}

//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1680
