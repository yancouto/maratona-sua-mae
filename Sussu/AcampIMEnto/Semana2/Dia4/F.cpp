#include <bits/stdc++.h>
#define mp make_pair
#define debug(args...) fprintf(stderr, args)
#define pb push_back
#define ff first
#define ss second
using namespace std;

const int MAXN = 210;

int main() {
	char str[MAXN];
	scanf("%s", str);
	int len = strlen(str);
	for(int i = 0; i < len; i++) str[i + len] = str[i];
	str[2*len] = 0;
	for(int i = 0; i < len; i++) {
		bool ok = true;
		for(int j = i; j < i + len; j++) {
			if(str[j] != str[len + 2*i - j - 1]) ok = false;
		}
		if(ok) {
			printf("yes\n");
			return 0;
		}
	}
	printf("no\n");
	return 0;
}
