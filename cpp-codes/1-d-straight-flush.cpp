#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

// int max(int a, int &b);

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<int> no(5);
    vector<char> suit(5);
    for (int j = 0; j < 5; ++j) {
        char ch;
        cin >> ch;
        if (ch == 'A')no[j] = 1;
        else if (ch == 'T')no[j] = 10;
        else if (ch == 'J')no[j] = 11;
        else if (ch == 'Q')no[j] = 12;
        else if (ch == 'K')no[j] = 13;
        else no[j] = ch - '0';
        cin >> suit[j];
    }
    sort(no.begin(), no.end());
    int i;
    for (i = 0; i < 5 - 1; ++i) {
        char f = suit[i], s = suit[i + 1];
        if (f != s) {
            printf("NO");
            break;
        }
    }
    bool b = false;
    if (i == 4) {
        if (no[0] == 1 && no[1] == 10 && no[2] == 11 && no[3] == 12 && no[4] == 13) {
            printf("YES");
            b = true;
        } else
            for (int idx = 1; idx < 5; ++idx) {
                if (no[idx] != no[idx - 1] + 1) {
                    b = true;
                    printf("NO");
                    break;
                }
            }
        if (!b) {
            printf("YES");
            b = true;
        }

    }
}

