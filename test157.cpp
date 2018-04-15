#include <iostream>
#include <algorithm>

using namespace std;

struct test{
	int m, n;
	double x;
};

test q[1000000];

double cmp(test a, test b) {
	return a.x < b.x;
}

int main() {
	int n;
	int arr[20005];
	scanf("%d", &n);
	while (n--) {
		int p;
		scanf("%d", &p);
		int i = 0;
		//cout << "k = " << k << endl;
		while (~scanf("%d", arr + i)) {
			i++;
		}
		int cnt = 0;
		for (int j = 1; j < i; j++) {
			for (int k = j - 1; k >= 0; k--) {
				q[cnt].m = arr[k];
				q[cnt].n = arr[j];
				q[cnt].x = (double)(arr[k]) / (double)(arr[j]);
				++cnt;
			}
		}
		sort(q, q + cnt, cmp);
		printf("%d %d\n", q[p - 1].m, q[p - 1].n);
	}
	return 0;
}