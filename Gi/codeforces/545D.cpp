#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main () {
	int n;
	int tme[100005];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &tme[i]);
	sort(tme, tme + n);
	int ans = 0, ctme = 0;
	for (int i = 0; i < n; i++) {
		if (tme[i] >= ctme) {
			ans++;
			ctme += tme[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}
//http://codeforces.com/contest/545/problem/D