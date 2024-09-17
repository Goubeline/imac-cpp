#include <iostream>

int main()
{
    float x;
    float y;
    float z;

    std::cin >> x;
    std::cin >> y;
    std::cin >> z;

    float sum = x + y + z;
    float aver = sum / 3;

    std::cout << sum + aver << std::endl;
    return 0;
}