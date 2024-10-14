#include <iostream>
#include <limits>
#include <tuple>

std::tuple<size_t, size_t> rec_suite(size_t n)
{
    if (n == 0)
    {
        std::cout << 'U' << n << " = 1 et V" << n << " = 2" << std::endl;
        return std::make_tuple(1, 2);
    }
    size_t u;
    size_t v;
    size_t buf;
    std::tie(buf, v) = rec_suite( n - 1);
    u = 3 * buf + 2 * v;
    v = 2 * v + buf + 1;
    std::cout << 'U' << n << " = " << u << " et V" << n << " = " << v << std::endl;
    return std::make_tuple(u, v);
}

int main()
{
    size_t n;
    do
    {
        std::cout << "Saisir le nombre d'éléments des deux suites à voir : ";
        std::cin >> n;
        if (!std::cin.fail() && std::cin.peek() == '\n' && n > 0)
        {
            break;
        }
    } while(true);
    rec_suite(n - 1);
    return 0;    
}