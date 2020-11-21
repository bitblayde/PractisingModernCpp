#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main(){
  std::vector<int> v(150);
  std::iota(std::begin(v), std::end(v), 0);

  auto contador{0};
  auto divisible{3};


  auto val = [&divisible, &contador]<typename U> (const std::vector<U>& v) {
    std::for_each( v.begin(), v.end(), [&divisible, &contador](const U& k) {
      if (k % divisible == 0) [[unlikely]]{
        contador += 1;
      }
      else{
        contador -= 1;
      }
    } );
  };

  val(v);
  std::cout << contador << std::endl;

  for ( auto element : std::views::iota(0, 150) | std::views::filter( [&divisible]<typename U>(const U& i){ return i % divisible == 0; } )
                                                | std::views::take(10) ){
      std::cout << element << std::endl;
  }
}
