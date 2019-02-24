/*

#include <tokenizer.hpp>

bool tokenizer::is_space(char c) { return c == ' '; }

bool tokenizer::is_digit(char c) { return c >= '0' && c <= '9'; }

void tokenizer::tokenize() {
  while (pos_ <= src_.size()) {
    char c = src_[pos_];
    if (is_space(c)) {
      ++pos_;
      continue;
    }
    expr();
  }
}

void tokenizer::num() { char c = src_[pos_]; }

void tokenizer::expr() {
  
}

*/
