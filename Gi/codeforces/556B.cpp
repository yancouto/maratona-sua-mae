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
	int a[1005];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int op1 = n-a[0];
	int i;
	if (n == 2) {
		if (a[0] != a[1])
			printf("Yes\n");
		else
			printf("No\n");
	} else 
	{
		for (i = 1; i < n; i++) {
			if (i % 2) {
				int o1 = a[i]-i;
				if (o1 == 0) o1 = n;
				int o2 = a[i] + n - i;
				if (o1 < 0) {
					if (o2%op1)
						break;
				}
				else {
					if (o2%op1 && o1%op1)
						break;
				}
			}
			else {
				int o1 = i-a[i];
				int o2 = n - a[i] + i;
				if (o1 == 0) o1 = n;
				if (o1 < 0) {
					if (o2%op1)
						break;
				}
				else {
					if (o2%op1 && o1%op1)
						break;
				}
			}
		}
		if (i == n)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}