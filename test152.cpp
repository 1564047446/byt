/*************************************************************************
	> File Name: problem15.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月14日 星期二 17时41分22秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<inttypes.h>
using namespace std;

int main()
{
    int64_t sum = 1;
    int64_t num = 50;
    for(int64_t i = 100; i >= 51; i--)
    {
        sum *= i;
        while(num && sum % num == 0)
        {
            sum /= num;
            num--;
        }
        sum %= 100000007;
    }
    printf("%"PRId64"\n", sum);
}

