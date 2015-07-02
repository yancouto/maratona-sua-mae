#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const int& lhs, const int&rhs) const
  {
    if (reverse) return (lhs<rhs);
    else return (lhs<rhs);
  }
};

priority_queue<int> ant;
priority_queue<int,vector<int>,mycomparison> pos;

int main () {
	int n, k, p, x, y, yi;
	int ak[1003];
	scanf("%d%d%d%d%d", &n, &k, &p, &x, &y);
	int i, sum, add[1003], iadd = 0;
	sum = yi = 0;
	for (i = 0; i < k; i++) {
		scanf("%d", &ak[i]);
		sum += ak[i];
		if (ak[i] < y) 
			ant.push(ak[i]);
		else if (ak[i] >= y)
			pos.push(ak[i]);
		

	}
	int ok = 1;
	for (i = 1; i <= n-k && ok; i++) {
		int s1, s2;
		s1 = ant.size();
		s2 = pos.size();
		if (s1 < s2) {
			ant.push(1);
			add[iadd++] = 1;
			sum += 1;
		}	
		else if (s1 >= s2){
			pos.push(y);
			add[iadd++] = y;
			sum += y;
		} 

		if (sum > x) ok = 0;
	}
	int s1, s2;
	s1 = ant.size();
	s2 = pos.size();
	if (ok && s1 < s2) {
		for (i = 0; i < iadd - 1; i++)
			printf("%d ", add[i]);
		printf("%d\n", add[iadd-1]);
	}
	else
		printf("-1\n");
}