#include <coroutine>
#include <exception>
#include <iostream>


//Future:
struct ReturnObject{
    struct promise_type{
        ReturnObject get_return_object() { return {};}
        std::suspend_never initial_suspend() {return {};}
        std::suspend_never final_suspend() noexcept {return {};}
        void unhandled_exception() {}
    };
};

//Promise:
struct Awaiter {
    std::coroutine_handle<> *hp;
    constexpr bool await_ready() const noexcept {return false;}
    void await_suspend(std::coroutine_handle<> h) { *hp = h;}
    constexpr  void await_resume() const noexcept{}
};

ReturnObject counter(std::coroutine_handle<> *continuation_out) {
    Awaiter a{continuation_out};
    for (unsigned i = 0;; ++i){
        std::cout << "before await" << std::endl;
        co_await a;
        std::cout << "counter" << i << std::endl;
    }
}

void coroutines_test() {
    std::coroutine_handle<> h;

    counter(&h);
    for(int i = 0; i < 3; ++i){
        std::cout << "In main function" << std::endl;
        h();
    }
    h.destroy();
}

struct ReturnObject2 {
  struct promise_type {
    ReturnObject2 get_return_object() {
      return {
        // Uses C++20 designated initializer syntax
        .h_ = std::coroutine_handle<promise_type>::from_promise(*this)
      };
    }
    std::suspend_never initial_suspend() { return {}; }
    std::suspend_never final_suspend() noexcept { return {}; }
    void unhandled_exception() {}
  };

  std::coroutine_handle<promise_type> h_;
  operator std::coroutine_handle<promise_type>() const { return h_; }
  // A coroutine_handle<promise_type> converts to coroutine_handle<>
  operator std::coroutine_handle<>() const { return h_; }
};

ReturnObject2
counter2()
{
  for (unsigned i = 0;; ++i) {
    co_await std::suspend_always{};
    std::cout << "counter2: " << i << std::endl;
  }
}

void coroutines_test2()
{
  std::coroutine_handle<> h = counter2();
  for (int i = 0; i < 3; ++i) {
    std::cout << "In main2 function\n";
    h();
  }
  h.destroy();
}