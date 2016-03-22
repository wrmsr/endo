#include <algorithm>
#include <functional>
#include <list>

#include <gtest/gtest.h>
#include <ftl/functional.h>
#include <ftl/prelude.h>
#include <ftl/maybe.h>
#include <ftl/maybe_trans.h>
#include <ftl/sum_type.h>

#include "endo/endo.hpp"

template<typename T>
using listM = ftl::maybeT<std::list<T>>;

TEST(test_stuff, test_stuff) {
//  ftl::sum_type<std::string, int> x{ftl::constructor<int>(), 3};
//  int y = x.match(
//    [](int x) { return x + 1; },
//    [](const std::string &) { return 0; }
//  );
//
//  listM<int> ms{ftl::inplace_tag(), ftl::just(1), ftl::nothing<int>(), ftl::just(2)};
//
//  for (auto m : *ms) {
//    m.matchE(
//      [](int x) { std::cout << x << ", "; },
//      [](ftl::Nothing) { std::cout << "nothing, "; }
//    );
//  }
//  std::cout << std::endl;

//  auto plus = ftl::curry(std::plus<int>);
//  auto addOne = plus(1);
//
//  auto x = addOne(2); // x = 3
//  auto y = addOne(x); // y = 4
}

TEST(test_fibs, test_fib) {
  ASSERT_EQ(1, 1);
}
