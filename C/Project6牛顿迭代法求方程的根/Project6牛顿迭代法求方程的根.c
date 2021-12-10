#define _CRT_SECURE_NO_WARNINGS 1
/*
������������д��ţ�ٵ������󷽳̵ĸ��ĺ���������A��X��������B��X��ƽ����C��X��һ�η���D�����㣬����ϵ�������������롣��X��1������һ��ʵ������������������������
ţ�ٵ���ʽ�Ĺ�ʽ�ǣ�X=x0-f(x0)/f'(x0);�������|X-x0|<=10����η�ʱ������
���������ţ�ٵ�����ȥx0֮������������ϣ��ҵ���x0���ӽ��ķ��̵ĸ���һ��һ���ĵ������Ӷ��ҵ����ӽ����̸��Ľ��Ƹ���
��rΪf(x)=0�ĸ���ѡȡx0��Ϊr�ĳ�ʼ����ֵ�����㣨x0,f(x0))������y=f(x)������L,L�����߷���Ϊ��y=f'(x0)*(x-x0)+f(x0),���L��x�ύ��ĺ�����x1=x0-f(x0)/f'(x0)��x1Ϊr��һ�ν���ֵ
���㣨x1,f(x1))������y=f(x)�����߷��̣�����������߷�����x��ĺ�����x2=x1-f(x1)/f'(x1)��Ϊr�Ķ��ν���ֵ����˷������ظ����Ϲ��̣��õ�r�ľͽ���ֵxn����ţ�ٵ������������̡�
�㷨��ƣ��������̷�������1����1����������һ��ʵ����Ϊx0�ĳ�ֵ����x0=1.5;(2)�ó�ֵx0���뷽�����f(x0)�Լ�f'(x0);�����б���f�������̵�ֵ��fb����������֮���ֵ��(3)��������h=f/fb;
(4��������һ��x,x=x0-h;
(5)���²�����x�滻x0,Ϊ��һ��������׼����
(6)��|x-x0|>=1e-5��ת������������ִ�У�����ִ�в���7��
(7)�������x���Ƿ��̷���A��X��������B��X��ƽ����C��X��һ�η���D������ĸ������������
*/
#include <stdio.h>
#include <math.h>
#define S "�����뷽�̵��ĸ�ϵ���磺"
#define N "���Է��̵ĸ�Ϊ��x="
double solution(double a, double b, double c, double d);
double Abs(double x, double x0);
int main() {
	double a, b, c, d, x;
	printf("%s1 2 3 4\n",S);
	while (scanf("%lf %lf %lf %lf", &a, &b, &c, &d) != EOF) {
		x = solution(a, b, c, d);
		printf("%s%.100f\n", N, x);
	}
	return 0;
}
double solution(double a, double b, double c, double d) {
	double x0, x = 1.5, f, fb, h;
	do {
		x0 = x;
		f = a * x0 * x0 * x0 + b * x0 * x0 + c * x0 + d;
		fb = 3 * a * x0 * x0 + 2 * b * x0 + c;
		h = f / fb;
		x = x0 - h;
	} while (Abs(x, x0) >= 1e-5);
	return x;
}
double Abs(double x, double x0) {
	int temp;
	temp = (x - x0) < 0 ? (x0 - x) : (x - x0);
	return temp;
}
