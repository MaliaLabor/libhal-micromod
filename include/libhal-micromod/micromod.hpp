// Copyright 2023 Google LLC
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

#pragma once

#include <libhal/adc.hpp>
#include <libhal/can.hpp>
#include <libhal/dac.hpp>
#include <libhal/i2c.hpp>
#include <libhal/input_pin.hpp>
#include <libhal/interrupt_pin.hpp>
#include <libhal/output_pin.hpp>
#include <libhal/pwm.hpp>
#include <libhal/serial.hpp>
#include <libhal/spi.hpp>
#include <libhal/steady_clock.hpp>
#include <libhal/timer.hpp>

namespace hal::micromod::v1 {
// =============================================================================
// CORE
// =============================================================================
/**
 * @brief
 *
 */
void initialize_platform();

/**
 * @brief
 *
 * @return hal::steady_clock&
 */
hal::steady_clock& uptime_clock();

/**
 * @brief
 *
 * @return hal::timer&
 */
hal::timer& system_timer();

/**
 * @brief
 *
 */
void enter_power_saving_mode();

/**
 * @brief
 *
 * @param p_receive_buffer
 * @return hal::serial&
 */
hal::serial& console(std::span<hal::byte> p_receive_buffer);

/**
 * @brief Resets the microcontroller, restarting the program in the process.
 *
 * If the application is executed as a program or process on operating system
 * then this function should exit() with the code TBD which will alert the
 * spawner process to rerun the command.
 *
 * This function must not return.
 */
[[noreturn]] void reset();

// =============================================================================
// ON CHIP DEVICES
// =============================================================================

/**
 * @brief Driver for the board LED output pin
 *
 * @return hal::output_pin& - Statically allocated output pin driver connected
 * to the LED.
 */
hal::output_pin& led();

// =============================================================================
// ANALOG
// =============================================================================

/**
 * @brief Driver for adc pin 0
 *
 * @return hal::adc& - Statically allocated analog pin driver.
 */
hal::adc& a0();

/**
 * @brief Driver for adc pin 1
 *
 * @return hal::adc& - Statically allocated analog pin driver.
 */
hal::adc& a1();

/**
 * @brief Driver for battery analog signal which is 1/3rd of the VIN voltage
 *
 * @return hal::adc& - Statically allocated battery analog pin driver.
 */
hal::adc& battery();

/**
 * @brief Driver for dac pin 0
 *
 * @return hal::dac& - Statically allocated dac pin driver.
 */
hal::dac& d0();

/**
 * @brief Driver for dac pin 1
 *
 * @return hal::dac& - Statically allocated dac pin driver.
 */
hal::dac& d1();

/**
 * @brief Driver for pwm pin 0
 *
 * @return hal::pwm& - Statically allocated pwm pin driver.
 */
hal::pwm& pwm0();

/**
 * @brief Driver for pwm pin 1
 *
 * @return hal::pwm& - Statically allocated pwm pin driver.
 */
hal::pwm& pwm1();

// =============================================================================
// Serial Communication
// =============================================================================

/**
 * @brief Driver for the main i2c bus
 *
 * @return hal::i2c& - Statically allocated i2c driver.
 */
hal::i2c& i2c();

/**
 * @brief Driver for i2c interrupt pin
 *
 * NOTE: that this pin can be used as an interrupt pin for both or either i2c
 * buss.
 *
 * @return hal::interrupt_pin& - Statically allocated interrupt pin driver.
 */
hal::interrupt_pin& i2c_interrupt_pin();

/**
 * @brief Driver for the alternative i2c bus 1
 *
 * @return hal::i2c& - Statically allocated i2c driver.
 */
hal::i2c& i2c1();

/**
 * @brief Driver for the main spi bus
 *
 * NOTE: in future iterations of this API, there will exist an sdio port used
 * for talking to SD cards. This port is shared with the future sdio port. Take
 * care to not use this along with the sdio port in the same application as they
 * will conflict with each other resulting in undefined behavior.
 *
 * @return hal::spi&
 */
hal::spi& spi();

/**
 * @brief Driver for spi interrupt pin
 *
 * NOTE: that this pin can be used as an interrupt pin for both or either spi
 * ports.
 *
 * @return hal::interrupt_pin&
 */
hal::interrupt_pin& spi_interrupt_pin();

/**
 * @brief Driver for the alternative spi port 1
 *
 * @return hal::spi&
 */
hal::spi& spi1();

/**
 * @brief Driver for uart 1 port
 *
 * @param p_receive_buffer - The size of the receive buffer for the serial port.
 * Note that subsequent calls to the function will ignore this parameter, thus
 * the first call will set the receive buffer size. Ensure that the lifetime of
 * the buffer is equal to or exceeds the lifetime of the uart port.
 * @return hal::serial&
 */
hal::serial& uart1(std::span<hal::byte> p_receive_buffer);

/**
 * @brief Driver for uart 0 port
 *
 * @param p_receive_buffer - The size of the receive buffer for the serial port.
 * Note that subsequent calls to the function will ignore this parameter, thus
 * the first call will set the receive buffer size. Ensure that the lifetime of
 * the buffer is equal to or exceeds the lifetime of the uart port.
 * @return hal::serial&
 */
hal::serial& uart2(std::span<hal::byte> p_receive_buffer);

/**
 * @brief Driver for the can bus
 *
 * @return hal::can& - statically allocated can driver
 */
hal::can& can();

// =============================================================================
// DIGITAL
// =============================================================================

namespace output {
hal::output_pin& g0();
hal::output_pin& g1();
hal::output_pin& g2();
hal::output_pin& g3();
hal::output_pin& g4();
hal::output_pin& g5();
hal::output_pin& g6();
hal::output_pin& g7();
hal::output_pin& g8();
hal::output_pin& g9();
hal::output_pin& g10();
}  // namespace output

namespace input {
hal::input_pin& g0();
hal::input_pin& g1();
hal::input_pin& g2();
hal::input_pin& g3();
hal::input_pin& g4();
hal::input_pin& g5();
hal::input_pin& g6();
hal::input_pin& g7();
hal::input_pin& g8();
hal::input_pin& g9();
hal::input_pin& g10();
}  // namespace input

namespace interrupt {
hal::interrupt_pin& g0();
hal::interrupt_pin& g1();
hal::interrupt_pin& g2();
hal::interrupt_pin& g3();
hal::interrupt_pin& g4();
hal::interrupt_pin& g5();
hal::interrupt_pin& g6();
hal::interrupt_pin& g7();
hal::interrupt_pin& g8();
hal::interrupt_pin& g9();
hal::interrupt_pin& g10();
}  // namespace interrupt
}  // namespace hal::micromod::v1