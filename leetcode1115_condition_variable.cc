#include <condition_variable>
#include <functional>
#include <mutex>
using std::function;
class FooBar {
private:
  int n;
  std::mutex mtx;
  std::condition_variable cv;
  bool flag;

public:
  FooBar(int n) : flag(true) { this->n = n; }

  void foo(function<void()> printFoo) {

    for (int i = 0; i < n; i++) {
      std::unique_lock<std::mutex> lock(this->mtx);
      cv.wait(lock, [this] { return flag; });
      printFoo();
      flag = not flag;
      cv.notify_one();
    }
  }

  void bar(function<void()> printBar) {
    for (int i = 0; i < n; i++) {
      std::unique_lock<std::mutex> lock(this->mtx);
      cv.wait(lock, [this] { return not flag; });
      printBar();
      flag = not flag;
      cv.notify_one();
    }
  }
};
