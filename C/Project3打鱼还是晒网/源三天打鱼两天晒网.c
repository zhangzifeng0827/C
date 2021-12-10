#define _CRT_SECURE_NO_WARNINGS 1
/*
�����������й��о�����С������������ɹ������ĳ�˴�1990��1��1����ʼ�����������ɹ����
����������Ժ��ÿһ�����Ǵ��㻹��ɹ�������Ҽ���ָ�����ھ���1990��1��1�յ������������ж������������껹��ƽ�ꡣ
���������ʽ��
��������������Լ�ָ�����ڣ��� 1990 1 1 2008 1 2
1990 1 1 2008 1 1
2008��  1��     1��     //����1990��1��1��      �����������1990��      1��     1��     ��6575��        ����ɹ��       2008��������
1994 6 18 2021 12 9
2021��  12��    9��     //����1990��1��1��      �����������1994��      6��     18��    ��9963��        �������       2021����ƽ��
2001 8 27 2021 12 9
2021��  12��    9��     //����1990��1��1��      �����������2001��      8��     27��    ��7376��        �������       2021����ƽ��

*/
#include<stdio.h>
#define N 13
#define S "1990��1��1��"
const int R = 5;//����
typedef struct date {//�������ڽṹ��
	int year;
	int month;//�ṹ���Ա������
	int day;
}Date;//���������ṹ������
int totalDays(struct date Birth,struct date toDay);//�������ָ�����ھ���1990��1��1�յ������ĺ�����
int runYear(int year);//�����ж��Ƿ�Ϊ���꺯��
int main() {
	Date birth,today;//�������ڣ�ָ������
	int countDays;//ָ�����ھ���1990��1��1�յ�������
	int result;//�������������ڵ�������
	printf("��������������Լ�ָ�����ڣ��� 1990 1 1 2008 1 2\n");
	while (scanf("%d %d %d %d %d %d",&birth.year,&birth.month,&birth.day, &today.year, &today.month, &today.day) != EOF) {//����������ݳ������ں�ָ������
		countDays = totalDays(birth,today);
		result = countDays % R;
		if (result > 0 && result <= 3) {
			printf("%d��\t%d��\t%d��\t//����%s\t�����������%d��\t%d��\t%d��\t��%d��\t�������\t", today.year, today.month, today.day, S,birth.year,birth.month,birth.day, countDays);
		}
		else {
			printf("%d��\t%d��\t%d��\t//����%s\t�����������%d��\t%d��\t%d��\t��%d��\t����ɹ��\t", today.year, today.month, today.day, S, birth.year,birth.month,birth.day,countDays);
		}
		if (runYear(today.year)) {
			printf("%d��������\n", today.year);
		}
		else {
			printf("%d����ƽ��\n", today.year);
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