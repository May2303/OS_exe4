#include <mutex>

class Guard {
public:
    explicit Guard(std::mutex& mtx) : mtx_(mtx) {
        mtx_.lock();
    }

    ~Guard() {
        mtx_.unlock();
    }

private:
    std::mutex& mtx_;
};