#include <iostream>

class dummy{
  private:
    float v;
  public:
    dummy(float const arg = 0.0f):v{arg}{}
    float &getter(){
      return v;
    }
};

decltype(auto) capture_ref(dummy &val){
  return val.getter();
}

auto capture(dummy &val){
  return val.getter();
}

int main(){
  auto a_ = dummy{-1.0f};
  auto b = capture(a_);
  decltype(auto) c = capture_ref(a_);
}
