#define _CRT_SECURE_NO_WARNINGS 1
/*问题描述：
中国古代科学家张邱建在他的算经中提出了著名的“百钱百鸡”问题：一只公鸡值五钱，一只母鸡值三钱，三只小鸡值一钱，现在要用百钱买百鸡，请问公鸡，母鸡，小鸡各多少只？
算法设计：穷举法，三重循环；
输出结果：
第1种方法：公鸡：  0只  母鸡： 25只     小鸡： 75只     第2种方法：公鸡：  3只  母鸡： 20只     小鸡： 77只
第3种方法：公鸡：  4只  母鸡： 18只     小鸡： 78只     第4种方法：公鸡：  7只  母鸡： 13只     小鸡： 80只
第5种方法：公鸡：  8只  母鸡： 11只     小鸡： 81只     第6种方法：公鸡： 11只  母鸡：  6只     小鸡： 83只
第7种方法：公鸡： 12只  母鸡：  4只     小鸡： 84只
C:\Users\31646\source\repos\百钱百鸡\Debug\百钱百鸡.exe (进程 14824)已退出，代码为 0。
按任意键关闭此窗口. . .
*/
#include <stdio.h>
const int N = 100;
int main() {
	int cook, hen, chicken,count=0;
	for(cook=0;cook<=21;cook++)
		for(hen=0;hen<=33;hen++)
			for (chicken = 0; chicken <= 100; chicken++) {
				if ((cook + hen + chicken == 100) && (cook * 5 + hen * 3 + chicken / 3 == 100)) {
					count++;
					if (!(count % 2)) {
						printf("第%d种方法：公鸡：%3d只\t母鸡：%3d只\t小鸡：%3d只\n", count, cook, hen, chicken);
					}
					else {
						printf("第%d种方法：公鸡：%3d只\t母鸡：%3d只\t小鸡：%3d只\t", count, cook, hen, chicken);
					}
				}
			}
	return 0;
}
