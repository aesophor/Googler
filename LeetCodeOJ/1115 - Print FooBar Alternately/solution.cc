// Runtime: 280 ms, faster than 92.02% of C++ online submissions for Print FooBar Alternately.
// Memory Usage: 10.6 MB, less than 100.00% of C++ online submissions for Print FooBar Alternately.

class FooBar {
 public:
  FooBar(int n) : n_(n), foo_should_print_(true) {}

  void foo(const function<void()>& printFoo) {
    for (int i = 0; i < n_; i++) {
      std::unique_lock<std::mutex> l(m_);
      cv_.wait(l, [=]() { return foo_should_print_; });
      
      printFoo(); // outputs "foo"
      
      foo_should_print_ = false;
      cv_.notify_one();
    }
  }

  void bar(const function<void()>& printBar) {
    for (int i = 0; i < n_; i++) {
      std::unique_lock<std::mutex> l(m_);
      cv_.wait(l, [=]() { return !foo_should_print_; });
      
      printBar(); // outputs "bar"
      
      foo_should_print_ = true;
      cv_.notify_one();
    }
  }
  
 private:
  int n_;
  bool foo_should_print_;
  
  std::mutex m_;
  std::condition_variable cv_;
};
