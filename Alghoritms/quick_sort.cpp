#include <iostream>

using namespace std;

int partition(int a[], int l, int r) {
    int pivot = a[r];
    int m = l;
    for(int j = l; j < r; ++j){
        if(a[j] <= pivot){
            swap(a[j], a[m]);
            m++;
        }
    }
    swap(a[m], a[r]);
    return m;
}

void quickSort(int a[], int l, int r) {
    if (l < r) {
        int m = partition(a, l, r);
        quickSort(a, m + 1, r);
        quickSort(a, l, m - 1);
    }else{
        return;
    }
}

int main() {
    int n;
    cin >> n;
    int* data = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }

    quickSort(data, 0, n-1);

    for (int j = 0; j < n; ++j) {
        cout << data[j] << ' ';
    }
}