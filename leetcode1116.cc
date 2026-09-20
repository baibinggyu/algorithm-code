#include <atomic>
#include <condition_variable>
#include <functional>
#include <mutex>
#include <ranges>
#include <vector>
using std::function;
void printNumber(int);
class ZeroEvenOdd {
private:
  int n;
  std::vector<int> vec_;
  std::mutex mtx_;
  std::condition_variable cv_;
  std::atomic<int> cnt_;
  bool flagZero;

public:
  ZeroEvenOdd(int n) : flagZero(true), cnt_(0) {
    for (auto x : std::views::iota(1, n + 1)) {
      vec_.emplace_back(0);
      vec_.emplace_back(x);
    }
  }

  // printNumber(x) outputs "x", where x is an integer.
  void zero(function<void(int)> printNumber) {
    while (cnt_ < vec_.size()) {
      std::unique_lock lock(mtx_);
      cv_.wait(lock, [this] { return cnt_ >= vec_.size() or vec_[cnt_] == 0; });
      if (cnt_ >= vec_.size())
        break;
      printNumber(vec_[cnt_++]);
      cv_.notify_all();
    }
  }

  void even(function<void(int)> printNumber) {
    while (cnt_ < vec_.size()) {
      std::unique_lock lock(mtx_);
      cv_.wait(lock, [this] {
        return cnt_ >= vec_.size() or
               ((vec_[cnt_] & 1) == 0 and vec_[cnt_] != 0);
      });
      if (cnt_ >= vec_.size())
        break;
      printNumber(vec_[cnt_++]);
      cv_.notify_all();
    }
  }

  void odd(function<void(int)> printNumber) {
    while (cnt_ < vec_.size()) {
      std::unique_lock lock(mtx_);
      cv_.wait(lock,
               [this] { return cnt_ >= vec_.size() or (vec_[cnt_] & 1) == 1; });
      if (cnt_ >= vec_.size())
        break;
      printNumber(vec_[cnt_++]);
      cv_.notify_all();
    }
  }
};
