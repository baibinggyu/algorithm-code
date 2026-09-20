#include <functional>
#include <mutex>
using std::function;
class DiningPhilosophers {
private:
  std::mutex mtx_;

public:
  DiningPhilosophers() {}

  void wantsToEat(int philosopher, function<void()> pickLeftFork,
                  function<void()> pickRightFork, function<void()> eat,
                  function<void()> putLeftFork, function<void()> putRightFork) {
    std::unique_lock<std::mutex> lock(this->mtx_);
    pickLeftFork(), pickRightFork(), eat(), putLeftFork(), putRightFork();
  }
};
