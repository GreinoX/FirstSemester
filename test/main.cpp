#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> createGreyCodes(int n){
    std::vector<std::string> codes;
    if(n == 1){
        codes.push_back("0");
        codes.push_back("1");
        return codes;
    }

    std::vector<std::string> result = createGreyCodes(n - 1);
    for(int i = 0; i < result.size(); ++ i){
        codes.push_back("0" + result[i]);
    }
    for(int i = result.size() - 1; i >= 0; --i){
        codes.push_back("1" + result[i]);
    }
    return codes;
}

int main(){
    std::vector<std::string> grey_codes;
    grey_codes.push_back("0");
    grey_codes.push_back("1");
    int n;
    std::cin >> n;
    grey_codes = createGreyCodes(n);
    for(int i =0; i < grey_codes.size(); ++i){
        std::cout << grey_codes[i] << '\n';
    }
}