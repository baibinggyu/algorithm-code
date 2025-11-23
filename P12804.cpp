#include <algorithm>
#include <iostream>
#include <vector>
#define int long long
signed main(void){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);	
	int t;std::cin >> t;
	while(t--){
		int n ;std::cin >> n;
		std::vector<int> arr(n);
		for(int i = 0;i < static_cast<int>(arr.size());i++) std::cin >> arr[i];
		if(n == 1 || n == 2){
			std::cout << 0 << std::endl;
			continue;
		}	
		std::sort(std::begin(arr),std::end(arr),[](const int & a,const int & b){return a < b;});
		int sum = 0;
		std::for_each(std::begin(arr),std::end(arr),[&sum](auto& x){sum += x;});
		bool flag = true;
		for(int i = n - 1;i >= 0;i--){
			sum -= arr[i];
			if(sum > arr[i]){
				std::cout << sum + arr[i] << std::endl;
				flag = false;	
				break;
			}
		}	
		if(flag == true) std::cout << 0 << std::endl;
	}
	return 0;
}
