#include <vector>
#include <iostream>

/////////////
// O(n) //
////////////

bool divisibleBy12_On(std::vector<int> v){
    if (v.size() < 2)
        return false;

    bool count12 = false, count1 = false;
    bool count6 = false, count2 = false;
    bool count4 = false, count3 = false;

    for (int num : v){
        if (num == 12) count12 = true;
        if (num == 1) count1 = true;
        if (num == 6) count6 = true;
        if (num == 2) count2 = true;
        if (num == 3) count3 = true;
        if (num == 4) count4 = true;
    }

    if ((count12 && count1) || (count6 && count2) || (count4 && count3)){
        return true;
    }
    return false;
}

/////////////
// O(n^2) //
////////////

bool divisibleBy12_On2(std::vector<int> v){
    if (v.size() < 2) 
        return false;
    
    for (size_t i = 0; i < v.size(); i++){
        for (size_t j = i + 1; j < v.size(); j++){
            if (v[i] * v[j] % 12 == 0){
                return true;
            }
        }
    }
    return false;
}




int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    if (divisibleBy12_On2(vec)) {
        std::cout << "Works O(n^2)" << std::endl;
    } else {
        std::cout << "No such pair exists." << std::endl;
    }

    if (divisibleBy12_On(vec)) {
        std::cout << "Works O(n)" << std::endl;
    } else {
        std::cout << "No such pair exists." << std::endl;
    }
    return 0;
}