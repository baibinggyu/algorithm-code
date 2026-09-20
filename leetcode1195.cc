#include <condition_variable>
#include <functional>
#include <mutex>
using std::function;
void printFizz(void);
void printBuzz(void);
void printNumber(int);
class FizzBuzz {
private:
  int n;
  std::mutex mtx_;
  std::condition_variable cv_;
  int cur;

public:
  FizzBuzz(int n) : cur(1) { this->n = n; }

  // printFizz() outputs "fizz".
  void fizz(function<void()> printFizz) {
    while (cur <= n) {
      std::unique_lock<std::mutex> lock(this->mtx_);
      cv_.wait(lock,
               [this] { return (cur % 3 == 0) and (cur % 5 != 0) or cur > n; });
      if (cur > n)
        break;
      printFizz();
      cur++;
      cv_.notify_all();
    }
  }

  // printBuzz() outputs "buzz".
  void buzz(function<void()> printBuzz) {
    while (cur <= n) {
      std::unique_lock<std::mutex> lock(this->mtx_);
      cv_.wait(lock,
               [this] { return (cur % 3 != 0) and (cur % 5 == 0) or cur > n; });
      if (cur > n)
        break;
      printBuzz();
      cur++;
      cv_.notify_all();
    }
  }

  // printFizzBuzz() outputs "fizzbuzz".
  void fizzbuzz(function<void()> printFizzBuzz) {
    while (cur <= n) {
      std::unique_lock<std::mutex> lock(this->mtx_);
      cv_.wait(lock,
               [this] { return (cur % 3 == 0) and (cur % 5 == 0) or cur > n; });
      if (cur > n)
        break;
      printFizzBuzz();
      cur++;
      cv_.notify_all();
    }
  }

  // printNumber(x) outputs "x", where x is an integer.
  void number(function<void(int)> printNumber) {
    while (cur <= n) {
      std::unique_lock<std::mutex> lock(this->mtx_);
      cv_.wait(lock,
               [this] { return (cur % 3 != 0) and (cur % 5 != 0) or cur > n; });
      if (cur > n)
        break;
      printNumber(cur);
      cur++;
      cv_.notify_all();
    }
  }
};
