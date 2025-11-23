#include <bits/stdc++.h>
using namespace std;

string run_cmd(const string &cmd) {
    string result;
    array<char, 4096> buf{};
    FILE *pipe = popen(cmd.c_str(), "r");
    if (!pipe) return "PIPE_ERR";
    while (fgets(buf.data(), buf.size(), pipe))
        result += buf.data();
    pclose(pipe);
    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "用法: ./cmp 暴力.cpp 被测.cpp\n";
        return 1;
    }

    string brute_cpp = argv[1];
    string test_cpp  = argv[2];

    cout << "== 编译中 ==\n";

    if (system(("g++ -std=c++20 -O2 " + brute_cpp + " -o brute").c_str())) {
        cerr << "暴力解法编译失败\n"; return 1;
    }
    if (system(("g++ -std=c++20 -O2 " + test_cpp + " -o test").c_str())) {
        cerr << "被测代码编译失败\n"; return 1;
    }

    cout << "== 开始对拍 == Ctrl+C 结束\n";

    while (true) {
        // 1. 生成随机输入，写到 input.txt
        int n = rand() % 10 + 1;

        ofstream fout("input.txt");
        fout << n << "\n";
        for (int i = 0; i < n; i++)
            fout << rand() % 100 << " ";
        fout << "\n";
        fout.close();

        // 2. 执行两份程序
        string out1 = run_cmd("./brute < input.txt");
        string out2 = run_cmd("./test < input.txt");

        // 3. 比较
        if (out1 != out2) {
            cout << "\n========== WA 发现 ==========\n";
            cout << "输入:\n";
            cout << run_cmd("cat input.txt") << "\n";
            cout << "暴力输出:\n" << out1 << "\n";
            cout << "被测输出:\n" << out2 << "\n";
            cout << "=============================\n";
            break;
        }

        static int cnt = 0;
        if (++cnt % 1000 == 0)
            cout << "已对拍: " << cnt << " 次\n";
    }

    return 0;
}
