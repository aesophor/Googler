// Runtime: 1524 ms, faster than 15.90% of C++ online submissions for Print in Order.
// Memory Usage: 9.2 MB, less than 100.00% of C++ online submissions for Print in Order.

class Foo {
 public:
  Foo() : is_printed_{{false, false}} {}

  void first(const function<void()>& printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    is_printed_[0] = true;
  }

  void second(const function<void()>& printSecond) {
    while (!is_printed_[0]) {
      this_thread::sleep_for(std::chrono::nanoseconds(1));
    }
    
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    is_printed_[1] = true;
  }

  void third(const function<void()>& printThird) {
    while (!is_printed_[1]) {
      this_thread::sleep_for(std::chrono::nanoseconds(1));
    }
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }
  
 private:
  std::array<bool, 2> is_printed_;
};
