#ifndef WY_FPG_H_
#define WY_FPG_H_

#include <iostream>
#include <stdlib.h>

void Solve() {
    int n = 0;
    int sum = 0;
    std::cin >> n;
    int num[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> num[i];
        sum += num[i];
    }
    if (sum % n != 0) {
        std::cout << -1;
        return;
    }
    int mean = sum / n;
    int bigSum = 0;
    for (int i = 0; i < n; ++i) {
        if (abs(num[i] - mean) % 2 != 0) {
            std::cout << -1;
            return;
        }
        else if (num[i] > mean) {
            bigSum += (num[i] - mean);
        }
    }
    std::cout << bigSum / 2;
}



#endif /* WY_FPG_H_ */
