#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define pb push_back

int n;
long long dp[40][10];

vector <int> p[10];

int main (){
    p[0].pb(1);p[0].pb(4);p[0].pb(7);
    p[1].pb(0);p[1].pb(6);
    p[2].pb(5);
    p[3].pb(4);
    p[4].pb(0);p[4].pb(3);
    p[5].pb(2);
    p[6].pb(1);
    p[7].pb(0);
    dp[0][0]=1;
    for(int a=0;a<=30;a++){
        for(int bm=0;bm<=7;bm++){
            for(int c=0;c<p[bm].size();c++){
                dp[a+1][p[bm][c]]+=dp[a][bm];
            }
        }
    }
    while(scanf("%d", &n) && n!=-1){
        printf("%lld\n", dp[n][0]);
    }
    return 0;
}
