#define _CRT_SECURE_NO_WARNINGS 1
/*
问题描述：中国有句俗语叫“三天打鱼两天晒网”。某人从1990年1月1日起开始三天打鱼两天晒网，
问这个人在以后的每一天中是打鱼还是晒网，并且计算指定日期距离1990年1月1日的天数，并且判断输出年份是闰年还是平年。
输入输出样式：
请输入出生年月以及指定日期：如 1990 1 1 2008 1 2
1990 1 1 2008 1 1
2008年  1月     1日     //距离1990年1月1日      距离出生日期1990年      1月     1日     有6575天        今天晒网       2008年是闰年
1994 6 18 2021 12 9
2021年  12月    9日     //距离1990年1月1日      距离出的日期1994年      6月     18日    有9963天        今天打鱼       2021年是平年
2001 8 27 2021 12 9
2021年  12月    9日     //距离1990年1月1日      距离出的日期2001年      8月     27日    有7376天        今天打鱼       2021年是平年

*/
#include<stdio.h>
#define N 13
#define S "1990年1月1日"
const int R = 5;//周期
typedef struct date {//定义日期结构体
	int year;
	int month;//结构体成员变量；
	int day;
}Date;//重新声明结构体类型
int totalDays(struct date Birth,struct date toDay);//定义计算指定日期距离1990年1月1日的天数的函数；
int runYear(int year);//定义判断是否为闰年函数
int main() {
	Date birth,today;//出生日期，指定日期
	int countDays;//指定日期距离1990年1月1日的天数；
	int result;//计算天数对周期的余数；
	printf("请输入出生年月以及指定日期：如 1990 1 1 2008 1 2\n");
	while (scanf("%d %d %d %d %d %d",&birth.year,&birth.month,&birth.day, &today.year, &today.month, &today.day) != EOF) {//输入多组数据出生日期和指定日期
		countDays = totalDays(birth,today);
		result = countDays % R;
		if (result > 0 && result <= 3) {
			printf("%d年\t%d月\t%d日\t//距离%s\t距离出的日期%d年\t%d月\t%d日\t有%d天\t今天打鱼\t", today.year, today.month, today.day, S,birth.year,birth.month,birth.day, countDays);
		}
		else {
			printf("%d年\t%d月\t%d日\t//距离%s\t距离出生日期%d年\t%d月\t%d日\t有%d天\t今天晒网\t", today.year, today.month, today.day, S, birth.year,birth.month,birth.day,countDays);
		}
		if (runYear(today.year)) {
			printf("%d年是闰年\n", today.year);
		}
		else {
			printf("%d年是平年\n", today.year);
		}
	}
	return 0;
}
int runYear(int year) {
	int temp;
	if (year % 400 == 0 || year % 4 == 0 && year != 0) {
		temp = 1;
	}
	else {
		temp = 0;
	}
	return temp;
}
int totalDays(Date Birth,Date toDay) {
	int a[N] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 }, tempDays = 0,i;
	i = Birth.year;
	while (i < toDay.year) {
		if (runYear(i)) {
			tempDays += 366;
		}
		else {
			tempDays += 365;
		}
		i++;
	}
	for (i = Birth.month; i < toDay.month; i++) {
		if (runYear(toDay.year)) {
			a[2] = 29;
		}
		else {
			a[2] = 28;
		}
		tempDays += a[i];
		i++;
	}
	tempDays += toDay.day;
	return tempDays;
}