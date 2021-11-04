#include <array>
#include <iostream>

//********************************
// To use when you need array, avoid bult-in arrays. They lives in the stack (size!!)
// Should be your reference for arrays
//********************************

//OSS: How they are defined in the std library
// template <class T, std::size_t N>  // N must be known a compiler time as static arrays!!
// struct array;


// This function complains if you do not pass to it std::arrays
template <typename T, std::size_t N>
void print_array_two(const std::array<T, N>& a);  //strange syntax

// This function is suited also for other types such as std::vectors
template <typename T>
void print_array_one(const T& a);

int main() {
  std::array<int, 4> a{1, 2, 3, 4};
  std::array<int, 4> b{a};  // I can copy element-wise from another std::array
                            // this is not possible with plain built-in arrays
                            // same as auto b = a
                            
  // auto b = a;  // same as line 16
  b = a;
  for (auto x : a)  // range-based for loop as python
    std::cout << x << " ";
  std::cout << std::endl;
  // OSS: const auto x --> if you do not change the the inside values
  //      auto& x --> if you want to change elements of the array 

  for (auto x : b)
    std::cout << x << " ";
  std::cout << std::endl;

  a[0] = 0;  // same subscripting operator without bound checking (pay attention when you access elemts!!)

  for (const auto x : a)
    std::cout << x << " ";
  std::cout << std::endl;

  for (const auto x : b)
    std::cout << x << " ";
  std::cout << std::endl;

  for (auto& x : a)
    x *= 10;

  for (auto i = 0u; i < a.size(); ++i)
    std::cout << "a[" << i << "] = " << a[i] << std::endl;

  b.at(0);  // bound checking at run-time (better to use respect line 32 :)) Original was 90
  
  print_array_two(a);
  print_array_one(b);

  return 0;
}


// 2 ways to pass arrays to functions
template <typename T, std::size_t N>  // here you've also type cecking at compile time
void print_array_two(const std::array<T, N>& a) {
  for (const auto& x : a)
    std::cout << x << " ";
  std::cout << std::endl;
}

// this is easier bcs the less the templates the better the life
template <typename T>
void print_array_one(const T& a) {
  for (const auto& x : a)
    std::cout << x << " ";
  std::cout << std::endl;
}
