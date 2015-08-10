#include <cstdio>
#include <cstring>

int N;
long long memo[25][10005];

long long solve (int c, int n) {
    long long ans = 0;
    if (n == 0) return 1;
    if (n < 0 || c*c*c > n) return 0;
    long long &m = memo[c][n];
    if (m != -1) return m;
    
    int v = c*c*c;
    ans += solve(c + 1, n);
    for (int i = 1; i <= n/v; i++)
        ans += solve(c + 1, n - i*v);
        
    m = ans;
    return ans;
}

int main () {
    memset(memo, -1, sizeof(memo));
    
    while (scanf("%d", &N) != EOF) 
        printf("%lld\n", solve(1, N));
    
    return 0;
}

//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2078

