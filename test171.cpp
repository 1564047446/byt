/*************************************************************************
	> File Name: test171.cpp
	> Author:  muhuilin 
	> Mail: 
	> Created Time: 2018年04月20日 星期五 17时14分03秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    for (int i = 0; i <= 10000000; i++) {
        sum += i;
    }
    cout << sum << endl;
    return 0;
}
