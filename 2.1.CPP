
#include <iostream>
#include <vector>
using namespace std;

int iterativeSearch(vector<int> a, int target) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == target)
            return i + 1;
    }
    return -1;
}

int recursiveSearch(vector<int>& a, int target, int i) {
    if (i == a.size())
        return -1;

    if (a[i] == target)
        return i + 1;

    return recursiveSearch(a, target, i + 1);
}

int main() {
    int n, target;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> target;

    int pos1 = iterativeSearch(a, target);
    int pos2 = recursiveSearch(a, target, 0);

    cout << "Iterative position: " << pos1 << endl;
    cout << "Recursive position: " << pos2 << endl;

    return 0;
}
