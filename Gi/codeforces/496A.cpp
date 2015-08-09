#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int a[1005];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int r = 100000000;
	for(int i = 1; i < n; i++){
		int cur = a[i+1] - a[i-1];
		for(int j = 1; j < n; j++){
			if(j == i || j == i+1) continue;
			cur = max(cur, a[j] - a[j-1]);
		}
		r = min(r, cur);
	}
	printf("%d\n", r);	
	return 0;
}
