#include <iostream>
#include <mutex>

class Singleton {
public:
    // Static method to access the Singleton instance
    static Singleton* getInstance() {
        std::lock_guard<std::mutex> lock(mutex_);
        if (!instance_)
            instance_ = new Singleton();
        return instance_;
    }

    // Public method for demonstration
    void show() {
        std::cout << "Singleton instance address: " << this << std::endl;
    }

protected:
    Singleton() = default;  // Protected constructor to prevent instantiation

private:
    static Singleton* instance_;
    static std::mutex mutex_;  // Mutex for synchronization

    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

// Initialize static members
Singleton* Singleton::instance_ = nullptr;
std::mutex Singleton::mutex_;