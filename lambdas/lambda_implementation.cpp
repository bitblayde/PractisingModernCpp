#include <iostream>
#include <vector>
#include <algorithm>

// Aproximated lambda generated implementation by compiler.
template <typename T>
struct __even_lambda_1__{
  T divisible;

  template<typename U1>
  auto operator()(U1 const n1) const{
    return n1 % divisible == 0;
  }
  __even_lambda_1__(const T & val) :divisible(val){};
  __even_lambda_1__() = default;
  __even_lambda_1__(const __even_lambda_1__ &) = default;
  __even_lambda_1__(__even_lambda_1__ &&) = default;
  __even_lambda_1__& operator=(const __even_lambda_1__ &) = delete;
  ~__even_lambda_1__() = default;
};

int main(){
  std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto const divisible = 2;
  
  auto even_lambda = [](auto const & e){
    return e % 2 == 0;
  };
  __even_lambda_1__<int> lam(divisible);

  auto total_even = std::count_if(std::begin(v), std::end(v), even_lambda);
  auto total_even_struct = std::count_if(std::begin(v), std::end(v), lam);

  std::cout << total_even << std::endl;
  std::cout << total_even_struct << std::endl;
}
