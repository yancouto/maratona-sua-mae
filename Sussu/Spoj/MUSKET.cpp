#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 110;

int t, n, dp[MAXN][MAXN];
char M[MAXN][MAXN];

int main (){
    scanf("%d", &t);
    for(int z=0;z<t;z++){
        scanf("%d", &n);
        for(int a=0;a<n;a++){
            for(int b=0;b<n;b++){
                dp[a][b]=0;
                M[a][b]=0;
            }
        }
        for(int a=0;a<n;a++){
            for(int b=0;b<n;b++){
                scanf(" %c", &M[a][b]);
            }
            dp[a][(a+1)%n]=1; //consegue lutar com
        }
        for(int a=2;a<=n;a++){
            for(int b=0;b<n;b++){
                for(int c=1;c<a;c++){
                    //printf("%d-%d %d-%d  %c %c %d %d\n", b, (b+c)%n, (b+c)%n, (b+a)%n, M[b][(b+c)%n], M[(b+a)%n][(b+c)%n], dp[b][(b+c)%n], dp[(b+c)%n][(b+a)%n]);
                    if((M[b][(b+c)%n]=='1' || M[(b+a)%n][(b+c)%n]=='1') && dp[b][(b+c)%n]==1 && dp[(b+c)%n][(b+a)%n]==1){
                        //printf("dp[%d][%d] = 1 por %d\n", b, (b+a)%n, (b+c)%n);
                        dp[b][(b+a)%n] = 1;
                        break;
                    }
                }
            }
        }
        int cnt=0;
        for(int a=0;a<n;a++){
            if(dp[a][a]==1){
                cnt++;
            }
        }
        printf("%d\n", cnt);
        for(int a=0;a<n;a++){
            if(dp[a][a]==1){
                //cnt++;
                printf("%d\n", a+1);
            }
        }
    }
    return 0;
}


