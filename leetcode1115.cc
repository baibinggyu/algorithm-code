#include <functional>
#include <mutex>
using std::function;
class FooBar {
private:
  int n;
  std::mutex foo_mutex_;
  std::mutex bar_mutex_;

public:
  FooBar(int n) {
    this->n = n;
    this->bar_mutex_.lock();
  }

  void foo(function<void()> printFoo) {
    for (int i = 0; i < n; i++) {
      this->foo_mutex_.lock();
      printFoo();
      this->bar_mutex_.unlock();
    }
  }

  void bar(function<void()> printBar) {

    for (int i = 0; i < n; i++) {
      this->bar_mutex_.lock();
      printBar();
      this->foo_mutex_.unlock();
    }
  }
};
