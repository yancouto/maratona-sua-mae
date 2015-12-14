#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t, n; ll g;
    scanf("%d", &t);
    while(t--) {
	scanf("%d", &n);
	for(g = 2; (g*(g+1))/2 <= n; g++) {
	    if(((n - (g*(g+1))/2) % g) == 0) {
		ll k = (n - ((g*(g+1))/2)) / g;
		printf("%d = %d", n, k + 1);
		for(int i = 2; i <= g; i++)
		    printf(" + %d", k + i);
		putchar('\n');
		break;
	    }
	}
	if((g*(g+1))/2 > n) puts("IMPOSSIBLE");
    }
}
