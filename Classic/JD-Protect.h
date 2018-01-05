#ifndef JD_PROTECT_H_
#define JD_PROTECT_H_

/*
 * ��Ŀ����
 * ս����Ϸ��������Ҫ���ھ�Ҫ�����ˣ���εĽ������������������������СB�����׶��ķ���������
 * �׶�λ��һ�����滷ɽ������У���Χ��n��Сɽ����һ��������ΪԤ����ʩ��СB�ƻ���ÿ��Сɽ������һ���۲��ڣ�
 * ��ҹ��ͣ�Ĳt����Χ����������� һ��������������¼���ɽ���ϵĸ��ڽ���ȼ���̣�
 * �������������ڵ�ɽ��֮��û�и��ߵ�ɽ���ڵ�������֮��������ͨ·������ڿ��Թ۲쵽��һ��ɽ���ϵķ����Ƿ��ȼ��
 * ����Сɽ���ڻ��ϣ���������Сɽ֮�����������ͬ������ͨ·�������������ڵ��������£�
 * һ��ɽ���ϸ��ڵ�ȼ�ķ������ٿ���ͨ��һ��ͨ·����һ�˹۲쵽�������������ڵĸ��ڣ�һ�˵ĸ���һ�����Է���һ�˵�ȼ�ķ��̡�
 * СB��Ƶ����ֱ���������һ����Ҫ�������ܹ��۲⵽�Է����̵ĸ��ڶԵ���������ϣ�����ܹ��������������⡣
 *
 * ��������:
 * �������ж���������ݣ�ÿһ��������ݵĵ�һ��Ϊһ������n(3<=n<=10^6),Ϊ�׶���Χ��Сɽ�������ڶ���Ϊn��������
 * ���α�ʾΪСɽ�ĸ߶�h��1<=h<=10^9��
 * �������:
 * ��ÿ��������ݣ��ڵ�����һ����������໥�۲쵽�ĸ��ڵĶ�����
 *
 * ʾ��
 * ����
 * 5
 * 1 2 4 5 3
 *
 * ���
 * 7
 */
#include <iostream>
#include <string.h>

const int N = 1000001;

int buf[N];			//ԭʼ����
int numbers[N];		//�����������
int right[N];		//�ұߴ��ڵ��������±�
int left[N];		//��ߴ��ڵ��������±�
int count[N];		//Сɽ�߶���ͬʱ��̬�滮

void Solve() {
	memset(right, 0, sizeof(right));
	memset(left, 0, sizeof(left));
	memset(count, 0, sizeof(count));

	int n = 0;
	int max = 0;			//���ֵ
	int firstMaxIndex = 0;	//��¼�����һ�����ֵ

	std::cin >> n;
	if (n <= 2) {
		return;
	}

	for (int i = 0; i < n; ++i) {
		std::cin >> buf[i];
		if (buf[i] > max) {
			max = buf[i];
			firstMaxIndex = i;
		}
	}

	//������ת��Ϊ��Ԫ��Ϊ���ֵ��������һ����ת����ߵ�ɽ��λ��0
	for (int i = 0; i < n; ++i) {
		numbers[i] = buf[(firstMaxIndex+i)%n];
	}

	left[0] = 0;

	//��������߽磬�ҵ���һ�������Լ����±�
	for (int i = 1; i < n; ++i) {
		int index = i-1;
		while (index > 0 && numbers[index] <= numbers[i]) {
			index = left[index];
		}
		left[i] = index;
	}

	right[n-1] = n;

	//�������ұ߽磬�ҵ���һ�����ڻ����������±�
	for (int i = n-2; i >= 0; --i) {
		int index = i+1;
		while (index < n && numbers[index] < numbers[i]) {
			index = right[index];
		}
		right[i] = index;
		if (index < n &&  numbers[index] == numbers[i]) {
			count[i] = count[index] + 1;
			right[i] = right[index];
		}
	}

	long long result = 0;
	for (int i = 1; i < n; ++i) {
		result += count[i] + 2;
		if (left[i] == 0 && right[i] == n) {
			--result;
		}
	}

	std::cout << result;
}


#endif /* JD_PROTECT_H_ */
