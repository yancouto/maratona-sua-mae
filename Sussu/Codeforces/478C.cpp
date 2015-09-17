#include <cstdio>
#include <algorithm>
using namespace std;

long long s[5];

int main() {
    for(int a=0;a<3;a++)
        scanf("%I64d", &s[a]);
    sort(s,s+3);
    if(s[2]/2>=s[0]+s[1])
        printf("%I64d\n", min(s[2]/2,s[0]+s[1]));
    else
        printf("%I64d\n", (s[0]+s[1]+s[2])/3);
	return 0;
}
