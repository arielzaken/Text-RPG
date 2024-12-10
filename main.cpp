#include <iostream>

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    if (num % 2 == 0) {
        std::cout << num << " is an even number." << std::endl;
    } else {
        std::cout << num << " is an odd number." << std::endl;
    }

    return 0;
}
