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
	int A[102][102], c, car[102], icar = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%d", &A[i][j]);
	}
	c = 0;
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (A[i][j] == 1 || A[i][j] == 3 || A[j][i] == 2 || A[j][i] == 3) {
				count = 1;
				break;
			}
		}
		if (!count) {
			car[icar++] = i;
			c++;
		}
	}
	sort(car, car + icar);
	printf("%d\n", c);
	for (int i = 0; i < icar - 1; i++)
		printf("%d ", car[i] + 1);
	if (icar > 0) printf("%d\n", car[icar-1] + 1);
	
	return 0;
}
//http://codeforces.com/contest/545/problem/A