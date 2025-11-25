#include <iostream>
#include <cmath>
#include <vector>
int main(void){
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);
	int t; std::cin >> t;
	while(t--){
		int n;std::cin >> n;
		int pre = -1;
		int size = -1;
		for(int i = 2;i <= ::sqrt(2 *n);i++){
			int num = 2 * n - i * i + i;
			int den = 2 * i;
			int sub = num / den;
			if(num > 0 && num % den == 0 && sub > pre ){
				pre = sub;
				size = i;
			}
		}
		if(pre == -1){
			std::cout << "IMPOSSIBLE" << std::endl;
		}else{
			std::cout << n << " = " << pre ;
			for(int i = 1;i < size;i++)
				std::cout << " + " << pre + i ;
			std::cout << std::endl;
		}
	}

}
