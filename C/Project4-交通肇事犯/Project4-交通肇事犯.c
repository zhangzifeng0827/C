#define _CRT_SECURE_NO_WARNINGS 1
/*
问题描述：
一辆卡车违反交通规则，交通肇事后逃跑。现场有三人目击事件。但是都没有记住卡号只记住了车牌号的一些特征。
甲说：牌照的前两个数字是相同的；乙说：拍照的后两位数字是相同的，但与前两位不同；丙是数学家，他说：四位的车牌号刚刚好是一个整数的平方。请根据以上线索求出车牌号；
问题分析：
按照题目要求构造出一个前两位数字相同，后两位数字相同并且相互间又双叒叕不同的四位数，然后判断整数是否为另一个整数的平方和
输出结果：
车牌号为：7744
C:\Users\31646\Desktop\CLanguage\Project4-交通肇事犯\Debug\Project4-交通肇事犯.exe (进程 15660)已退出，代码为 0。
按任意键关闭此窗口. . .

*/
#include <stdio.h>
int main() {
	int i, j, k, temp;//i代表前两位j代表后两位k代表车牌号
	for (i = 0; i <= 9; i++) {
		for (j = 0; j <= 9; j++) {//穷举前两位数字相同后两位数字相同
			if (i != j) {
				k = 1000 * i + 100 * i + 10 * j + j;
				//组成四位车牌号；
				for (temp = 00; temp <= 99; temp++) {
					if (temp * temp == k) {
						printf("车牌号为：%d", k);
					}
				}
			}
		}
	}
	return 0;
}