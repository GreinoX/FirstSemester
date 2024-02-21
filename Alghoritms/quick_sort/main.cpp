#include <iostream>
using namespace std;

//БЫСТРАЯ СОРТИРОВКА ЛОМУТА
/*
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


void quick_sort(int a[], int l, int r) {
    if (l < r) {
        int m = partition(a, l, r);
        quickSort(a, m + 1, r);
        quickSort(a, l, m - 1);
    }else{
        return;
    }
}

*/
//КОНЕЦ БЫСТРОЙ СОРТИРОВКИ ЛОМУТА

//БЫСТРАЯ СОРТИРОВКА РАНДОМИЗИРОВАННАЯ
/*
int randPartition(int array[], int l, int r){
    int pivot = rand() % (r - l + 1) + l;
    swap(array[pivot], array[r]);
    return partition(array, l , r);
}

void quick_sort(int array[], int l, int r){
    if(l >= r){
        return;
    }
    int m = randPartition(array, l, r);
    quick_sort(array, l, m - 1);
    quick_sort(array, m + 1, r);
}
*/
//КОНЕЦ БЫСТРОЙ РАНДОМИЗИРОВАННОЙ СОРТИРОВКИ

//БЫСТРАЯ СОРТИРОВКА ОТНОСИТЕЛЬНОГО СРЕДНЕ ЗНАЧ 
/*
int partition(int array[], int lB, int rB){
    int pivot = (array[lB] + array[rB - 1]) / 2;
    int i = lB;
    int j = rB;
    while(i <= j){
        while(array[i] < pivot) ++i;
        while(array[j] > pivot) --j;
        if(i >= j){
            break;
        }
        swap(array[i++], array[j--]);
    }
    return j; 
}

void quick_sort(int array[], int lB, int rB){
    if(lB >= rB){
        return;
    }
    int m_pivot = partition(array, lB, rB);
    quick_sort(array, lB, m_pivot);
    quick_sort(array, m_pivot + 1, rB);
}
 */

int partition(int * array, int lb, int rb){
    int pivot = array[(lb + rb) / 2];
    int i = lb;
    int j = rb;
    while (i <= j){
        while(array[i] < pivot){
            i++;
        }
        while(array[j] > pivot){
            j--;
        }
        if(i >= j) break;
        std::swap(array[i++], array[j--]);
    }
    return j;
}

void quick_sort(int * array, int lb, int rb){
    if(rb - lb >= 1){
        int m = partition(array, lb, rb);
        quick_sort(array, lb, m - 1);
        quick_sort(array, m + 1, rb);
    }else{
        return;
    }
}

int main() {
    int n;
    cin >> n;
    int data[n];
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }

    quick_sort(data, 0, n-1);

    for (int j = 0; j < n; ++j) {
        cout << data[j] << ' ';
    }
}
