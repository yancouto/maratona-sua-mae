#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 110;

int  R,S,P;
double dp[MAXN][MAXN][MAXN];

int main (){
    scanf("%d%d%d", &R, &S, &P);
    dp[R][S][P]=1.0;
    for(int som=R+S+P;som>0;som--){
        for(int r=R;r>=0;r--){
            for(int s=S;s>=0;s--){
                int p = som-r-s;
                if(p<0 || p>P) continue;
                //printf("%d %d %d\n", r, s, p);
                if(r+s==0 || r+p==0 || p+s==0) continue;
                double cur = dp[r][s][p];
                if(r>0) dp[r-1][s][p]+=cur*((double)r*p)/((double)r*p+(double)r*s+(double)s*p);
                if(s>0) dp[r][s-1][p]+=cur*((double)r*s)/((double)r*p+(double)r*s+(double)s*p);
                if(p>0) dp[r][s][p-1]+=cur*((double)s*p)/((double)r*p+(double)r*s+(double)s*p);
            }
        }
    }
    double r1, r2, r3;
    r1=r2=r3=0;
    for(int a=1;a<=R;a++){
        r1+=dp[a][0][0];
    }
    for(int a=1;a<=S;a++){
        r2+=dp[0][a][0];
    }
    for(int a=1;a<=P;a++){
        r3+=dp[0][0][a];
    }
    printf("%.12f %.12f %.12f", r1, r2, r3);
    return 0;
}
