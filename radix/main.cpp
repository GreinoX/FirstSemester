#include <iostream>

void radix(int n, int t, int k, std::string *abc) {
    int alphabet[26];
    int position[26];
    std::string output[n];
    for (int i = 0; i < 26; ++i) {
        alphabet[i] = 0;
        position[i] = 0;
    }
    for(int i = 0; i < n; ++i){
        char element = abc[i][k - t];
        element -= 97;
        alphabet[element]++;

    }
    position[0] = alphabet[0] - 1;
    for(int s = 1; s < 26; ++s){
        position[s] = position[s - 1] + alphabet[s];
    }

    for(int i = n - 1; i >= 0; --i){
        output[position[((int)abc[i][k - t]) - 97]--] = abc[i];
    }

    for(int h = 0; h < n; ++h){
        abc[h] = output[h];
    }
}

void insertion_sort(std::string * array, int n, int min_digit){
    std::string key;
    int s;
    for(int j = 1; j < n; ++j){
        key = array[j];
        s = j - 1;
        while(s >= 0 && key[min_digit] < array[s][min_digit]){
            array[s + 1] = array[s];
            --s;
        }
        array[s + 1] = key;
    }
}


int main() {

    int n, k, t;
    std::cin >> n >> k >> t;
    std::string data[n];
    for(int j = 0; j < n; ++j){
        std::cin >> data[j];
    }
    for(int i = 1; i <= t; ++i){
        radix(n, i, k, data);
    }

    for(int s = 0; s < n; ++s){
        std::cout << data[s] << '\n';
    }
    return 0;
}
