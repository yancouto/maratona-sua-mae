#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

char s1[100003], s2[100002];
int n;

int main () {
	scanf("%s %s", s1, s2);
	n = strlen(s1);
	int z1 = 0, z2 = 0;
	int diff = 0;
	for (int i = 0; i < n; i++) {
		if (s1[i] != s2[i])
			diff++;
	}
	if (diff%2)
		printf("impossible\n");
	else {
		int flag = 1;
		for (int i = 0; i < n; i++) {
			if (s1[i] == s2[i])
				printf("%c", s1[i]);
			else if (flag) {
				printf("%c", s1[i]);
				flag = 0;
			} else {
				printf("%c", s2[i]);
				flag = 1;
			}
		}
		printf("\n");
	}

	return 0;
}
//http://codeforces.com/contest/545/problem/B