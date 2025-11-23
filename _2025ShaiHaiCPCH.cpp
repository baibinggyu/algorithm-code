#include <iostream>
#include <iomanip>
#define int long long

signed main(void){
	double x;
	std::cin >> x;
	std::cout << std::fixed << std::setprecision(3) << "Vivo " << (50 * (x / 100 + 1)) << std::endl; 

}
