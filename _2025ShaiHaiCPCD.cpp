#include <iostream>
#define int long long
signed main(void){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int t;std::cin >> t;
	while(t--){
		int a , b , x , y;
		std::cin >> a >> b >> x >> y;
		if(a < x or b > y) {
			std::cout << "No" << std::endl;
			continue;
		}
		if(a == x and b == y) {
			std::cout << "Yes" << std::endl;
			continue;
		}
		if(a == x){
			if((b & (~y)) == 0){
				std::cout << "Yes" << std::endl;
				continue;
			}
		}
		if(b == y){
			if((a | x) == a) {
				std::cout << "Yes" << std::endl;
				continue;
			}
		}
		std::cout << "No" << std::endl;
	}
}
