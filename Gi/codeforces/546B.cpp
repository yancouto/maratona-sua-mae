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

int n;
int b[3003], freq[3003];

int main () {
	memset(freq, 0, sizeof(freq));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		freq[b[i]]++;
	}
	sort(b, b+n);
	int ans = 0;
	int last[30003], ilast = 0;
	int amais = 0;
	for (int i = 1; i <= b[n-1]; i++) {
		if (freq[i] == 0 && ilast) {
			ans += i-last[ilast-1];
			freq[last[ilast-1]]--;
			if (freq[last[ilast-1]] == 1) {
				ilast--;
			}
		}
		else if (freq[i] > 1) {
			last[ilast++] = i;
		}
	}
	int ult = b[n-1] + 1;
	for (int i = 0; i < ilast; i++) {
		int a = freq[last[i]] - 1;	
		ans += (ult + amais + ult + amais + a - 1)* a/2 - last[i]*a;
		amais+=a;
	}
	printf("%d\n", ans);
	return 0;
}
//http://codeforces.com/contest/546/problem/B