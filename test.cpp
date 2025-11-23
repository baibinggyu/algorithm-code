// #include <boost/version.hpp>
// #include <boost/config.hpp>
// #include <boost/iostreams/stream.hpp>
// #include <boost/iostreams/filtering_stream.hpp>
// #include <boost/iostreams/filter/gzip.hpp>  // 可选过滤器
// #include <iostream>
// #include <vector>
// int main(void){
//     boost::iostreams::filtering_ostream out;
//     out.push(std::cout);
//     out << "This is boost::iostreams::filtering_ostream" << std::endl;
//     std::vector<bool> test(10,false);
//     int a = 10;
//     std::cout << &a << std::endl;
//     // std::cout << &test[1] << std::endl;
// }
#include <string>
#include <iostream>
struct Node{
    int val;
    std::string str;
    Node(int val,std::string str):val(val),str(str){}
    friend std::ostream& operator<<(std::ostream& os,Node& node){
        os << node.str << " " << node.val;
        return os;
    }
};
int main(void){
    // Node node(10,"bai-yu");
    Node node{10,"baiyu"};

    std::cout << node << std::endl;
    
}