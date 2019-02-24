add_library(tokenizer
      SHARED
        tokenizer.cpp
    )

target_include_directories(tokenizer
      PUBLIC ${PROJECT_SOURCE_DIR}/include
    )


