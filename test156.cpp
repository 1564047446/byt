#include <stdio.h>
#include <iostream>

#define mod 1e9+7

using namespace std;

int main() {
	char str[10001];
	scanf("%s", str);
	int n;
	scanf("%d", &n);
	while (n--) {
		int row, cow, start_row, start_cow, i = 0;
		scanf("%d%d%d%d", &row, &cow, &start_row, &start_cow);
		int ans = 0;
		while (str[i]) {
			++ans;
			switch (str[i]) {
				case 'u':
					start_row--;
					break;
				case 'd' :
					start_row++;
					break;
				case 'l' :
					start_cow--;
					break;
				case 'r' :
					start_cow++;
					break;
			}
			if (start_row > row || start_cow > cow || start_row < 1 || start_cow < 1) {
				break;
			}
			i++;
		}
		printf("%d\n", ans);
	}
	return 0;
}