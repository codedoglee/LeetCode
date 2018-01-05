#ifndef PURCHASEORDER_H_
#define PURCHASEORDER_H_

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <map>
#include <vector>

void PurchaseOrder() {
	int n = 0;
	int m = 0;
	std::vector<int> price;
	char buf[33];
	int min = 0;
	int max = 0;
	std::vector<int> count;
	std::map<std::string, int> counter;
	int temp = 0;
	while (scanf("%d", &n) != EOF) {
		scanf("%d", &m);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &temp);
			price.push_back(temp);
		}
		std::sort(price.begin(), price.end());
		for (int i = 0; i < m; ++i) {
			scanf("%s", buf);
			std::string temp = buf;
			std::map<std::string, int>::iterator iter = counter.begin();
			bool find = false;
			for (; iter != counter.end(); ++iter) {
				if (iter->first.compare(temp) == 0) {
					++counter[iter->first];
					find = true;
					break;
				}
			}
			if (!find) {
				counter.insert(std::pair<std::string, int>(temp, 1));
			}
		}

		std::map<std::string, int>::iterator it = counter.begin();
		for (; it != counter.end(); ++it) {
			count.push_back(it->second);
		}

		std::sort(count.begin(), count.end());

		int i = count.size() - 1;
		int j = 0;
		while (i >= 0) {
			min += price[j] * count[i];
			--i;
			++j;
		}
		i = count.size() - 1;
		j = n-1;
		while (i >= 0) {
			max += price[j] * count[i];
			--j;
			--i;
		}

		printf("%d %d\n", min, max);
		min = 0;
		max = 0;
		m = 0;
		n = 0;
		price.clear();
		count.clear();
		counter.clear();
	}
}


#endif /* PURCHASEORDER_H_ */
