#include <functional>
#include <future>
using namespace std;
class Foo {
private:
  std::promise<void> promise01, promise02;

public:
  Foo() {}

  void first(function<void()> printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    this->promise01.set_value();
  }

  void second(function<void()> printSecond) {
    this->promise01.get_future().wait();
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    this->promise02.set_value();
  }

  void third(function<void()> printThird) {
    this->promise02.get_future().wait();
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }
};
