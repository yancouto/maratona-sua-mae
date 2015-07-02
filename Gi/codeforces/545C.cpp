#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct Tree {
	int x, h;
};

int n;
Tree t[100005];
int memo[100005][3];

/*
int solve (int i, int pos) {
	if (i >= n-1) return 0;
	int &m = memo[i][pos];
	if (m != -1) return m;

	int ans = 0;
	if (!pos) {
		if (t[i].x-t[i-1].x > t[i].h)
			ans = max(ans, 1 + solve(i + 1, 0));
		else if (t[i+1].x-t[i].x > t[i].h) {
			ans = max(ans, 1 + solve(i + 1, 1));
			ans = max(ans, solve(i + 1, 0));
		}
		else
			ans = max(ans, solve(i + 1, 0));
	}
	else if (pos) {
		int d = t[i].x - (t[i-1].x + t[i-1].h);
		if (d > t[i].h)
			ans = max(ans, 1 + solve(i + 1, 0));
		else if (t[i+1].x - t[i].x > t[i].h) {
			ans = max(ans, 1 + solve(i + 1, 1));
			ans = max(ans, solve(i+1, 0));
		} else
			ans = max(ans, solve(i+1, 0));
	}	

	return m=ans;
}*/

int main () {
	memset(memo, -1, sizeof(memo));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &t[i].x, &t[i].h);
	int ans = 0, pos = 1;
	ans++;
	for (int i = 1; i < n-1; i++) {
		if (pos) {
			if ((t[i].x - t[i-1].x) > t[i].h)
				ans++;
			else if (pos && (t[i+1].x - t[i].x) > t[i].h) {
				ans++;
				pos = 0;
			}

		}
		else if (!pos) {
			int d = t[i].x - (t[i-1].x + t[i-1].h);
			if (d > t[i].h) {
				ans++;
				pos = 1;
			}
			else if ((t[i+1].x - t[i].x) > t[i].h)
				ans++;
			else 
				pos = 1;
		}
	}
	if (n > 1) ans++;

	printf("%d\n", ans);
	return 0;
}

//http://codeforces.com/contest/545/problem/C