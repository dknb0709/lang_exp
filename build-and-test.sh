#!/bin/bash

ROOT=`pwd`

BUILD_DIR="$ROOT/build"

function build() {
  rm -rf $BUILD_DIR
  mkdir $BUILD_DIR
  cd $BUILD_DIR
  cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1
  make
}

function runtest() {
  find "$BUILD_DIR/test" -name "test_*.out" -print0 | while read -d $'\0' f
  do
    "$f"
  done
}

build

# runtest

