#include <functional>
#include <mutex>
using namespace std;
class Foo {
public:
  Foo()
      : lock01_(mutex01_, std::try_to_lock),
        lock02_(mutex02_, std::try_to_lock) {}

  void first(function<void()> printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    this->lock01_.unlock();
  }

  void second(function<void()> printSecond) {
    std::lock_guard<std::mutex> lock(this->mutex01_);
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    this->lock02_.unlock();
  }

  void third(function<void()> printThird) {
    std::lock_guard<std::mutex> lock(this->mutex02_);
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }

private:
  std::mutex mutex01_;
  std::mutex mutex02_;
  std::unique_lock<std::mutex> lock01_;
  std::unique_lock<std::mutex> lock02_;
};
