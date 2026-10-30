#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> books(n);
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        cin >> books[i];
        freq[books[i]]++;
    }

    for (auto book : freq) {
        if (book.second > 1) {
            cout << book.first << " ";
        }
    }

    return 0;
}