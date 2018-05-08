/*************************************************************************
	> File Name: test179.cpp
	> Author:  muhuilin 
	> Mail: 
	> Created Time: 2018年05月07日 星期一 13时47分39秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;



int main() {
    int a = 10;
    int *p = &a;
    cout << a << endl;
    cout << (*p) << endl;
    cout << ++a << " " << (*p) << endl;
    cout << (*p) << endl;
    return 0;
    
}
