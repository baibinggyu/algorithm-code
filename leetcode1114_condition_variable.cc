#include <condition_variable>
#include <functional>
#include <mutex>
using namespace std;
class Foo {
private:
  std::mutex mtx_;
  std::condition_variable conditon_;
  enum class state { FIRST = 0, SECOND, THIRD };
  state cur;

public:
  Foo() : cur(state::FIRST) {}

  void first(function<void()> printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    this->cur = state::SECOND;
    this->conditon_.notify_all();
  }

  void second(function<void()> printSecond) {
    std::unique_lock<std::mutex> lock(this->mtx_);
    this->conditon_.wait(lock, [this] { return this->cur == state::SECOND; });
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    this->cur = state::THIRD;
    this->conditon_.notify_all();
  }

  void third(function<void()> printThird) {
    std::unique_lock<std::mutex> lock(this->mtx_);
    this->conditon_.wait(lock, [this] { return this->cur == state::THIRD; });
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
    this->conditon_.notify_all();
  }
};
