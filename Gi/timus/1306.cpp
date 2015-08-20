#include <bits/stdc++.h>

using namespace std;


int v[125002];
int main(){
	int n; scanf("%d", &n);
	int i, a;

	for(i = 0; i < n/2 + 1; i++) scanf("%d", &v[i]); 
	make_heap(v, v + i);

	for(; i < n; i++){
		int a; scanf("%d", &a);
		if(v[0] > a) {
			pop_heap(v, v + n/2 + 1);
			v[n/2] = a;
			push_heap(v, v + n/2 + 1);
		}
	}
	if(n%2) printf("%.1f\n", (double)v[0]);
	else {
		double a = v[0]; pop_heap(v, v + n/2 + 1);
		a += v[0];
		printf("%.1f\n", a/2.0); 
	}

}
