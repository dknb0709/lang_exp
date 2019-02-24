#include <cassert>
#include <iostream>
#include <tokenizer.hpp>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "usage: command <src_path>" << std::endl;
    return 1;
  }
  tokenizer t(argv[1]);
  t.tokenize();
}
