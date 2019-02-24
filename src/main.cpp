#include <iostream>
#include <string>
#include <vector>

namespace dknb {
class foo {
  int a_;

public:
  foo(int a) : a_{a} {}
  int getA() { return a_; }
};
} // namespace dknb

int main() {
  std::cin.get();
  std::vector<std::string> vec{""};

  dknb::foo f(10);
  int ret = f.getA();

  return 0;
}
