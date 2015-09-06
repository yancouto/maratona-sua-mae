#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

int n;
long long dp[MAXN][2], c[MAXN], s[MAXN];

int main (){
    scanf("%d", &n);
    for(int a=0;a<n;a++){
        scanf("%lld", &s[a]);
        c[s[a]]++;
    }
    dp[100001][1]=dp[100001][0]=0;
    for(int a=100000;a>=0;a--){
        dp[a][0]=max(dp[a+1][0],dp[a+1][1]+(a+1)*(c[a+1]));
        dp[a][1]=dp[a+1][0];
    }
    printf("%lld", dp[0][0]);
}
