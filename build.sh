#!/bin/bash
set -e

COMPILER=${1:-clang}
CMAKE_BUILD_TYPE=${2:-Debug}

if [ "${COMPILER}" == "clang" ]; then
  if [ -e /usr/local/Cellar/llvm\@6/6.0.1_1/bin ]; then
    export PATH=/usr/local/Cellar/llvm\@6/6.0.1_1/bin:${PATH}
  fi
  export CC=clang
  export CXX=clang++
elif [ "${COMPILER}" == "gcc" ]; then
  if [ -e /usr/local/Cellar/gcc\@7/7.3.0/bin/ ]; then
    export PATH=/usr/local/Cellar/gcc\@7/7.3.0/bin:${PATH}
  fi
  export CC=gcc-7
  export CXX=g++-7
fi

BUILDPATH=".build-${COMPILER}-${CMAKE_BUILD_TYPE}"
mkdir -p ${BUILDPATH}
pushd ${BUILDPATH}
cmake -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} ..
export GTEST_COLOR=1
make all test ARGS=--verbose
popd
