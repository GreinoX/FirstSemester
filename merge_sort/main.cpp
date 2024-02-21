#include <iostream>

using namespace std;


void merge(int * array, int l, int m, int r) {
    int i = 0;
    int j = 0;
    int sub_array[r - l];
    while(l + i < m && m + j < r){
        if(array[l + i] <= array[m + j]){
            sub_array[i + j] = array[l + i];
            ++i;
        }else{
            sub_array[i + j] = array[m + j];
            ++j;
        }
    }

    while(l + i < m){
        sub_array[i + j] = array[l + i];
        ++i;
    }

    while(m + j < r){
        sub_array[i + j] = array[m + j];
        ++j;
    }

    for(int k = 0; k < (i + j); ++k){
        array[l + k] = sub_array[k];
    }
}

void merge_sort(int * array, int l, int r) {
    if(l + 1 >= r){
        return;
    }
    int pivot = (l + r) / 2;
    merge_sort(array, l, pivot);
    merge_sort(array, pivot, r);
    merge(array, l, pivot, r);
}

void echo(int * data, int n){
    cout << '\n';
    for(int i = 0; i < n; ++i){
        cout << data[i] << ' ';
    }
}

int main() {
    int n;
    cin >> n;
    int data[n];
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }

    long v = 0;
    long * p = &v;

    merge_sort(data, 0, n);
    echo(data, n);
    cout << '\n';
    cout << *p;
}