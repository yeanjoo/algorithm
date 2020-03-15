
#include<iostream>
using namespace std;
int combination(int n, int r);
int main(void) {
	int circulation, r, n;
	cin >> circulation;
	for (int i = 0; i < circulation; i++) {
		cin >> r >> n;
		cout << combination(n, r);
	}
}
int combination(int n, int r)
{
	if (n == r || r == 0) return 1;
	else {
		return combination(n - 1, r - 1) + combination(n - 1, r);
	}
}