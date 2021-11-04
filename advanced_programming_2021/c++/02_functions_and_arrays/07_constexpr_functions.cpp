#include <chrono>  //to measure time
#include <iostream>
constexpr std::size_t fib(const unsigned int x) {
  return (x < 2) ? x : fib(x - 1) + fib(x - 2);  // both c++(11) and c++(14)
  // if (x < 2) return x;  //only c++(14)
  // else {
  //   return fib(x-1) + fib(x-2);
  // }
}
// constexpr are not very smart: if you call fib(42), for ex, it call 2^42 fib() due to the recursion and it will exceed the limit of the recursion call and you get an error (templates does not have this problem, they are more robust)




std::size_t fib_rt(const std::size_t x) {  // rt --> runtime (sure to be evaluated at runtime)
  if (x < 2)
    return x;
  return fib(x - 1) + fib(x - 2);
}



template <unsigned i>
constexpr std::size_t fib_t() {  //fib<5>()
  return fib_t<i - 1>() + fib_t<i - 2>();
}
// OSS: //fib<n>() not allowed bcs n MUST be known at compiler time!! (it is known at runtime)

// the 2 base cases works as specialization of the general fib_t templete function
template <>
constexpr std::size_t fib_t<0>() {  // base case for fib_t
  return 0;
}

template <>
constexpr std::size_t fib_t<1>() {  // base case for fib_t
  return 1;
}




#if __cplusplus > 201700L

template <unsigned i>
constexpr std::size_t fib_t17() {
  if constexpr (i < 2)
    return i;
  else {  // very important
    return fib_t17<i - 1>() + fib_t17<i - 2>();
  }
}
#endif

constexpr unsigned int num{24};

int main() {
  {
    auto t0 = std::chrono::high_resolution_clock::now();  //it reuturn a difficult and strange type --> better to use auto 
    constexpr auto x = fib(num);  // if you remove constexpr might happen that the function is evaluated at runtime even if it is a constexpr function!! (--> put always constexpr when a constexpr function return
    auto t1 = std::chrono::high_resolution_clock::now();
    auto elapsed =
        std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0);  //can use second instead microsecond
    std::cout << "constexpr: " << x << " [" << elapsed.count() << " us]"
              << std::endl;
  }
  
  // different scopes to avoid thta compiler complains about that we used multiple time the same variable name. Renaming the same variable was too difficult??
  {
    auto t0 = std::chrono::high_resolution_clock::now();
    auto x = fib_rt(num);
    auto t1 = std::chrono::high_resolution_clock::now();
    auto elapsed =
        std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0);
    std::cout << "run time: " << x << " [" << elapsed.count() << " us]"
              << std::endl;
  }

  {
    auto t0 = std::chrono::high_resolution_clock::now();
    auto x = fib_t<num>();
    auto t1 = std::chrono::high_resolution_clock::now();
    auto elapsed =
        std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0);
    std::cout << "template: " << x << " [" << elapsed.count() << " us]"
              << std::endl;
  }

#if __cplusplus > 201700L
  {
    auto t0 = std::chrono::high_resolution_clock::now();
    auto x = fib_t17<num>();
    auto t1 = std::chrono::high_resolution_clock::now();
    auto elapsed =
        std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0);
    std::cout << "c++17: " << x << " [" << elapsed.count() << " us]"
              << std::endl;
  }

#endif

  return 0;
}
