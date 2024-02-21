#include <iostream>

void sift_Down(int * data, int element_indx, int n){
    int i = element_indx;
    while(true){
        int j = i;
        if(2 * i + 1 < n && data[2 * i + 1] < data[j]){
            j = 2 * i + 1;
        }
        if(2 * i + 2 < n && data[2 * i + 2] < data[j]){
            j = 2 * i + 2;
        }
        if(j == i){
            break;
        }
        std::swap(data[i], data[j]);
        i = j;
    }
}

int extract_min(int * data, int &n){
    int res = data[0];
    data[0] = data[--n];
    sift_Down(data, 0, n);
    return res;
}

int main(){
    int n;
    std::cin >> n;
    int copy_n = n;
    int * data = new int[n];
    int * sorted_data = new int[n];
    for(int i = 0; i < n; ++i){
        std::cin >> data[i];
    }
    for(int i = n; i >= 0; --i){
        sift_Down(data, i, n);
    }

    for(int i = 0; i < copy_n; ++i){
        sorted_data[i] = extract_min(data, n);
    }

    for(int i = 0; i < copy_n; ++i){
        std::cout << sorted_data[i] << ' ';
    }

}

// 1 4 5 9 3
