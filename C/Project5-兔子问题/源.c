#define _CRT_SECURE_NO_WARNINGS 1
/*
问题描述：
有一对兔子，从出生后的第三个月起每个月出生一对兔子。小兔子长到第第三个月后每个月又双叒叕出生一对兔子，假设所有的兔子都不会死，问30个月的兔子数量是多少？
//斐波那契数列问题：可以用循环或者递归；
*/
#include <stdio.h>
int fib(int x);
int main() {
	int n,i,count=0;
	while (scanf("%d", &n) != EOF) {
		for (i = 1; i <= n; i++) {
			count++;
			if (count % 3) {
				printf("||第%2d个月有兔子：%10d只\t", i, fib(i));
			}
			else {
				printf("第%2d个月有兔子：%10d只\n", i, fib(i));
			}
		}
	}
	return 0;
}
int fib(int x) {
	int temp;
	if (x == 1 || x == 2) {
		temp = 1;
	}
	else if (x > 2) {
		temp = fib(x - 1) + fib(x - 2);
	}
	return temp;
}