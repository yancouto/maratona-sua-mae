#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXV = 5000010;

int dp[MAXV][7], dig[11], fil[MAXV][7], deg[7], w, d, v;

bool ehint(double v){
    if(floor(v)==v) return true;
    return false;
}

int go(int val,int jog){
    if(dp[val][jog]==0){
        dp[val][jog]=1;
        if(jog<=4) return dp[val][jog];
        for(int a=0;a<d;a++){
            if(dig[a]!=0 && ehint((double)val/dig[a]))
                dp[val][jog]=max(dp[val][jog],go(val/dig[a],jog-1));
            if(val-dig[a]>=0)
                dp[val][jog]=max(dp[val][jog],go(val-dig[a],jog-1));
        }
    }
    return dp[val][jog];
}

int main(){
    scanf("%d%d", &w, &d);
    for(int a=0;a<d;a++){
        scanf("%d", &dig[a]);
        dp[dig[a]][0]=2;
        fil[deg[0]++][0]=dig[a];
    }
    for(int jog=0;jog<4;jog++){
        for(int i=0;i<deg[jog];i++){
            int val = fil[i][jog];
            for(int dd=0;dd<d;dd++){
                if(dp[val*dig[dd]][jog+1]==0 && val*dig[dd]<MAXV-5){
                    printf("alcanssa %d %d\n", val*dig[dd], jog+1);
                    dp[val*dig[dd]][jog+1]=1;
                    fil[deg[jog+1]++][jog+1]=val*dig[dd];
                }
                if(dp[val*dig[dd]][jog+1]==0 && val+dig[dd]<MAXV-5){
                    dp[val+dig[dd]][jog+1]=1;
                    fil[deg[jog+1]++][jog+1]=val+dig[dd];
                }
            }
        }
    }
    scanf("%d", &v);
    for(int a=0;a<v;a++){
        int val;
        scanf("%d", &val);
        if(go(val,w)==2)
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}
