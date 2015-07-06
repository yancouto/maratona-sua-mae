#include <cstdio>
int n, k;
int a[102][102], b[102][102];

bool eq() {
	int i, j;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(a[i][j] != b[i][j])
				return false;
	return true;
}

bool bsim() {
	int i, j;
	for(i = 0; i < n; i++)
		for(j = i + 1; j < n; j++)
			if(b[i][j] != b[j][i])
				return false;
	return true;
}

int solve() {
	int i, j, probs = 0, prob1 = 0, sim = 0;
	for(i = 0; i < n; i++)
		if(a[i][i] != b[i][i])
			probs++;
	for(i = 0; i < n; i++)
		for(j = i + 1; j < n; j++) {
			if(a[i][j] != b[i][j]) probs++;
			if(a[j][i] != b[j][i]) probs++;
			if(a[i][j] != a[j][i]) {
				sim++;
				if(b[i][j] == a[j][i] && b[j][i] == a[i][j])
					prob1++;
			}
		}
	if(prob1 == 1 && sim == 1) {
		if(k == 2 && n == 2) return -1;
		if(k == 2) return probs + 2;
		return probs + 1;
	}
	return probs;
}

int main() {
	int t, i, j;
	scanf("%d", &t);
	for(int tt = 1; tt <= t; tt++) {
		scanf("%d %d", &n, &k);
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				scanf("%d", &a[i][j]);
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				scanf("%d", &b[i][j]);
		if(eq()) { printf("Case %d: 0\n", tt); continue; }
		if(bsim()) { printf("Case %d: -1\n", tt); continue; };
		printf("Case %d: %d\n", tt, solve());
	}
	return 0;
}