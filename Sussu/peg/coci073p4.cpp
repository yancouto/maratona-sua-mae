#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXX = 100010, MAXN = 100000;

int n;
long long ni[MAXX], nj[MAXX], i[MAXN], j[MAXN], res;

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%lld%lld", &i[a], &j[a]);
		ni[i[a]]++;
		nj[j[a]]++;
	}
	for(int a=0;a<n;a++){
		res+=(ni[i[a]]-1)*(nj[j[a]]-1);
	}
	printf("%lld\n", res);
	return 0;
}

/*
3
4 2
2 1
1 3

6
1 1
2 1
3 1
4 1
5 1
6 1

8
1 1
2 1
3 1
4 1
5 1
6 1
1 2
1 3

5
1 2
2 1
2 2
2 3
3 2

6
10 10
20 10
10 20
20 20
30 20
30 30

*/
