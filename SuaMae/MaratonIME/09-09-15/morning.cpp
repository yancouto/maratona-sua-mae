#include <bits/stdc++.h>
using namespace std;
char *s[] = {"123", "456", "789", "X0X"};
inline bool valid(int i, int j) { return i >= 0 && j >= 0 && j < 3 && i < 4 && s[i][j] != 'X'; }
set<int> all;
void go(int i, int j, int sum, int left) {
    all.insert(sum);
    if(left == 0) return;
    go(i, j, sum * 10 + s[i][j] - '0', left - 1);
    if(valid(i + 1, j)) go(i + 1, j, sum, left);
    if(valid(i, j + 1)) go(i, j + 1, sum, left);
}

int main() {
    go(0, 0, 0, 3);
    int t, x;
    scanf("%d", &t);
    while(t--) {
	scanf("%d", &x);
	auto it = all.lower_bound(x);
	int cl = 10000;
	if(it != all.end() && abs(*it - x) < abs(cl - x)) cl = *it;
	if(it != all.begin() && abs(*prev(it) - x) < abs(cl - x)) cl = *prev(it);
	printf("%d\n", cl);
    }
}
