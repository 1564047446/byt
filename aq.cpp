/*************************************************************************
	> File Name: aq.cpp
	> Author:  muhuilin 
	> Mail: 
	> Created Time: 2018年04月14日 星期六 17时08分35秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int main() {
    int i;
    for (i = 0; i < 2; i++) {
        fork();
        cout << "-" << endl;
    }
    wait(NULL);
    wait(NULL);
    return 0;
}
