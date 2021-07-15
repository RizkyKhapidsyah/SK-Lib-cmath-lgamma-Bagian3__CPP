#pragma warning(disable:4996)
#pragma fenv_access(on)

#include <iostream>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <cfenv>
#include <conio.h>

/*  Source by CPPReference
    Modified For Learn by Rizky Khapidsyah
    I.D.E : VS2019 */

const double pi = std::acos(-1);

int main() {
    std::cout << "lgamma(10) = " << std::lgamma(10)
        << ",  log(9!) = " << std::log(2 * 3 * 4 * 5 * 6 * 7 * 8 * 9) << '\n'
        << "lgamma(0.5) = " << std::lgamma(0.5)
        << " , log(sqrt(pi)) = " << std::log(std::sqrt(pi)) << '\n';

    std::cout << "lgamma(1) = " << std::lgamma(1) << '\n'
        << "lgamma(+Inf) = " << std::lgamma(INFINITY) << '\n';

    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "lgamma(0) = " << std::lgamma(0) << '\n';

    if (errno == ERANGE) {
        std::cout << "    errno == ERANGE: " << std::strerror(errno) << '\n';
    }
        
    if (std::fetestexcept(FE_DIVBYZERO)) {
        std::cout << "    FE_DIVBYZERO raised\n";
    }
        
    _getch();
    return 0;
}