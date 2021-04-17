#include <chrono>
struct time_elapse {
    void start() {
        start_ = std::chrono::steady_clock::now();
    }
    double end() {
        std::chrono::duration<double>dura = std::chrono::steady_clock::now() - start_;
        return dura.count();
    }
private:
    std::chrono::time_point<std::chrono::steady_clock> start_ = std::chrono::steady_clock::now();
};