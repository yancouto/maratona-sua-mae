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
#include <stack>
#include <list>

using namespace std;

int n, k1, k2;
int v1[12], v2[12];
list<int> p1, p2;

bool check() {
	int i = 0;

	if (p1.size() != k1) return false;
	if (p2.size() != k2) return false;
	for (list<int>::iterator it = p1.begin(); it != p1.end(); ++it) 
		if (v1[i++] != (*it))
			return false;
	i = 0;
	for (list<int>::iterator it = p2.begin(); it != p2.end(); ++it) 
		if (v2[i++] != (*it))
			return false;
	
	return true;
	
}

int main () {
	scanf("%d", &n);
	scanf("%d", &k1);
	for (int i = 0; i < k1; i++) {
		int a;
		scanf("%d", &a);
		p1.push_back(a);
		v1[i] = a;
	}
	scanf("%d", &k2);
	for (int i = 0; i < k2; i++) {
		int a;
		scanf("%d", &a);
		p2.push_back(a);
		v2[i] = a;
	}

	int ans = 0;
	int first = 1;
	if (k1 == 0)
		printf("0 2\n");
	else if (k2 == 0)
		printf("0 1\n");
	else {
		int count = 0;
		while (!p1.empty() && !p2.empty()) {
			count++;
			int a = p1.front();
			int b = p2.front();
			p1.pop_front(); p2.pop_front();
			ans++;
			if (a > b) {
				p1.push_back(b);
				p1.push_back(a);
			} else {
				p2.push_back(a);
				p2.push_back(b);
			}
			if (check()) {
				ans = -1;
				break;
			}
			first = 0;
			if (count > 5000000) {
				ans = -1;
				break;
			}	
		}
		if (ans != -1) {
			if (p1.empty())
				printf("%d 2\n", ans);
			else 
				printf("%d 1\n", ans);
		}
		else
			printf("-1\n");
	}	
	return 0;
}
//http://codeforces.com/contest/546/problem/C