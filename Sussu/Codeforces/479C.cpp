#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 5010;

int n;

struct prova{
    int i, j;
} p[MAXN];

bool cmp(prova a,prova b){
    if(a.i!=b.i)
        return a.i<b.i;
    return a.j<b.j;
}

int main (){
    scanf("%d", &n);
    for(int a=0;a<n;a++){
        scanf("%d%d", &p[a].i, &p[a].j);
    }
    sort(p,p+n,cmp);
    int ult=0;
    for(int a=0;a<n;a++){
        if(ult<=p[a].j)
            ult=p[a].j;
        else
            ult=p[a].i;
    }
    printf("%d\n", ult);
    return 0;
}
