# Copyright 2024 Khalil Estell
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
cmake_minimum_required(VERSION 3.15)

project(libhal-util LANGUAGES CXX)

set(TEST_SOURCES_LIST
  tests/as_bytes.test.cpp
  tests/can.test.cpp
  tests/bit.test.cpp
  tests/enum.test.cpp
  tests/i2c.test.cpp
  tests/input_pin.test.cpp
  tests/interrupt_pin.test.cpp
  tests/map.test.cpp
  tests/math.test.cpp
  tests/move_interceptor.test.cpp
  tests/output_pin.test.cpp
  tests/overflow_counter.test.cpp
  tests/serial.test.cpp
  tests/spi.test.cpp
  tests/static_callable.test.cpp
  tests/serial_coroutines.test.cpp
  tests/static_list.test.cpp
  tests/steady_clock.test.cpp
  tests/streams.test.cpp
  tests/timeout.test.cpp
  tests/units.test.cpp
  tests/main.test.cpp
)

set(SOURCES_LIST
  src/steady_clock.cpp
  src/streams.cpp
)

if(NOT ${CMAKE_CROSSCOMPILING})
  libhal_unit_test(
    SOURCES
    ${SOURCES_LIST}
    ${TEST_SOURCES_LIST}

    PACKAGES
    libhal

    LINK_LIBRARIES
    libhal::libhal
  )
endif()

libhal_make_library(
  LIBRARY_NAME libhal-util

  SOURCES
  ${SOURCES_LIST}

  PACKAGES
  libhal

  LINK_LIBRARIES
  libhal::libhal
)
