#include <condition_variable>
#include <functional>
#include <mutex>
using std::function;
class H2O {
private:
  enum class State { H1 = 0, H2, O };
  State state_;
  std::mutex mtx_;
  std::condition_variable cv_;

public:
  H2O() { this->state_ = State::H1; }
  void hydrogen(function<void()> releaseHydrogen) {
    // releaseHydrogen() outputs "H". Do not change or remove this line.
    std::unique_lock<std::mutex> lock(mtx_);
    cv_.wait(lock, [this] {
      return this->state_ == State::H1 or this->state_ == State::H2;
    });
    releaseHydrogen();
    if (this->state_ == State::H1)
      this->state_ = State::H2;
    else if (this->state_ == State::H2)
      this->state_ = State::O;
    cv_.notify_all();
  }

  void oxygen(function<void()> releaseOxygen) {

    // releaseOxygen() outputs "O". Do not change or remove this line.
    std::unique_lock<std::mutex> lock(mtx_);
    cv_.wait(lock, [this] { return this->state_ == State::O; });
    releaseOxygen();
    this->state_ = State::H1;
    cv_.notify_all();
  }
};
