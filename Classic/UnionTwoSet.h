#ifndef UNIONTWOSET_H_
#define UNIONTWOSET_H_

#include <stdio.h>
#include <algorithm>
#include <vector>

void UnionTwoSet() {
	int n = 0;
	int m = 0;
	int setA[10000];
	int setB[10000];
	std::vector<int> result;
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 0; i < n; ++i) {
			scanf("%d", &setA[i]);
		}
		for (int i = 0; i < m; ++i) {
			scanf("%d", &setB[i]);
		}
		std::sort(setA, setA+n);
		std::sort(setB, setB+m);
		int i = 0;
		int j = 0;
		int count = 0;
		while (i < n && j < m) {
			if (setA[i] < setB[j]) {
				result.push_back(setA[i]);
				++i;
			}
			else if (setA[i] == setB[j]) {
				result.push_back(setA[i]);
				++i;
				++j;
			}
			else {
				result.push_back(setB[j]);
				++j;
			}
			++count;
		}
		while (i < n) {
			result.push_back(setA[i]);
			++i;
			++count;
		}
		while (j < m) {
			result.push_back(setB[j]);
			++j;
			++count;
		}
		for (int k = 0; k < count; ++k) {
			printf("%d ", result[k]);
		}
		i = 0;
		j = 0;
		count = 0;
		printf("\n");
		result.clear();
	}
}



#endif /* UNIONTWOSET_H_ */
