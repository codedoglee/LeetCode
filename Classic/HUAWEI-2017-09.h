#ifndef HUAWEI_2017_09_H_
#define HUAWEI_2017_09_H_

/*
 * ��Ŀ����
 * ����һ��int�����������մ���������Ķ�˳�򣬷���һ�������ظ����ֵ��µ�������
 * ��������:
 * ����һ��int������
 * �������:
 * ���մ���������Ķ�˳�򣬷���һ�������ظ����ֵ��µ�����
 *
 * ʾ��
 * ����
 * 9876673
 *
 * ���
 * 37689
 */
void Solve() {
	int n = 0;
	std::cin >> n;
	bool flag[10];
	for (int i = 0; i < 10; ++i) {
		flag[i] = false;
	}
	while (n % 10 == 0) {
		n = n / 10;
	}
	while (n != 0) {
		if (!flag[n % 10]) {
			std::cout << n % 10;
			flag[n % 10] = true;
		}
		n = n / 10;
	}
}


#endif /* HUAWEI_2017_09_H_ */
