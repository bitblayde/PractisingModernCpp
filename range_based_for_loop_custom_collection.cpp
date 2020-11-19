#include <iostream>

template <typename U, size_t const s>
class custom_arr{
  private:
    U arr[s] = {};
  public:
    custom_arr() = default;

    U const &get_by_index(size_t const i) const{
      if (i < s){
        return arr[i];
      }
      throw std::out_of_range("out of range");
    }

    void set_by_index(U const &v, size_t const i){
      if (i < s){
        arr[i] = v;
      }
      else{
        throw std::out_of_range("out of range");
      }
    }

    size_t size()const{
      return s;
    }
};

/*
  Range-based for loop body C++17

    auto && __range = range_expression;
    auto __begin = begin_expr;
    auto __end = end_expr;

    for (; __begin != __end; ++__begin) {
      range_declaration = *__begin;
      loop_statement
    }

  to implement:
    operator++ post and prefix
    operator*
    operator!=
    begin()
    end()

*/
template <typename U, typename T, size_t const s>
class custom_arr_iterator{
  private:
    T &cont;
    size_t index;
  public:
    custom_arr_iterator(T &c, size_t const i) :cont(c), index(i) {}

    size_t const& get_index()const{
      return index;
    }

    custom_arr_iterator operator++(int){
      auto copy = *this;
      return ++(*copy);
    }

    custom_arr_iterator& operator++(){
      ++index;
      return *this;
    }

    bool operator!=(const custom_arr_iterator &v){
      return v.get_index() != index;
    }

    U const &operator*() const{
      return cont.get_by_index(index);
    }
};

// ALIAS
template <typename U, size_t const s>
using custom_arr_it = custom_arr_iterator<U, custom_arr<U, s>, s>;

template <typename U, size_t const s>
using custom_arr_it_const = custom_arr_iterator<U, custom_arr<U, s> const, s>;


//  BEGIN
template <typename U, size_t const s>
inline custom_arr_it<U, s> begin(  custom_arr<U, s>& arr ){
  return custom_arr_it<U, s>(arr, 0);
}
template <typename U, size_t const s>
inline custom_arr_it_const<U, s> begin(  custom_arr<U, s> const & arr ){
  return custom_arr_it_const<U, s>(arr, 0);
}

//  END
template <typename U, size_t const s>
inline custom_arr_it<U, s> end(  custom_arr<U, s>& arr ){
  return custom_arr_it<U, s>(arr, arr.size() );
}

template <typename U, size_t const s>
inline custom_arr_it_const<U, s> end(  custom_arr<U, s> const & arr ){
  return custom_arr_it_const<U, s>(arr, arr.size());
}


int main(){
  custom_arr<std::string, 5> test;
  test.set_by_index("hola,", 0);
  test.set_by_index("esto", 1);
  test.set_by_index("es", 2);
  test.set_by_index("una", 3);
  test.set_by_index("prueba", 4);

  for (auto && t : test){
    std::cout << t << std::endl;
  }
}
