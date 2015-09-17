#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;

int n, k, p, x, y, s[MAXN];

int main (){
    scanf("%d%d%d%d%d", &n, &k, &p, &x, &y);
    int men=0,som=0, kk=k;
    for(int a=1;a<=k;a++){
        scanf("%d", &s[a]);
        if(s[a]<y) men++;
        som+=s[a];
    }
    if(men>(n-1)/2){
        printf("-1\n");
        return 0;
    }
    int men2=men;
    while(men2<(n-1)/2 && kk<n){
        som++;
        kk++;
        men2++;
    }
    //printf("%d %d %d %d\n", men, men2, k, kk);
    if(kk==n){
        if(som<=x){
            for(int a=k;a<kk;a++){
                printf("1 ");
            }
            return 0;
        }
        else{
            printf("-1");
            return 0;
        }
    }
    else{
        int kkk=kk;
        while(kkk<n){
            som+=y;
            kkk++;
        }
        //printf("%d %d %d %d\n", k, kk, kkk, som);
        //return 0;
        if(som<=x){
            for(int a=k;a<kk;a++){
                printf("1 ");
            }
            for(int a=kk;a<kkk;a++){
                printf("%d ", y);
            }
            return 0;
        }
        else{
            printf("-1");
            return 0;
        }
    }

    return 0;
}
/*
5 3 5 18 4
3 5 4

5 3 5 18 4
5 5 5

*/
