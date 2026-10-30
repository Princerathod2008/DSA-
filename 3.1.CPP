
#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> a, int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }

    for (int x : a)
        cout << x << " ";
    cout << endl;
}

void selectionSort(vector<int> a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex])
                minIndex = j;
        }

        swap(a[i], a[minIndex]);
    }

    for (int x : a)
        cout << x << " ";
    cout << endl;
}

void insertionSort(vector<int> a, int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }

    for (int x : a)
        cout << x << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    vector<int> marks(n);
    for (int i = 0; i < n; i++)
        cin >> marks[i];

    cout << "Bubble Sort: ";
    bubbleSort(marks, n);

    cout << "Selection Sort: ";
    selectionSort(marks, n);

    cout << "Insertion Sort: ";
    insertionSort(marks, n);

    return 0;
}
