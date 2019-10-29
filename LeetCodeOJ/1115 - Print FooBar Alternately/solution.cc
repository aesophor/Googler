// Runtime: 332 ms, faster than 73.81% of C++ online submissions for Print FooBar Alternately.
// Memory Usage: 10.5 MB, less than 100.00% of C++ online submissions for Print FooBar Alternately.

class FooBar {
 public:
  FooBar(int n) : n_(n), foo_should_print_(true) {}

  void foo(function<void()> printFoo) {
    for (int i = 0; i < n_; i++) {
      while (!foo_should_print_) {
        this_thread::sleep_for (std::chrono::nanoseconds(1));
      }
      printFoo(); // outputs "foo"
      foo_should_print_ = false;
    }
  }

  void bar(function<void()> printBar) {
    for (int i = 0; i < n_; i++) {
      while (foo_should_print_) {
        this_thread::sleep_for (std::chrono::nanoseconds(1));
      }
      printBar(); // outputs "bar"
      foo_should_print_ = true;
    }
  }
  
 private:
  int n_;
  bool foo_should_print_;
};
