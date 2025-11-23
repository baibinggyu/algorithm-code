#include <iostream>
#include <fstream>
#include <sstream>
constexpr int SIZE = 1000;
int main(void){
    system("g++ data.cpp -o data.out");
    system("g++ std.cpp  -o std.out");
    system("g++ test.cpp -o test.out");
    int count = 0;
    while(system("diff test.txt std.txt") == 0 and count < SIZE){
        system("./data.out > data.in");
        system("./std.out < data.in > std.txt");
        system("./test.out < data.in > test.txt");
        std::fstream in("./std.in");
        std::fstream out("./std.txt");
        std::stringstream ss;
        ss << in.rdbuf();
        std::cout << ss.str();
        ss << out.rdbuf();
        std::cout << ss.str();
        in.close();
        out.close();
        std::cout << "AC" << std::endl;
        count++;
    }
    if(count == SIZE) return 0;
    std::cout << "WA" << std::endl;

    return 0;
}