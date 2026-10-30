
#include <iostream>
#include <vector>
using namespace std;

int iterativeSearch(vector<int>& a, int target) {
    int low = 0, high = a.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (a[mid] == target)
            return mid + 1;
        else if (a[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int recursiveSearch(vector<int>& a, int low, int high, int target) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (a[mid] == target)
        return mid + 1;
    else if (a[mid] < target)
        return recursiveSearch(a, mid + 1, high, target);
    else
        return recursiveSearch(a, low, mid - 1, target);
}

int main() {
    int n, target;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> target;

    cout << "Iterative position: "
         << iterativeSearch(a, target) << endl;

    cout << "Recursive position: "
         << recursiveSearch(a, 0, n - 1, target) << endl;

    return 0;
}
