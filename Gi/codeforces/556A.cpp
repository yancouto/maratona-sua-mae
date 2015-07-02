#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int main () {
	int n;
	char s[200005];
	scanf("%d", &n);
	scanf("%s", s);
	int ans = n;
	int uns = 0, dois = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == '1') uns++;
		else dois++;

	printf("%d\n", n-min(uns, dois)*2);
	return 0;
}