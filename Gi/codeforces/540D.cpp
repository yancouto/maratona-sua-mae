#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int R, S, P, r, s, p;
double memo[102][102][102];

double prob (int x, int y, int z) {
    return (double)(x*y)/(x*y + x*z + y*z);
}

/*double solve (int r, int s, int p) {
    if (s == 0 && p == 0) return 1.0;
    double &m = memo[r][s][p];
    int stop = 1;
    double ans = 0;
    if (r > 1 && p > 0) {
        stop = 0;
        ans += solve(r-1, s, p)*prob(r, p, s);
    } 
    if (s > 0 && r > 0) {
        stop = 0;
        ans += solve(r, s-1, p)*prob(s,r,p);
    }
    if (p > 0 && s > 0) {
        stop = 0;
        ans += solve(r, s, p-1)*prob(p,s,r);
    }
    if (stop) return 0;
    return m = ans;
}*/

void solve() {
    memo[r][s][p] = 1.0;
    memo[r+1][s][p] = memo[r][s+1][p] = memo[r][s][p+1] = 0.0;
    for (int i = r; i >= 0; i--){
        for (int j = s; j >= 0; j--){
            for (int k = p; k >= 0; k--) {
                if (j > 0) memo[i][j][k] += memo[i][j][k+1]*prob(j,k+1,i);
                if (i > 0) memo[i][j][k] += memo[i][j+1][k]*prob(i,j+1,k);
                if (k > 0) memo[i][j][k] += memo[i+1][j][k]*prob(i+1,k,j);
            }
        }      
    }
}

int  main () {	
    scanf("%d%d%d", &R, &S, &P);
    double a=0, b=0, c=0;
    r = R; s = S; p = P;
    solve();
    for (int i = 1; i <= R; i++)
        a += memo[i][0][0];
    for (int i = 1; i <= S; i++)
        b += memo[0][i][0];
    for (int i = 1; i <= P; i++)
        c += memo[0][0][i];
    printf("%.12f %.12f %.12f\n", a, b, c);
    return 0;
}

//http://codeforces.com/contest/540/problem/D
