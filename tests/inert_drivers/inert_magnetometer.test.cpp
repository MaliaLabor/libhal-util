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

#include <libhal-util/inert_drivers/inert_magnetometer.hpp>

#include <boost/ut.hpp>

namespace hal {
boost::ut::suite inert_magnetometer_test = []() {
  using namespace boost::ut;
  "inert_magnetometer"_test = []() {
    // Setup
    constexpr auto expected_read = magnetometer::read_t{ 0.1f, 0.2f, 0.3f };
    inert_magnetometer test(expected_read);

    // Exercise
    auto result = test.read();

    // Verify
    expect(that % expected_read.x == result.x);
    expect(that % expected_read.y == result.y);
    expect(that % expected_read.z == result.z);
  };
};
}  // namespace hal