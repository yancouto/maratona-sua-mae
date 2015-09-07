#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10010;


int n, l[MAXN], res;

int mod(int a){
    if(a<0) return -a;
    return a;
}

inline int dist(int a,int b){
    if(a<b) swap(a,b);
    return min(a-b,10-a+b);
}

int main (){
    scanf("%d", &n);
    for(int a=0;a<n;a++){
        char abc;
        scanf(" %c", &abc);
        l[a]=abc-'0';
    }
    char i;
    for(int a=0;a<n;a++){
        scanf(" %c", &i);
        int ii = i-'0';
        res+=dist(l[a],ii);
    }
    printf("%d", res);
    return 0;
}
