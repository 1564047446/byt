/*************************************************************************
	> File Name: test79.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月24日 星期三 11时35分31秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
int num;
void dfs(int x) {

}

int main() {
    num = 0;
    int x;
    scanf("%d", &x);
    int sum2_3 = 0;
    int sum = 0;
    for (int i = 0; i < x - 1; i++) {
        if (i == 0) {
            sum = 1;
            sum2_3 = sum - 1 - sum2_3;
        }
        else {
            sum *= 2;
            sum2_3 = sum - sum2_3;
        }
        printf("%d\n", sum2_3);
    }
    //int result = pow(2, x - 1);
    sum *= 2;
    printf("result = %d\n", (sum - sum2_3) * 3);
    return 0;
}
