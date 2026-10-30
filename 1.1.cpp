#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    long long h;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> h;

    if (n == 0) return 0;

    h = h % n;

    for (int i = h; i < n; i++) {
        cout << a[i] << " ";
    }

    for (int i = 0; i < h; i++) {
        cout << a[i] << " ";
    }

    return 0;
}