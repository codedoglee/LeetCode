#ifndef NUMBERSCEQUENCE_H_
#define NUMBERSCEQUENCE_H_

/*
 * ��Ŀ����
 * ����n�������������������ӳ�һ�ţ����һ�����Ķ�λ������
 * ��:n=3ʱ��3������13,312,343,���ɵ��������Ϊ34331213��
 * ��:n=4ʱ,4������7,13,4,246���ӳɵ��������Ϊ7424613��
 *
 * ��������:
 * �ж������������ÿ����������������У���һ��Ϊһ������N��N<=100�����ڶ��а���N����(ÿ����������1000���ո�ֿ�)��
 * �������:
 * ÿ���������һ����ʾ����������
 *
 * ʾ��
 * ����
 * 2
 * 12 123
 * 4
 * 7 13 4 246
 *
 * ���
 * 12312
 * 7424613
 */
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

const int N = 100;
const int MaxLen = 3;

char num1[MaxLen+1];
char num2[MaxLen+1];

char buf1[2*MaxLen+1];
char buf2[2*MaxLen+1];

int myCompare(const void* n1, const void* n2) {
	sprintf(num1, "%d", *(int*)n1);
	sprintf(num2, "%d", *(int*)n2);

	strcpy(buf1, num1);
	strcat(buf1, num2);

	strcpy(buf2, num2);
	strcat(buf2, num1);

	return strcmp(buf1, buf2);
}

void Solve() {
	int n = 0;
	int buf[N];
	while (std::cin >> n) {
		for (int i = 0; i < n; ++i) {
			std::cin >> buf[i];
		}
		qsort(buf, n, sizeof(int), myCompare);
		for (int i = n-1; i >= 0; --i) {
			std::cout << buf[i];
		}
		std::cout << "\n";
	}
}



#endif /* NUMBERSCEQUENCE_H_ */
