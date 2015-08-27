#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int ns[100009][26];
int nn;
char str[5009];
int main() {
	int i, n, j;
	scanf("%s", str);
	n = strlen(str);
	memset(ns[0], -1, sizeof(int) * 26);
	nn++;
	for(i = 0; i < n; i++) {
		int p = 0;
		for(j = i; j < n; j++) {
			if(ns[p][str[j] - 'a'] == -1)
				memset(ns[ns[p][str[j] - 'a'] = nn++], -1, sizeof(int) * 26);
			p = ns[p][str[j] - 'a'];
		}
	}
	printf("%d\n", nn - 1);
	return 0;
}
