// Runtime: 1524 ms, faster than 15.90% of C++ online submissions for Print in Order.
// Memory Usage: 9.2 MB, less than 100.00% of C++ online submissions for Print in Order.

class Foo {
 public:
  Foo() : is_printed_{{false, false, false}} {}
  virtual ~Foo() = default;

  void first(function<void()> printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    is_printed_[0] = true;
  }

  void second(function<void()> printSecond) {
    while (!is_printed_[0]) {
      ;
    }
    
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    is_printed_[1] = true;
  }

  void third(function<void()> printThird) {
    while (!is_printed_[1]) {
      ;
    }
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }
  
 private:
  std::array<bool, 3> is_printed_;
};
