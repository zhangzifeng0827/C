#define _CRT_SECURE_NO_WARNINGS 1
/*
问题描述：编写用牛顿迭代法求方程的根的函数。方程A的X的立方加B的X的平方加C的X的一次方加D等于零，其中系数由主函数输入。求X在1附近的一个实数根。求出后由主函数输出。
牛顿迭代式的公式是：X=x0-f(x0)/f'(x0);设迭代到|X-x0|<=10负五次方时结束。
问题分析：牛顿迭代法去x0之后，在这个基础上，找到比x0更接近的方程的根，一步一步的迭代，从而找到更接近方程根的近似根。
设r为f(x)=0的根，选取x0作为r的初始近似值，过点（x0,f(x0))作曲线y=f(x)的切线L,L的切线方程为：y=f'(x0)*(x-x0)+f(x0),求出L与x轴交点的横坐标x1=x0-f(x0)/f'(x0)称x1为r的一次近似值
过点（x1,f(x1))作曲线y=f(x)的切线方程，并且求出切线方程与x轴的横坐标x2=x1-f(x1)/f'(x1)称为r的二次近似值，如此反复，重复以上过程，得到r的就近似值xn。即牛顿迭代法的求解过程。
算法设计：程序流程分析：（1）在1附近任意找一个实数作为x0的初值，如x0=1.5;(2)用初值x0代入方程求出f(x0)以及f'(x0);程序中变量f描述方程的值，fb描述方程求导之后的值；(3)计算增量h=f/fb;
(4）计算下一个x,x=x0-h;
(5)用新产生的x替换x0,为下一个迭代做准备。
(6)若|x-x0|>=1e-5，转到步骤三继续执行，否则执行步骤7。
(7)所求出的x就是方程方程A的X的立方加B的X的平方加C的X的一次方加D等于零的根，并且其输出
*/
#include <stdio.h>
#include <math.h>
#define S "请输入方程的四个系数如："
#define N "所以方程的根为：x="
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
