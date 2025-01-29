#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n, c;
    std::cin >> n >> c;
    std::vector<int> a(n);

    int pos_c = -1;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] == c) {
            pos_c = i;
        }
    }

    std::unordered_map<int, int> leftBalance;
    int balance = 0;
    leftBalance[balance] = 1;
    for (int i = pos_c - 1; i >= 0; i--) {
        if (a[i] > c) {
            balance++;
        } else if (a[i] < c) {
            balance--;
        }

        leftBalance[balance]++;
    }

    balance = 0;
    int result = 0;
    for (int i = pos_c; i < n; i++) {
        if (a[i] > c) {
            balance++;
        } else if (a[i] < c) {
            balance--;
        }
        result += leftBalance[-balance];
    }

    std::cout << result << std::endl;
    return 0;
}
