#include <bits/stdc++.h>
using namespace std;

struct ChessFloor {
	int minimumChanges(vector<string> floor);
}
int f[2][30];
int ChessFloor::minimumChanges(vector<string> fl) {
	int n = fl.size();
	int i, j;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			f[(i+j)%2][fl[i][j] - 'a']++;
	int cst = INT_MAX;
	for(i = 'a'; i <= 'z'; i++)
		for(j = 'a'; j <= 'z'; j++) {
			if(i == j) continue;
			cst = min(cst, n*n - f[0][i-'a'] - f[1][j-'b']);
		}
	return cst;
}
