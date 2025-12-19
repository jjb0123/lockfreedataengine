#pragma once
#include <atomic>
#include <cstddef>
#include <vector>
#include <optional>

template <typename T>
class SpscRing {
public:
    explicit SpscRing(std::size_t capacity_power_of_two)
        : capacity_(capacity_power_of_two),
          mask_(capacity_power_of_two - 1),
          buffer_(capacity_power_of_two)
    {
        if ((capacity_power_of_two & mask_) != 0) {
            throw std::runtime_error("capacity must be power of two");
        }
    }

    bool push(const T& value) {
        auto tail = tail_.load(std::memory_order_relaxed);
        auto head = head_.load(std::memory_order_acquire);

        if (tail - head == capacity_) {
            return false; 
        }

        buffer_[tail & mask_] = value;
        tail_.store(tail + 1, std::memory_order_release);
        return true;
    }

    std::optional<T> pop() {
        auto head = head_.load(std::memory_order_relaxed);
        auto tail = tail_.load(std::memory_order_acquire);

        if (head == tail) {
            return std::nullopt; 
        }

        T value = buffer_[head & mask_];
        head_.store(head + 1, std::memory_order_release);
        return value;
    }

private:
    const std::size_t capacity_;
    const std::size_t mask_;
    std::vector<T> buffer_;
    std::atomic<std::size_t> head_{0};
    std::atomic<std::size_t> tail_{0};
};
