add_executable(test_tokenizer.out test_tokenizer.cpp)

target_link_libraries(test_tokenizer.out tokenizer boost_system boost_iostreams)

