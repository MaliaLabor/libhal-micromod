// Copyright 2024 - 2025 Khalil Estell and the libhal contributors
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

#include <libhal-micromod/micromod.hpp>
#include <libhal-util/serial.hpp>
#include <libhal-util/steady_clock.hpp>

bool volatile should_terminate = true;

void application()
{
  using namespace std::chrono_literals;
  using namespace hal::literals;

  auto& clock = hal::micromod::v1::uptime_clock();
  auto& console = hal::micromod::v1::console(hal::buffer<16>);
  hal::print(console,
             "This application invokes the terminate handler by throwing an "
             "uncaught exception.\n");
  hal::print(console, "Waiting 5 seconds before throwing an exception...\n");
  hal::delay(clock, 5s);

  if (should_terminate) {
    throw 5;
  }
}
