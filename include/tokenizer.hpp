#include <algorithm>
#include <boost/iostreams/device/mapped_file.hpp>  // for mmap
#include <functional>
#include <iostream>
#include <string>
#include <token.hpp>
#include <vector>

class source {
  using mapped_file = boost::iostreams::mapped_file;
  mapped_file mf_;
  const char *iter_;
  const char *eof_;

 public:
  source(const std::string &file) {
    mf_ = {file, boost::iostreams::mapped_file::readonly};
    iter_ = mf_.const_data();
    eof_ = iter_ + mf_.size();
  }
  char peek() { return *iter_; }
  void next() noexcept { ++iter_; }
  bool has_next() noexcept { return iter_ != eof_; }
};

struct token {
  t_token type;
  int value;
};

class tokenizer {
  source src_;
  std::vector<token> tokens_;

 public:
  tokenizer(const std::string &src) : src_(src) {}
  void tokenize() {
    expr();
    eof();
  }

 private:
  template <typename T>
  void callback(const T &value) {
    std::cout << "parsed: \'" << value << "\'" << std::endl;
  }
  template <typename T>
  void error(const T &reason) {
    std::cout << "error: \'" << reason << "\'" << std::endl;
  }
  void scan(std::function<bool(char)> pred) {
    src_.next();
    while (pred(src_.peek())) {
      src_.next();
    }
  }
  void scan() {
    scan([](char c) { return c == ' '; });
  }
  void expr() {
    term();
    while (src_.peek() == '+' || src_.peek() == '-') {
      callback(src_.peek());
      scan();
      term();
    }
  }
  void term() {
    factor();
    while (src_.peek() == '*' || src_.peek() == '/') {
      callback(src_.peek());
      scan();
      factor();
    }
  }
  void factor() {
    if (src_.peek() >= '0' && src_.peek() <= '9') {
      num();
    } else if (src_.peek() == '(') {
      callback(src_.peek());
      scan();
      expr();
      if (src_.peek() == ')') {
        callback(src_.peek());
        scan();
      } else {
        error(std::string("\")\" expected but got \"") + src_.peek() + "\"");
        return;
      }
    }
  }
  void num() {
    std::string s;
    while (true) {
      if (src_.peek() >= '0' && src_.peek() <= '9') {
        s += src_.peek();
        src_.next();
      } else {
        break;
      }
    }
    callback(s);
    if (src_.peek() == ' ') {
      scan();
    }
  }
  void eof() {
    if (!src_.has_next()) {
      callback("<EOF>");
    }
  }
};
