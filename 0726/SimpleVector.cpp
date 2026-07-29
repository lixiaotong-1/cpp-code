#include <iostream>
#include <memory>
template <typename T>
class SimpleVector
{
private:
    T* start;
    T* finish;
    T* end_of_storage;
    std::allocator<T> allocator;
public:
    size_t size() const {
        return finish - start;
    }
    size_t capacity() const {
        return end_of_storage - start;
    }
    bool is_empty() const {
        return start == finish;
    }
    
    SimpleVector(): start(nullptr), finish(nullptr), end_of_storage(nullptr) {}
    ~SimpleVector() {
        for (T* iter = start; iter != finish; ++iter) {
            allocator.destroy(iter);
        }
        if (start) {
            allocator.deallocate(start, capacity());
        }
    }
    // copy construction
    SimpleVector(const SimpleVector<T>& other) {
        size_t sz = other.size();
        size_t cap = other.capacity();
        start = allocator.allocate(cap);
        finish = start;
        for (T* cur = other.start; cur != other.finish; ++cur) {
            allocator.construct(finish, *cur);
            ++finish;
        }
        end_of_storage = start + cap;
    }

    SimpleVector& operator=(const SimpleVector<T>& other) {
        if (&other == this) {
            return *this;
        }
        for (T* cur = start; cur != finish; ++cur) {
            allocator.destroy(cur);
        }
        allocator.deallocate(start, capacity());
        size_t sz = other.size();
        size_t cap = other.capacity();
        start = allocator.allocate(cap);
        finish = start;
        for (T* cur = other.start; cur != other.finish; ++cur) {
            allocator.construct(finish, *cur);
            ++finish;
        }
        end_of_storage = start + cap;
        return *this;
    }

    SimpleVector(SimpleVector<T>&& other) noexcept {
        start = other.start;
        finish = other.finish;
        end_of_storage = other.end_of_storage;
        other.start = nullptr;
        other.finish = nullptr;
        other.end_of_storage = nullptr;
    }

    SimpleVector& operator=(SimpleVector<T>&& other) noexcept {
        if (&other == this) {
            return *this;
        }
        for (T* cur = start; cur != finish; ++cur) {
            allocator.destroy(cur);
        }
        allocator.deallocate(start, capacity());
        start = other.start;
        finish = other.finish;
        end_of_storage = other.end_of_storage;
        other.start = nullptr;
        other.finish = nullptr;
        other.end_of_storage = nullptr;
        return *this;
    }

    void reallocate() {
        size_t cap = capacity();
        size_t newcap = cap == 0 ? 1 : 2 * cap;
        T* newstart = allocator.allocate(newcap);
        T* newfinish = newstart;
        for (T* cur = start; cur != finish; ++cur) {
            allocator.construct(newfinish, std::move(*cur));
            ++newfinish;
            allocator.destroy(cur);
        } 
        allocator.deallocate(start, cap);
        start = newstart;
        finish = newfinish;
        end_of_storage = newstart + newcap;
    }

    void push_back(const T& a) {
        if (finish == end_of_storage) {
            // 扩容
            reallocate();
        }
       allocator.construct(finish, a);
        ++finish;
    }

    void push_back(T&& a) {
        if (finish == end_of_storage) {
            // 扩容
            reallocate();
        }
       allocator.construct(finish, std::move(a));
        ++finish;
    }

    template <typename... Args>
    void emplace_back(Args&&... args) {
        if (finish == end_of_storage) {
            reallocate();
        }
        allocator.construct(finish, std::forward<Args>(args)...);
        ++finish;
    }
    
    void pop_back() {
        if (is_empty()) {
            return;
        }
        --finish;
        allocator.destroy(finish);
    }

    T& operator[](size_t index) {
        return start[index];
    }

    const T& operator[](size_t index) const {
        return start[index];
    }

    T* begin() {
        return start;
    }

    T* end() {
        return finish;
    }

    T* begin() const {
        return start;
    }

    T* end() const {
        return finish;
    }

};

int main() {
    SimpleVector<int> simplevec;
    simplevec.emplace_back(3);
    simplevec.emplace_back(4);
    simplevec.emplace_back(5);
    simplevec.emplace_back(6);
    simplevec.emplace_back(7);
    for (auto& n: simplevec) {
        std::cout << n << " ";
    }
    std::cout << "\n";
    std::cout << "size = " << simplevec.size() << ", cap = " << simplevec.capacity() << "\n";
    simplevec.pop_back();
    for (auto& n: simplevec) {
        std::cout << n << " ";
    }
    std::cout << "\n";
    simplevec.push_back(10);
    simplevec.push_back(10);
    simplevec.push_back(10);
    for (auto& n: simplevec) {
        std::cout << n << " ";
    }
    std::cout << "\n";
}
