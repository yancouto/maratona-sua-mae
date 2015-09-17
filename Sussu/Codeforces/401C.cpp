#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m;

inline void p110(int i){
    while(i!=0){
        printf("110");
        i--;
    }
}

inline void p10(int i){
    while(i!=0){
        printf("10");
        i--;
    }
}

int main(){
    scanf("%d%d", &n, &m);
    if(m>2*n+2 || m<n-1)
        printf("-1\n");
    else if(m==2*n+2 || m==2*n+1 || m==2*n){
        p110(n);
        for(int a=0;a<m-2*n;a++)
            printf("1");
    }
    else if(m==n-1){
        printf("0");
        p10(n-1);
    }
    else{
        while(1){
            if(m==2*n){
                p110(n);
                break;
            }
            else if(m==n){
                p10(n);
                break;
            }
            else{
                printf("10");
                n--;
                m--;
            }
        }
    }
    printf("\n");
    return 0;
}

/*
4247 8495
*/
