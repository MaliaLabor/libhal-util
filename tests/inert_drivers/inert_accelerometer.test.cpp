// Copyright 2024 Khalil Estell
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <libhal-util/inert_drivers/inert_accelerometer.hpp>

#include <boost/ut.hpp>

namespace hal {
boost::ut::suite inert_accelerometer_test = []() {
  using namespace boost::ut;
  "inert_accelerometer"_test = []() {
    // Setup
    constexpr auto expected =
      accelerometer::read_t{ .x = 0.1f, .y = 0.2f, .z = 0.3f };
    inert_accelerometer test(expected);

    // Exercise
    auto result = test.read();

    // Verify
    expect(that % expected.x == result.x);
    expect(that % expected.y == result.y);
    expect(that % expected.z == result.z);
  };
};
}  // namespace hal
