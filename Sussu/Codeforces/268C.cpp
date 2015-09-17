#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;

int main (){
    scanf("%d%d", &n, &m);
    printf("%d\n", min(n, m)+1);
    for(int a=0;a<=min(n,m);a++){
        printf("%d %d\n", a, min(n,m)-a);
    }
    return 0;
}
