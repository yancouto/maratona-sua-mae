#include <bits/stdc++.h>
using namespace std;

struct ExactTreeEasy {
	vector <int> getTree(int n, int m);
};

vector<int> ExactTreeEasy::getTree(int n, int m) {
	vector<int> v;
	for(int i = 0; i < m - 1; i++) {
		v.push_back(m - 1);
		v.push_back(i);
	}
	for(int i = m; i < n; i++) {
		v.push_back(i);
		v.push_back(i - 1);
	}
	return v;
}
