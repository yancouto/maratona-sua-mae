#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 110, INF = 0x3f3f3f3f;

int t, n, m, M[MAXN][MAXN], MF[MAXN][MAXN], vez, cnt;

void exp(){
    int MA[MAXN][MAXN];
    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            MA[a][b]=0;
            for(int c=0;c<n;c++){
                MA[a][b]+=MF[c][b]*M[a][c];
                if(MA[a][b]!=0) MA[a][b]=1;
            }
        }
    }
    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            MF[a][b]=MA[a][b];
        }
    }
}

int main (){
    scanf("%d", &t);
    for(int z=0;z<t;z++){
        scanf("%d", &n);
        for(int a=0;a<n;a++){
            for(int b=0;b<n;b++){
                char aux;
                scanf(" %c", &aux);
                M[a][b]=aux-'0';
               //if(a==b)
                   // M[a][b]=0;
                MF[a][b]=M[a][b];
            }
        }
        for(vez=0;vez<n-1;vez++){
            exp();
        }
        cnt=0;
        for(int a=0;a<n;a++){
            int aux = 0;
            for(int b=0;b<n;b++){
                if(MF[a][b]==0) aux=1;
            }
            if(aux!=1)
                cnt++;
        }
        printf("%d\n", cnt);
        for(int a=0;a<n;a++){
            int aux = 0;
            for(int b=0;b<n;b++){
                if(MF[a][b]==0) aux=1;
            }
            if(aux!=1)
                printf("%d\n", a+1);
        }
        /*
        for(int a=0;a<n;a++){
            int aux = INF;
            for(int b=0;b<n;b++){
                printf("%4d", MF[a][b]);
            }
            printf("\n");
        }
        printf("\n");
        */
    }
    return 0;
}

/*

1
7
1111101
0101100
0111111
0001101
0000101
1101111
0100001

2
3
110
011
101
7
1111101
0101100
0111111
0001101
0000101
1101111
0100001

1
3
100
111
101


*/
