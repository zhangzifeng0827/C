#define _CRT_SECURE_NO_WARNINGS 1
/*
����������
��һ�����ӣ��ӳ�����ĵ���������ÿ���³���һ�����ӡ�С���ӳ����ڵ������º�ÿ������˫��������һ�����ӣ��������е����Ӷ�����������30���µ����������Ƕ��٣�
//쳲������������⣺������ѭ�����ߵݹ飻
*/
#include <stdio.h>
int fib(int x);
int main() {
	int n,i,count=0;
	while (scanf("%d", &n) != EOF) {
		for (i = 1; i <= n; i++) {
			count++;
			if (count % 3) {
				printf("||��%2d���������ӣ�%10dֻ\t", i, fib(i));
			}
			else {
				printf("��%2d���������ӣ�%10dֻ\n", i, fib(i));
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