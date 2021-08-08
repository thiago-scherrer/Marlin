/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https:
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https:
 *
 */
#pragma once

/**
 * Configuration_adv.h
 *
 * Advanced settings.
 * Only change these if you know exactly what you're doing.
 * Some of these settings can damage your printer if improperly set!
 *
 * Basic settings can be found in Configuration.h
 */
#define CONFIGURATION_ADV_H_VERSION 02000901
/**
 * Thermocouple sensors are quite sensitive to noise.  Any noise induced in
 * the sensor wires, such as by stepper motor wires run in parallel to them,
 * may result in the thermocouple sensor reporting spurious errors.  This
 * value is the number of errors which can occur in a row before the error
 * is reported.  This allows us to ignore intermittent error conditions while
 * still detecting an actual failure, which should result in a continuous
 * stream of errors from the sensor.
 *
 * Set this value to 0 to fail on the first error to occur.
 */
#define THERMOCOUPLE_MAX_ERRORS 15
#if TEMP_SENSOR_0 == 1000
  #define HOTEND0_PULLUP_RESISTOR_OHMS 4700
  #define HOTEND0_RESISTANCE_25C_OHMS  100000
  #define HOTEND0_BETA                 3950
#endif

#if TEMP_SENSOR_1 == 1000
  #define HOTEND1_PULLUP_RESISTOR_OHMS 4700
  #define HOTEND1_RESISTANCE_25C_OHMS  100000
  #define HOTEND1_BETA                 3950
#endif

#if TEMP_SENSOR_2 == 1000
  #define HOTEND2_PULLUP_RESISTOR_OHMS 4700
  #define HOTEND2_RESISTANCE_25C_OHMS  100000
  #define HOTEND2_BETA                 3950
#endif

#if TEMP_SENSOR_3 == 1000
  #define HOTEND3_PULLUP_RESISTOR_OHMS 4700
  #define HOTEND3_RESISTANCE_25C_OHMS  100000
  #define HOTEND3_BETA                 3950
#endif

#if TEMP_SENSOR_4 == 1000
  #define HOTEND4_PULLUP_RESISTOR_OHMS 4700
  #define HOTEND4_RESISTANCE_25C_OHMS  100000
  #define HOTEND4_BETA                 3950
#endif

#if TEMP_SENSOR_5 == 1000
  #define HOTEND5_PULLUP_RESISTOR_OHMS 4700
  #define HOTEND5_RESISTANCE_25C_OHMS  100000
  #define HOTEND5_BETA                 3950
#endif

#if TEMP_SENSOR_6 == 1000
  #define HOTEND6_PULLUP_RESISTOR_OHMS 4700
  #define HOTEND6_RESISTANCE_25C_OHMS  100000
  #define HOTEND6_BETA                 3950
#endif

#if TEMP_SENSOR_7 == 1000
  #define HOTEND7_PULLUP_RESISTOR_OHMS 4700
  #define HOTEND7_RESISTANCE_25C_OHMS  100000
  #define HOTEND7_BETA                 3950
#endif

#if TEMP_SENSOR_BED == 1000
  #define BED_PULLUP_RESISTOR_OHMS     4700
  #define BED_RESISTANCE_25C_OHMS      100000
  #define BED_BETA                     3950
#endif

#if TEMP_SENSOR_CHAMBER == 1000
  #define CHAMBER_PULLUP_RESISTOR_OHMS 4700
  #define CHAMBER_RESISTANCE_25C_OHMS  100000
  #define CHAMBER_BETA                 3950
#endif

#if TEMP_SENSOR_COOLER == 1000
  #define COOLER_PULLUP_RESISTOR_OHMS 4700
  #define COOLER_RESISTANCE_25C_OHMS  100000
  #define COOLER_BETA                 3950
#endif

#if TEMP_SENSOR_PROBE == 1000
  #define PROBE_PULLUP_RESISTOR_OHMS   4700
  #define PROBE_RESISTANCE_25C_OHMS    100000
  #define PROBE_BETA                   3950
#endif

#if TEMP_SENSOR_REDUNDANT == 1000
  #define REDUNDANT_PULLUP_RESISTOR_OHMS   4700
  #define REDUNDANT_RESISTANCE_25C_OHMS    100000
  #define REDUNDANT_BETA                   3950
#endif

/**
 * Configuration options for MAX Thermocouples (-2, -3, -5).
 *   FORCE_HW_SPI:   Ignore SCK/MOSI/MISO pins and just use the CS pin & default SPI bus.
 *   MAX31865_WIRES: Set the number of wires for the probe connected to a MAX31865 board, 2-4. Default: 2
 *   MAX31865_50HZ:  Enable 50Hz filter instead of the default 60Hz.
 */

/**
 * Hephestos 2 24V heated bed upgrade kit.
 * https:
 */

#if ENABLED(HEPHESTOS2_HEATED_BED_KIT)
  #undef TEMP_SENSOR_BED
  #define TEMP_SENSOR_BED 70
  #define HEATER_BED_INVERTING true
#endif
#if DISABLED(PIDTEMPBED)
  #define BED_CHECK_INTERVAL 5000
  #if ENABLED(BED_LIMIT_SWITCHING)
    #define BED_HYSTERESIS 2
  #endif
#endif
#if DISABLED(PIDTEMPCHAMBER)
  #define CHAMBER_CHECK_INTERVAL 5000
  #if ENABLED(CHAMBER_LIMIT_SWITCHING)
    #define CHAMBER_HYSTERESIS 2
  #endif
#endif

#if TEMP_SENSOR_CHAMBER

  #if ENABLED(CHAMBER_FAN)
    #define CHAMBER_FAN_MODE 2
    #if CHAMBER_FAN_MODE == 0
      #define CHAMBER_FAN_BASE  255
    #elif CHAMBER_FAN_MODE == 1
      #define CHAMBER_FAN_BASE  128
      #define CHAMBER_FAN_FACTOR 25
    #elif CHAMBER_FAN_MODE == 2
      #define CHAMBER_FAN_BASE  128
      #define CHAMBER_FAN_FACTOR 25
    #elif CHAMBER_FAN_MODE == 3
      #define CHAMBER_FAN_BASE  128
      #define CHAMBER_FAN_FACTOR 25
    #endif
  #endif
  #if ENABLED(CHAMBER_VENT)
    #define CHAMBER_VENT_SERVO_NR  1
    #define HIGH_EXCESS_HEAT_LIMIT 5
    #define LOW_EXCESS_HEAT_LIMIT  3
    #define MIN_COOLING_SLOPE_TIME_CHAMBER_VENT 20
    #define MIN_COOLING_SLOPE_DEG_CHAMBER_VENT 1.5
  #endif
#endif
#if TEMP_SENSOR_COOLER
  #define COOLER_MINTEMP           8
  #define COOLER_MAXTEMP          26
  #define COOLER_DEFAULT_TEMP     16
  #define TEMP_COOLER_HYSTERESIS   1
  #define COOLER_PIN               8
  #define COOLER_INVERTING     false
  #define TEMP_COOLER_PIN         15
  #define COOLER_FAN
  #define COOLER_FAN_INDEX         0
  #if ENABLED(COOLER_FAN)
    #define COOLER_FAN_BASE      100
    #define COOLER_FAN_FACTOR     25
  #endif
#endif

#if ENABLED(LASER_COOLANT_FLOW_METER)
  #define FLOWMETER_PIN         20
  #define FLOWMETER_PPL       5880
  #define FLOWMETER_INTERVAL  1000
  #define FLOWMETER_SAFETY
  #if ENABLED(FLOWMETER_SAFETY)
    #define FLOWMETER_MIN_LITERS_PER_MINUTE 1.5
  #endif
#endif

/**
 * Thermal Protection provides additional protection to your printer from damage
 * and fire. Marlin always includes safe min and max temperature ranges which
 * protect against a broken or disconnected thermistor wire.
 *
 * The issue: If a thermistor falls out, it will report the much lower
 * temperature of the air in the room, and the the firmware will keep
 * the heater on.
 *
 * The solution: Once the temperature reaches the target, start observing.
 * If the temperature stays too far below the target (hysteresis) for too
 * long (period), the firmware will halt the machine as a safety precaution.
 *
 * If you get false positives for "Thermal Runaway", increase
 * THERMAL_PROTECTION_HYSTERESIS and/or THERMAL_PROTECTION_PERIOD
 */
#if ENABLED(THERMAL_PROTECTION_HOTENDS)
  #define THERMAL_PROTECTION_PERIOD 40
  #define THERMAL_PROTECTION_HYSTERESIS 4
  #if BOTH(ADAPTIVE_FAN_SLOWING, PIDTEMP)

  #endif

  /**
   * Whenever an M104, M109, or M303 increases the target temperature, the
   * firmware will wait for the WATCH_TEMP_PERIOD to expire. If the temperature
   * hasn't increased by WATCH_TEMP_INCREASE degrees, the machine is halted and
   * requires a hard reset. This test restarts with any M104/M109/M303, but only
   * if the current temperature is far enough below the target for a reliable
   * test.
   *
   * If you get false positives for "Heating failed", increase WATCH_TEMP_PERIOD
   * and/or decrease WATCH_TEMP_INCREASE. WATCH_TEMP_INCREASE should not be set
   * below 2.
   */
  #define WATCH_TEMP_PERIOD  20
  #define WATCH_TEMP_INCREASE 2
#endif

/**
 * Thermal Protection parameters for the bed are just as above for hotends.
 */
#if ENABLED(THERMAL_PROTECTION_BED)
  #define THERMAL_PROTECTION_BED_PERIOD        20
  #define THERMAL_PROTECTION_BED_HYSTERESIS     2

  /**
   * As described above, except for the bed (M140/M190/M303).
   */
  #define WATCH_BED_TEMP_PERIOD                60
  #define WATCH_BED_TEMP_INCREASE               2
#endif

/**
 * Thermal Protection parameters for the heated chamber.
 */
#if ENABLED(THERMAL_PROTECTION_CHAMBER)
  #define THERMAL_PROTECTION_CHAMBER_PERIOD    20
  #define THERMAL_PROTECTION_CHAMBER_HYSTERESIS 2

  /**
   * Heated chamber watch settings (M141/M191).
   */
  #define WATCH_CHAMBER_TEMP_PERIOD            60
  #define WATCH_CHAMBER_TEMP_INCREASE           2
#endif

/**
 * Thermal Protection parameters for the laser cooler.
 */
#if ENABLED(THERMAL_PROTECTION_COOLER)
  #define THERMAL_PROTECTION_COOLER_PERIOD    10
  #define THERMAL_PROTECTION_COOLER_HYSTERESIS 3

  /**
   * Laser cooling watch settings (M143/M193).
   */
  #define WATCH_COOLER_TEMP_PERIOD            60
  #define WATCH_COOLER_TEMP_INCREASE           3
#endif

#if ENABLED(PIDTEMP)

  #if ENABLED(PID_EXTRUSION_SCALING)
    #define DEFAULT_Kc (100)
    #define LPQ_MAX_LEN 50
  #endif

  /**
   * Add an experimental additional term to the heater power, proportional to the fan speed.
   * A well-chosen Kf value should add just enough power to compensate for power-loss from the cooling fan.
   * You can either just add a constant compensation with the DEFAULT_Kf value
   * or follow the instruction below to get speed-dependent compensation.
   *
   * Constant compensation (use only with fanspeeds of 0% and 100%)
   * ---------------------------------------------------------------------
   * A good starting point for the Kf-value comes from the calculation:
   *   kf = (power_fan * eff_fan) / power_heater * 255
   * where eff_fan is between 0.0 and 1.0, based on fan-efficiency and airflow to the nozzle / heater.
   *
   * Example:
   *   Heater: 40W, Fan: 0.1A * 24V = 2.4W, eff_fan = 0.8
   *   Kf = (2.4W * 0.8) / 40W * 255 = 12.24
   *
   * Fan-speed dependent compensation
   * --------------------------------
   * 1. To find a good Kf value, set the hotend temperature, wait for it to settle, and enable the fan (100%).
   *    Make sure PID_FAN_SCALING_LIN_FACTOR is 0 and PID_FAN_SCALING_ALTERNATIVE_DEFINITION is not enabled.
   *    If you see the temperature drop repeat the test, increasing the Kf value slowly, until the temperature
   *    drop goes away. If the temperature overshoots after enabling the fan, the Kf value is too big.
   * 2. Note the Kf-value for fan-speed at 100%
   * 3. Determine a good value for PID_FAN_SCALING_MIN_SPEED, which is around the speed, where the fan starts moving.
   * 4. Repeat step 1. and 2. for this fan speed.
   * 5. Enable PID_FAN_SCALING_ALTERNATIVE_DEFINITION and enter the two identified Kf-values in
   *    PID_FAN_SCALING_AT_FULL_SPEED and PID_FAN_SCALING_AT_MIN_SPEED. Enter the minimum speed in PID_FAN_SCALING_MIN_SPEED
   */

  #if ENABLED(PID_FAN_SCALING)

    #if ENABLED(PID_FAN_SCALING_ALTERNATIVE_DEFINITION)
      #define PID_FAN_SCALING_AT_FULL_SPEED 13.0
      #define PID_FAN_SCALING_AT_MIN_SPEED   6.0
      #define PID_FAN_SCALING_MIN_SPEED     10.0

      #define DEFAULT_Kf (255.0*PID_FAN_SCALING_AT_MIN_SPEED-PID_FAN_SCALING_AT_FULL_SPEED*PID_FAN_SCALING_MIN_SPEED)/(255.0-PID_FAN_SCALING_MIN_SPEED)
      #define PID_FAN_SCALING_LIN_FACTOR (PID_FAN_SCALING_AT_FULL_SPEED-DEFAULT_Kf)/255.0

    #else
      #define PID_FAN_SCALING_LIN_FACTOR (0)
      #define DEFAULT_Kf 10
      #define PID_FAN_SCALING_MIN_SPEED 10
    #endif
  #endif
#endif

/**
 * Automatic Temperature Mode
 *
 * Dynamically adjust the hotend target temperature based on planned E moves.
 *
 * (Contrast with PID_EXTRUSION_SCALING, which tracks E movement and adjusts PID
 *  behavior using an additional kC value.)
 *
 * Autotemp is calculated by (mintemp + factor * mm_per_sec), capped to maxtemp.
 *
 * Enable Autotemp Mode with M104/M109 F<factor> S<mintemp> B<maxtemp>.
 * Disable by sending M104/M109 with no F parameter (or F0 with AUTOTEMP_PROPORTIONAL).
 */
#define AUTOTEMP
#if ENABLED(AUTOTEMP)
  #define AUTOTEMP_OLDWEIGHT    0.98
  #if ENABLED(AUTOTEMP_PROPORTIONAL)
    #define AUTOTEMP_MIN_P      0
    #define AUTOTEMP_MAX_P      5
    #define AUTOTEMP_FACTOR_P   1
  #endif
#endif

/**
 * High Temperature Thermistor Support
 *
 * Thermistors able to support high temperature tend to have a hard time getting
 * good readings at room and lower temperatures. This means TEMP_SENSOR_X_RAW_LO_TEMP
 * will probably be caught when the heating element first turns on during the
 * preheating process, which will trigger a min_temp_error as a safety measure
 * and force stop everything.
 * To circumvent this limitation, we allow for a preheat time (during which,
 * min_temp_error won't be triggered) and add a min_temp buffer to handle
 * aberrant readings.
 *
 * If you want to enable this feature for your hotend thermistor(s)
 * uncomment and set values > 0 in the constants below
 */
#if ENABLED(EXTRUDER_RUNOUT_PREVENT)
  #define EXTRUDER_RUNOUT_MINTEMP 190
  #define EXTRUDER_RUNOUT_SECONDS 30
  #define EXTRUDER_RUNOUT_SPEED 1500
  #define EXTRUDER_RUNOUT_EXTRUDE 5
#endif

/**
 * Hotend Idle Timeout
 * Prevent filament in the nozzle from charring and causing a critical jam.
 */
#define HOTEND_IDLE_TIMEOUT
#if ENABLED(HOTEND_IDLE_TIMEOUT)
  #define HOTEND_IDLE_TIMEOUT_SEC (5*60)
  #define HOTEND_IDLE_MIN_TRIGGER   180
  #define HOTEND_IDLE_NOZZLE_TARGET   0
  #define HOTEND_IDLE_BED_TARGET      0
#endif

#define TEMP_SENSOR_AD595_OFFSET  0.0
#define TEMP_SENSOR_AD595_GAIN    1.0
#define TEMP_SENSOR_AD8495_OFFSET 0.0
#define TEMP_SENSOR_AD8495_GAIN   1.0

/**
 * Controller Fan
 * To cool down the stepper drivers and MOSFETs.
 *
 * The fan turns on automatically whenever any driver is enabled and turns
 * off (or reduces to idle speed) shortly after drivers are turned off.
 */

#if ENABLED(USE_CONTROLLER_FAN)

  #define CONTROLLERFAN_SPEED_MIN      0
  #define CONTROLLERFAN_SPEED_ACTIVE 255
  #define CONTROLLERFAN_SPEED_IDLE     0
  #define CONTROLLERFAN_IDLE_TIME     60

  #if ENABLED(CONTROLLER_FAN_EDITABLE)
    #define CONTROLLER_FAN_MENU
  #endif
#endif

/**
 * PWM Fan Scaling
 *
 * Define the min/max speeds for PWM fans (as set with M106).
 *
 * With these options the M106 0-255 value range is scaled to a subset
 * to ensure that the fan has enough power to spin, or to run lower
 * current fans with higher current. (e.g., 5V/12V fans with 12V/24V)
 * Value 0 always turns off the fan.
 *
 * Define one or both of these to override the default 0-255 range.
 */

/**
 * FAST PWM FAN Settings
 *
 * Use to change the FAST FAN PWM frequency (if enabled in Configuration.h)
 * Combinations of PWM Modes, prescale values and TOP resolutions are used internally to produce a
 * frequency as close as possible to the desired frequency.
 *
 * FAST_PWM_FAN_FREQUENCY [undefined by default]
 *   Set this to your desired frequency.
 *   If left undefined this defaults to F = F_CPU/(2*255*1)
 *   i.e., F = 31.4kHz on 16MHz microcontrollers or F = 39.2kHz on 20MHz microcontrollers.
 *   These defaults are the same as with the old FAST_PWM_FAN implementation - no migration is required
 *   NOTE: Setting very low frequencies (< 10 Hz) may result in unexpected timer behavior.
 *
 * USE_OCR2A_AS_TOP [undefined by default]
 *   Boards that use TIMER2 for PWM have limitations resulting in only a few possible frequencies on TIMER2:
 *   16MHz MCUs: [62.5KHz, 31.4KHz (default), 7.8KHz, 3.92KHz, 1.95KHz, 977Hz, 488Hz, 244Hz, 60Hz, 122Hz, 30Hz]
 *   20MHz MCUs: [78.1KHz, 39.2KHz (default), 9.77KHz, 4.9KHz, 2.44KHz, 1.22KHz, 610Hz, 305Hz, 153Hz, 76Hz, 38Hz]
 *   A greater range can be achieved by enabling USE_OCR2A_AS_TOP. But note that this option blocks the use of
 *   PWM on pin OC2A. Only use this option if you don't need PWM on 0C2A. (Check your schematic.)
 *   USE_OCR2A_AS_TOP sacrifices duty cycle control resolution to achieve this broader range of frequencies.
 */
#if ENABLED(FAST_PWM_FAN)
#endif

/**
 * Use one of the PWM fans as a redundant part-cooling fan
 */
/**
 * Extruder cooling fans
 *
 * Extruder auto fans automatically turn on when their extruders'
 * temperatures go above EXTRUDER_AUTO_FAN_TEMPERATURE.
 *
 * Your board's pins file specifies the recommended pins. Override those here
 * or set to -1 to disable completely.
 *
 * Multiple extruders can be assigned to the same pin in which case
 * the fan will turn on when any selected extruder is above the threshold.
 */
#define E0_AUTO_FAN_PIN 50
#define E1_AUTO_FAN_PIN -1
#define E2_AUTO_FAN_PIN -1
#define E3_AUTO_FAN_PIN -1
#define E4_AUTO_FAN_PIN -1
#define E5_AUTO_FAN_PIN -1
#define E6_AUTO_FAN_PIN -1
#define E7_AUTO_FAN_PIN -1
#define CHAMBER_AUTO_FAN_PIN -1
#define COOLER_AUTO_FAN_PIN -1
#define COOLER_FAN_PIN -1

#define EXTRUDER_AUTO_FAN_TEMPERATURE 50
#define EXTRUDER_AUTO_FAN_SPEED 255
#define CHAMBER_AUTO_FAN_TEMPERATURE 30
#define CHAMBER_AUTO_FAN_SPEED 255
#define COOLER_AUTO_FAN_TEMPERATURE 18
#define COOLER_AUTO_FAN_SPEED 255

/**
 * Part-Cooling Fan Multiplexer
 *
 * This feature allows you to digitally multiplex the fan output.
 * The multiplexer is automatically switched at tool-change.
 * Set FANMUX[012]_PINs below for up to 2, 4, or 8 multiplexed fans.
 */
#define FANMUX0_PIN -1
#define FANMUX1_PIN -1
#define FANMUX2_PIN -1

/**
 * M355 Case Light on-off / brightness
 */

#if ENABLED(CASE_LIGHT_ENABLE)

  #define INVERT_CASE_LIGHT false
  #define CASE_LIGHT_DEFAULT_ON true
  #define CASE_LIGHT_DEFAULT_BRIGHTNESS 105

  #if ENABLED(NEOPIXEL_LED)

  #endif
  #if EITHER(RGB_LED, RGBW_LED)

  #endif
  #if EITHER(CASE_LIGHT_USE_NEOPIXEL, CASE_LIGHT_USE_RGB_LED)
    #define CASE_LIGHT_DEFAULT_COLOR { 255, 255, 255, 255 }
  #endif
#endif

#if ENABLED(EXTERNAL_CLOSED_LOOP_CONTROLLER)
#endif

/**
 * Dual Steppers / Dual Endstops
 *
 * This section will allow you to use extra E drivers to drive a second motor for X, Y, or Z axes.
 *
 * For example, set X_DUAL_STEPPER_DRIVERS setting to use a second motor. If the motors need to
 * spin in opposite directions set INVERT_X2_VS_X_DIR. If the second motor needs its own endstop
 * set X_DUAL_ENDSTOPS. This can adjust for "racking." Use X2_USE_ENDSTOP to set the endstop plug
 * that should be used for the second endstop. Extra endstops will appear in the output of 'M119'.
 *
 * Use X_DUAL_ENDSTOP_ADJUSTMENT to adjust for mechanical imperfection. After homing both motors
 * this offset is applied to the X2 motor. To find the offset home the X axis, and measure the error
 * in X2. Dual endstop offsets can be set at runtime with 'M666 X<offset> Y<offset> Z<offset>'.
 */
#if ENABLED(X_DUAL_STEPPER_DRIVERS)
  #if ENABLED(X_DUAL_ENDSTOPS)
    #define X2_USE_ENDSTOP _XMAX_
    #define X2_ENDSTOP_ADJUSTMENT  0
  #endif
#endif
#if ENABLED(Y_DUAL_STEPPER_DRIVERS)
  #if ENABLED(Y_DUAL_ENDSTOPS)
    #define Y2_USE_ENDSTOP _YMAX_
    #define Y2_ENDSTOP_ADJUSTMENT  0
  #endif
#endif
#define NUM_Z_STEPPER_DRIVERS 1

#if NUM_Z_STEPPER_DRIVERS > 1
  #if ENABLED(Z_MULTI_ENDSTOPS)
    #define Z2_USE_ENDSTOP          _XMAX_
    #define Z2_ENDSTOP_ADJUSTMENT   0
    #if NUM_Z_STEPPER_DRIVERS >= 3
      #define Z3_USE_ENDSTOP        _YMAX_
      #define Z3_ENDSTOP_ADJUSTMENT 0
    #endif
    #if NUM_Z_STEPPER_DRIVERS >= 4
      #define Z4_USE_ENDSTOP        _ZMAX_
      #define Z4_ENDSTOP_ADJUSTMENT 0
    #endif
  #endif
#endif

#if ENABLED(E_DUAL_STEPPER_DRIVERS)

#endif

/**
 * Dual X Carriage
 *
 * This setup has two X carriages that can move independently, each with its own hotend.
 * The carriages can be used to print an object with two colors or materials, or in
 * "duplication mode" it can print two identical or X-mirrored objects simultaneously.
 * The inactive carriage is parked automatically to prevent oozing.
 * X1 is the left carriage, X2 the right. They park and home at opposite ends of the X axis.
 * By default the X2 stepper is assigned to the first unused E plug on the board.
 *
 * The following Dual X Carriage modes can be selected with M605 S<mode>:
 *
 *   0 : (FULL_CONTROL) The slicer has full control over both X-carriages and can achieve optimal travel
 *       results as long as it supports dual X-carriages. (M605 S0)
 *
 *   1 : (AUTO_PARK) The firmware automatically parks and unparks the X-carriages on tool-change so
 *       that additional slicer support is not required. (M605 S1)
 *
 *   2 : (DUPLICATION) The firmware moves the second X-carriage and extruder in synchronization with
 *       the first X-carriage and extruder, to print 2 copies of the same object at the same time.
 *       Set the constant X-offset and temperature differential with M605 S2 X[offs] R[deg] and
 *       follow with M605 S2 to initiate duplicated movement.
 *
 *   3 : (MIRRORED) Formbot/Vivedino-inspired mirrored mode in which the second extruder duplicates
 *       the movement of the first except the second extruder is reversed in the X axis.
 *       Set the initial X offset and temperature differential with M605 S2 X[offs] R[deg] and
 *       follow with M605 S3 to initiate mirrored movement.
 */

#if ENABLED(DUAL_X_CARRIAGE)
  #define X1_MIN_POS X_MIN_POS
  #define X1_MAX_POS X_BED_SIZE
  #define X2_MIN_POS    80
  #define X2_MAX_POS   353
  #define X2_HOME_DIR    1
  #define X2_HOME_POS X2_MAX_POS
  #define DEFAULT_DUAL_X_CARRIAGE_MODE DXC_AUTO_PARK_MODE
  #define DEFAULT_DUPLICATION_X_OFFSET 100

#endif

/**
 * Homing Procedure
 * Homing (G28) does an indefinite move towards the endstops to establish
 * the position of the toolhead relative to the workspace.
 */

/** TEST */
#define HOMING_BUMP_MM      { 0, 0, 2 }
#define HOMING_BUMP_DIVISOR { 2, 2, 4 }

#define QUICK_HOME
#if ENABLED(BLTOUCH)
  /**
   * Either: Use the defaults (recommended) or: For special purposes, use the following DEFINES
   * Do not activate settings that the probe might not understand. Clones might misunderstand
   * advanced commands.
   *
   * Note: If the probe is not deploying, do a "Reset" and "Self-Test" and then check the
   *       wiring of the BROWN, RED and ORANGE wires.
   *
   * Note: If the trigger signal of your probe is not being recognized, it has been very often
   *       because the BLACK and WHITE wires needed to be swapped. They are not "interchangeable"
   *       like they would be with a real switch. So please check the wiring first.
   *
   * Settings for all BLTouch and clone probes:
   */

  #define BLTOUCH_DELAY 500

  /**
   * Settings for BLTOUCH Classic 1.2, 1.3 or BLTouch Smart 1.0, 2.0, 2.2, 3.0, 3.1, and most clones:
   */

  /**
   * Settings for BLTouch Smart 3.0 and 3.1
   * Summary:
   *   - Voltage modes: 5V and OD (open drain - "logic voltage free") output modes
   *   - High-Speed mode
   *   - Disable LCD voltage options
   */

  /**
   * Danger: Don't activate 5V mode unless attached to a 5V-tolerant controller!
   * V3.0 or 3.1: Set default mode to 5V mode at Marlin startup.
   * If disabled, OD mode is the hard-coded default on 3.0
   * On startup, Marlin will compare its eeprom to this value. If the selected mode
   * differs, a mode set eeprom write will be completed at initialization.
   * Use the option below to force an eeprom write to a V3.1 probe regardless.
   */
  /**
   * Safety: Activate if connecting a probe with an unknown voltage mode.
   * V3.0: Set a probe into mode selected above at Marlin startup. Required for 5V mode on 3.0
   * V3.1: Force a probe with unknown mode into selected mode at Marlin startup ( = Probe EEPROM write )
   * To preserve the life of the probe, use this once then turn it off and re-flash.
   */
  /**
   * Use "HIGH SPEED" mode for probing.
   * Danger: Disable if your probe sometimes fails. Only suitable for stable well-adjusted systems.
   * This feature was designed for Deltabots with very fast Z moves; however, higher speed Cartesians
   * might be able to use it. If the machine can't raise Z fast enough the BLTouch may go into ALARM.
   */

#endif

/**
 * Z Steppers Auto-Alignment
 * Add the G34 command to align multiple Z steppers using a bed probe.
 */

#if ENABLED(Z_STEPPER_AUTO_ALIGN)

  /**
   * Orientation for the automatically-calculated probe positions.
   * Override Z stepper align points with 'M422 S<index> X<pos> Y<pos>'
   *
   * 2 Steppers:  (0)     (1)
   *               |       |   2   |
   *               | 1   2 |       |
   *               |       |   1   |
   *
   * 3 Steppers:  (0)     (1)     (2)     (3)
   *               |   3   | 1     | 2   1 |     2 |
   *               |       |     3 |       | 3     |
   *               | 1   2 | 2     |   3   |     1 |
   *
   * 4 Steppers:  (0)     (1)     (2)     (3)
   *               | 4   3 | 1   4 | 2   1 | 3   2 |
   *               |       |       |       |       |
   *               | 1   2 | 2   3 | 3   4 | 4   1 |
   */
  #ifndef Z_STEPPER_ALIGN_XY

  #endif
  #if ENABLED(Z_STEPPER_ALIGN_KNOWN_STEPPER_POSITIONS)

    #define Z_STEPPER_ALIGN_STEPPER_XY { { 210.7, 102.5 }, { 152.6, 220.0 }, { 94.5, 102.5 } }
  #else
    #define Z_STEPPER_ALIGN_AMP 1.0
  #endif
  #define G34_MAX_GRADE              5
  #define Z_STEPPER_ALIGN_ITERATIONS 3
  #define Z_STEPPER_ALIGN_ACC        0.02
  #define RESTORE_LEVELING_AFTER_G34
  #define HOME_AFTER_G34
#endif

#if ENABLED(ASSISTED_TRAMMING)
 #define TRAMMING_POINT_XY { {  20, 20 }, { 200,  20 }, { 200, 200 }, { 20, 200 } }
  #define TRAMMING_POINT_NAME_1 "Front-Left"
  #define TRAMMING_POINT_NAME_2 "Front-Right"
  #define TRAMMING_POINT_NAME_3 "Back-Right"
  #define TRAMMING_POINT_NAME_4 "Back-Left"

  #define RESTORE_LEVELING_AFTER_G35
  /**
   * Screw thread:
   *   M3: 30 = Clockwise, 31 = Counter-Clockwise
   *   M4: 40 = Clockwise, 41 = Counter-Clockwise
   *   M5: 50 = Clockwise, 51 = Counter-Clockwise
   */
  #define TRAMMING_SCREW_THREAD 40

#endif

#define AXIS_RELATIVE_MODES { false, false, false, false }

#define INVERT_X_STEP_PIN false
#define INVERT_Y_STEP_PIN false
#define INVERT_Z_STEP_PIN false
#define INVERT_I_STEP_PIN false
#define INVERT_J_STEP_PIN false
#define INVERT_K_STEP_PIN false
#define INVERT_E_STEP_PIN false

/**
 * Idle Stepper Shutdown
 * Set DISABLE_INACTIVE_? 'true' to shut down axis steppers after an idle period.
 * The Deactive Time can be overridden with M18 and M84. Set to 0 for No Timeout.
 */
#define DEFAULT_STEPPER_DEACTIVE_TIME 120
#define DISABLE_INACTIVE_X true
#define DISABLE_INACTIVE_Y true
#define DISABLE_INACTIVE_Z true
#define DISABLE_INACTIVE_I true
#define DISABLE_INACTIVE_J true
#define DISABLE_INACTIVE_K true
#define DISABLE_INACTIVE_E true
#define DEFAULT_MINIMUMFEEDRATE       0.0
#define DEFAULT_MINTRAVELFEEDRATE     0.0
#define DEFAULT_MINSEGMENTTIME        20000

#define SLOWDOWN
#if ENABLED(SLOWDOWN)
  #define SLOWDOWN_DIVISOR 8
#endif

/**
 * XY Frequency limit
 * Reduce resonance by limiting the frequency of small zigzag infill moves.
 * See https:
 * Use M201 F<freq> G<min%> to change limits at runtime.
 */

#ifdef XY_FREQUENCY_LIMIT
  #define XY_FREQUENCY_MIN_PERCENT 5
#endif
#define MINIMUM_PLANNER_SPEED 0.05
#if ENABLED(BACKLASH_COMPENSATION)
  #define BACKLASH_DISTANCE_MM { 0, 0, 0 }
  #define BACKLASH_CORRECTION    0.0

  #if ENABLED(BACKLASH_GCODE)

    #define MEASURE_BACKLASH_WHEN_PROBING

    #if ENABLED(MEASURE_BACKLASH_WHEN_PROBING)

      #define BACKLASH_MEASUREMENT_LIMIT       0.5
      #define BACKLASH_MEASUREMENT_RESOLUTION  0.005
      #define BACKLASH_MEASUREMENT_FEEDRATE    Z_PROBE_FEEDRATE_SLOW
    #endif
  #endif
#endif

/**
 * Automatic backlash, position and hotend offset calibration
 *
 * Enable G425 to run automatic calibration using an electrically-
 * conductive cube, bolt, or washer mounted on the bed.
 *
 * G425 uses the probe to touch the top and sides of the calibration object
 * on the bed and measures and/or correct positional offsets, axis backlash
 * and hotend offsets.
 *
 * Note: HOTEND_OFFSET and CALIBRATION_OBJECT_CENTER must be set to within
 *       ±5mm of true values for G425 to succeed.
 */

#if ENABLED(CALIBRATION_GCODE)
  #define CALIBRATION_MEASUREMENT_RESOLUTION     0.01

  #define CALIBRATION_FEEDRATE_SLOW             60
  #define CALIBRATION_FEEDRATE_FAST           1200
  #define CALIBRATION_FEEDRATE_TRAVEL         3000
  #define CALIBRATION_NOZZLE_TIP_HEIGHT          1.0
  #define CALIBRATION_NOZZLE_OUTER_DIAMETER      2.0

  #define CALIBRATION_OBJECT_CENTER     { 264.0, -22.0,  -2.0 }
  #define CALIBRATION_OBJECT_DIMENSIONS {  10.0,  10.0,  10.0 }

  #define CALIBRATION_MEASURE_RIGHT
  #define CALIBRATION_MEASURE_FRONT
  #define CALIBRATION_MEASURE_LEFT
  #define CALIBRATION_MEASURE_BACK

  #ifndef CALIBRATION_PIN

    #define CALIBRATION_PIN_INVERTING false

    #define CALIBRATION_PIN_PULLUP
  #endif
#endif

/**
 * Adaptive Step Smoothing increases the resolution of multi-axis moves, particularly at step frequencies
 * below 1kHz (for AVR) or 10kHz (for ARM), where aliasing between axes in multi-axis moves causes audible
 * vibration and surface artifacts. The algorithm adapts to provide the best possible step smoothing at the
 * lowest stepping frequencies.
 */
#define ADAPTIVE_STEP_SMOOTHING

/**
 * Custom Microstepping
 * Override as-needed for your setup. Up to 3 MS pins are supported.
 */
#define MICROSTEP_MODES { 16, 16, 16, 16, 16, 16 }

/**
 *  @section  stepper motor current
 *
 *  Some boards have a means of setting the stepper motor current via firmware.
 *
 *  The power on motor currents are set by:
 *    PWM_MOTOR_CURRENT - used by MINIRAMBO & ULTIMAIN_2
 *                         known compatible chips: A4982
 *    DIGIPOT_MOTOR_CURRENT - used by BQ_ZUM_MEGA_3D, RAMBO & SCOOVO_X9H
 *                         known compatible chips: AD5206
 *    DAC_MOTOR_CURRENT_DEFAULT - used by PRINTRBOARD_REVF & RIGIDBOARD_V2
 *                         known compatible chips: MCP4728
 *    DIGIPOT_I2C_MOTOR_CURRENTS - used by 5DPRINT, AZTEEG_X3_PRO, AZTEEG_X5_MINI_WIFI, MIGHTYBOARD_REVE
 *                         known compatible chips: MCP4451, MCP4018
 *
 *  Motor currents can also be set by M907 - M910 and by the LCD.
 *    M907 - applies to all.
 *    M908 - BQ_ZUM_MEGA_3D, RAMBO, PRINTRBOARD_REVF, RIGIDBOARD_V2 & SCOOVO_X9H
 *    M909, M910 & LCD - only PRINTRBOARD_REVF & RIGIDBOARD_V2
 */
/**
 * I2C-based DIGIPOTs (e.g., Azteeg X3 Pro)
 */
#if EITHER(DIGIPOT_MCP4018, DIGIPOT_MCP4451)
  #define DIGIPOT_I2C_NUM_CHANNELS 8

  #define DIGIPOT_I2C_MOTOR_CURRENTS { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 }

  /**
   * Common slave addresses:
   *
   *                        A   (A shifted)   B   (B shifted)  IC
   * Smoothie              0x2C (0x58)       0x2D (0x5A)       MCP4451
   * AZTEEG_X3_PRO         0x2C (0x58)       0x2E (0x5C)       MCP4451
   * AZTEEG_X5_MINI        0x2C (0x58)       0x2E (0x5C)       MCP4451
   * AZTEEG_X5_MINI_WIFI         0x58              0x5C        MCP4451
   * MIGHTYBOARD_REVE      0x2F (0x5E)                         MCP4018
   */
#endif

#if EITHER(IS_ULTIPANEL, EXTENSIBLE_UI)
  #define MANUAL_FEEDRATE { 50*60, 50*60, 4*60, 2*60 }
  #define FINE_MANUAL_MOVE 0.005
  #if IS_ULTIPANEL
    #define MANUAL_E_MOVES_RELATIVE
    #define ULTIPANEL_FEEDMULTIPLY
  #endif
#endif
#define ENCODER_RATE_MULTIPLIER
#if ENABLED(ENCODER_RATE_MULTIPLIER)
  #define ENCODER_10X_STEPS_PER_SEC   30
  #define ENCODER_100X_STEPS_PER_SEC  80
#endif

#if ENABLED(BEEP_ON_FEEDRATE_CHANGE)
  #define FEEDRATE_CHANGE_BEEP_DURATION   10
  #define FEEDRATE_CHANGE_BEEP_FREQUENCY 440
#endif

#if HAS_LCD_MENU
  #if HAS_BED_PROBE
    #define PROBE_OFFSET_WIZARD
    #if ENABLED(PROBE_OFFSET_WIZARD)
      #define PROBE_OFFSET_WIZARD_XY_POS { X_CENTER, Y_CENTER }
    #endif
  #endif

  #if ENABLED(LCD_INFO_MENU)

  #endif

  /**
   * LED Control Menu
   * Add LED Control to the LCD menu
   */

  #if ENABLED(LED_CONTROL_MENU)
    #define LED_COLOR_PRESETS

    #if ENABLED(LED_COLOR_PRESETS)
      #define LED_USER_PRESET_RED        255
      #define LED_USER_PRESET_GREEN      128
      #define LED_USER_PRESET_BLUE         0
      #define LED_USER_PRESET_WHITE      255
      #define LED_USER_PRESET_BRIGHTNESS 255

    #endif
    #if ENABLED(NEO2_COLOR_PRESETS)
      #define NEO2_USER_PRESET_RED        255
      #define NEO2_USER_PRESET_GREEN      128
      #define NEO2_USER_PRESET_BLUE         0
      #define NEO2_USER_PRESET_WHITE      255
      #define NEO2_USER_PRESET_BRIGHTNESS 255

    #endif
  #endif
#endif

#if HAS_DISPLAY

  #if ENABLED(SHOW_BOOTSCREEN)
    #define BOOTSCREEN_TIMEOUT 4000
    #if EITHER(HAS_MARLINUI_U8GLIB, TFT_COLOR_UI)
      #define BOOT_MARLIN_LOGO_SMALL
    #endif
  #endif
#define STATUS_MESSAGE_SCROLLING

  #define LCD_SET_PROGRESS_MANUALLY

#endif

#if EITHER(SDSUPPORT, LCD_SET_PROGRESS_MANUALLY) && ANY(HAS_MARLINUI_U8GLIB, HAS_MARLINUI_HD44780, IS_TFTGLCD_PANEL, EXTENSIBLE_UI)
  #define SHOW_REMAINING_TIME
  #if ENABLED(SHOW_REMAINING_TIME)
    #define USE_M73_REMAINING_TIME
    #define ROTATE_PROGRESS_DISPLAY
  #endif

  #if EITHER(HAS_MARLINUI_U8GLIB, EXTENSIBLE_UI)
    #define PRINT_PROGRESS_SHOW_DECIMALS
  #endif

  #if EITHER(HAS_MARLINUI_HD44780, IS_TFTGLCD_PANEL)

    #if ENABLED(LCD_PROGRESS_BAR)
      #define PROGRESS_BAR_BAR_TIME 2000
      #define PROGRESS_BAR_MSG_TIME 3000
      #define PROGRESS_MSG_EXPIRE   0
    #endif
  #endif
#endif

#if ENABLED(SDSUPPORT)
  /**
   * SD Card SPI Speed
   * May be required to resolve "volume init" errors.
   *
   * Enable and set to SPI_HALF_SPEED, SPI_QUARTER_SPEED, or SPI_EIGHTH_SPEED
   *  otherwise full speed will be applied.
   *
   * :['SPI_HALF_SPEED', 'SPI_QUARTER_SPEED', 'SPI_EIGHTH_SPEED']
   */

  #define SD_PROCEDURE_DEPTH 1

  #define SD_FINISHED_STEPPERRELEASE true
  #define SD_FINISHED_RELEASECOMMAND "M84"

  #define SDCARD_RATHERRECENTFIRST

  #define SD_MENU_CONFIRM_START
  #define BROWSE_MEDIA_ON_INSERT

  #define EVENT_GCODE_SD_ABORT "G28XY"

  #if ENABLED(PRINTER_EVENT_LEDS)
    #define PE_LEDS_COMPLETED_TIME  (30*60)
  #endif

  /**
   * Continue after Power-Loss (Creality3D)
   *
   * Store the current state to the SD Card at the start of each layer
   * during SD printing. If the recovery file is found at boot time, present
   * an option on the LCD screen to continue the print from the last-known
   * point in the file.
   */

  #if ENABLED(POWER_LOSS_RECOVERY)
    #define PLR_ENABLED_DEFAULT   false

    #define POWER_LOSS_MIN_Z_CHANGE 0.05

    #if ENABLED(POWER_LOSS_RECOVER_ZHOME)

    #endif
  #endif

  /**
   * Sort SD file listings in alphabetical order.
   *
   * With this option enabled, items on SD cards will be sorted
   * by name for easier navigation.
   *
   * By default...
   *
   *  - Use the slowest -but safest- method for sorting.
   *  - Folders are sorted to the top.
   *  - The sort key is statically allocated.
   *  - No added G-code (M34) support.
   *  - 40 item sorting limit. (Items after the first 40 are unsorted.)
   *
   * SD sorting uses static allocation (as set by SDSORT_LIMIT), allowing the
   * compiler to calculate the worst-case usage and throw an error if the SRAM
   * limit is exceeded.
   *
   *  - SDSORT_USES_RAM provides faster sorting via a static directory buffer.
   *  - SDSORT_USES_STACK does the same, but uses a local stack-based buffer.
   *  - SDSORT_CACHE_NAMES will retain the sorted file listing in RAM. (Expensive!)
   *  - SDSORT_DYNAMIC_RAM only uses RAM when the SD menu is visible. (Use with caution!)
   */

  #if ENABLED(SDCARD_SORT_ALPHA)
    #define SDSORT_LIMIT       40
    #define FOLDER_SORTING     -1
    #define SDSORT_GCODE       false
    #define SDSORT_USES_RAM    false
    #define SDSORT_USES_STACK  false
    #define SDSORT_CACHE_NAMES false
    #define SDSORT_DYNAMIC_RAM false
    #define SDSORT_CACHE_VFATS 2

  #endif

  #define SCROLL_LONG_FILENAMES
  /**
   * This option allows you to abort SD printing when any endstop is triggered.
   * This feature must be enabled with "M540 S1" or from the LCD menu.
   * To have any effect, endstops must be enabled during SD printing.
   */
  /**
   * This option makes it easier to print the same SD Card file again.
   * On print completion the LCD Menu will open with the file selected.
   * You can just click to start the print, or navigate elsewhere.
   */
  /**
   * Auto-report SdCard status with M27 S<seconds>
   */
  /**
   * Support for USB thumb drives using an Arduino USB Host Shield or
   * equivalent MAX3421E breakout board. The USB thumb drive will appear
   * to Marlin as an SD card.
   *
   * The MAX3421E can be assigned the same pins as the SD card reader, with
   * the following pin mapping:
   *
   *    SCLK, MOSI, MISO --> SCLK, MOSI, MISO
   *    INT              --> SD_DETECT_PIN [1]
   *    SS               --> SDSS
   *
   * [1] On AVR an interrupt-capable pin is best for UHS3 compatibility.
   */

  #if ENABLED(USB_FLASH_DRIVE_SUPPORT)
    /**
     * USB Host Shield Library
     *
     * - UHS2 uses no interrupts and has been production-tested
     *   on a LulzBot TAZ Pro with a 32-bit Archim board.
     *
     * - UHS3 is newer code with better USB compatibility. But it
     *   is less tested and is known to interfere with Servos.
     *   [1] This requires USB_INTR_PIN to be interrupt-capable.
     */

    /**
     * Native USB Host supported by some boards (USB OTG)
     */
    #if DISABLED(USE_OTG_USB_HOST)
      #define USB_CS_PIN    SDSS
      #define USB_INTR_PIN  SD_DETECT_PIN
    #endif
  #endif

  /**
   * When using a bootloader that supports SD-Firmware-Flashing,
   * add a menu item to activate SD-FW-Update on the next reboot.
   *
   * Requires ATMEGA2560 (Arduino Mega)
   *
   * Tested with this bootloader:
   *   https:
   */

  #if ENABLED(SD_FIRMWARE_UPDATE)
    #define SD_FIRMWARE_UPDATE_EEPROM_ADDR    0x1FF
    #define SD_FIRMWARE_UPDATE_ACTIVE_VALUE   0xF0
    #define SD_FIRMWARE_UPDATE_INACTIVE_VALUE 0xFF
  #endif
  /**
   * Set this option to one of the following (or the board's defaults apply):
   *
   *           LCD - Use the SD drive in the external LCD controller.
   *       ONBOARD - Use the SD drive on the control board.
   *  CUSTOM_CABLE - Use a custom cable to access the SD (as defined in a pins file).
   *
   * :[ 'LCD', 'ONBOARD', 'CUSTOM_CABLE' ]
   */
  #define SDCARD_CONNECTION ONBOARD
  #if ENABLED(MULTI_VOLUME)
    #define VOLUME_SD_ONBOARD
    #define VOLUME_USB_FLASH_DRIVE
    #define DEFAULT_VOLUME SV_SD_ONBOARD
    #define DEFAULT_SHARED_VOLUME SV_USB_FLASH_DRIVE
  #endif

#endif

/**
 * By default an onboard SD card reader may be shared as a USB mass-
 * storage device. This option hides the SD card from the host PC.
 */
/**
 * Additional options for Graphical Displays
 *
 * Use the optimizations here to improve printing performance,
 * which can be adversely affected by graphical display drawing,
 * especially when doing several short moves, and when printing
 * on DELTA and SCARA machines.
 *
 * Some of these options may result in the display lagging behind
 * controller events, as there is a trade-off between reliable
 * printing performance versus fast display updates.
 */
#if HAS_MARLINUI_U8GLIB

  #define XYZ_HOLLOW_FRAME
  #define MENU_HOLLOW_FRAME
  /**
   * ST7920-based LCDs can emulate a 16 x 4 character display using
   * the ST7920 character-generator for very fast screen updates.
   * Enable LIGHTWEIGHT_UI to use this special display mode.
   *
   * Since LIGHTWEIGHT_UI has limited space, the position and status
   * message occupy the same line. Set STATUS_EXPIRE_SECONDS to the
   * length of time to display the status message before clearing.
   *
   * Set STATUS_EXPIRE_SECONDS to zero to never clear the status.
   * This will prevent position updates from being displayed.
   */
  #if ENABLED(U8GLIB_ST7920)

    #if ENABLED(LIGHTWEIGHT_UI)
      #define STATUS_EXPIRE_SECONDS 20
    #endif
  #endif

  /**
   * Status (Info) Screen customizations
   * These options may affect code size and screen render time.
   * Custom status screens can forcibly override these settings.
   */
  #define STATUS_HOTEND_INVERTED
  #define STATUS_HOTEND_ANIM
  #define STATUS_BED_ANIM
  #define STATUS_CHAMBER_ANIM
  #define STATUS_HEAT_PERCENT
#endif
#if HAS_DGUS_LCD
  #define LCD_SERIAL_PORT 3
  #define LCD_BAUDRATE 115200

  #define DGUS_RX_BUFFER_SIZE 128
  #define DGUS_TX_BUFFER_SIZE 48
  #define DGUS_UPDATE_INTERVAL_MS  500

  #if ANY(DGUS_LCD_UI_FYSETC, DGUS_LCD_UI_MKS, DGUS_LCD_UI_HIPRECY)
    #define DGUS_PRINT_FILENAME
    #define DGUS_PREHEAT_UI

    #if EITHER(DGUS_LCD_UI_FYSETC, DGUS_LCD_UI_MKS)

    #else
      #define DGUS_UI_MOVE_DIS_OPTION
    #endif

    #define DGUS_FILAMENT_LOADUNLOAD
    #if ENABLED(DGUS_FILAMENT_LOADUNLOAD)
      #define DGUS_FILAMENT_PURGE_LENGTH 10
      #define DGUS_FILAMENT_LOAD_LENGTH_PER_TIME 0.5
    #endif

    #define DGUS_UI_WAITING
    #if ENABLED(DGUS_UI_WAITING)
      #define DGUS_UI_WAITING_STATUS 10
      #define DGUS_UI_WAITING_STATUS_PERIOD 8
    #endif
  #endif
#endif
#if ENABLED(ANYCUBIC_LCD_CHIRON)
  /**
   * Display Folders
   * By default the file browser lists all G-code files (including those in subfolders) in a flat list.
   * Enable this option to display a hierarchical file browser.
   *
   * NOTES:
   * - Without this option it helps to enable SDCARD_SORT_ALPHA so files are sorted before/after folders.
   * - When used with the "new" panel, folder names will also have '.gcode' appended to their names.
   *   This hack is currently required to force the panel to show folders.
   */
  #define AC_SD_FOLDER_VIEW
#endif
#if ANY(DOGLCD, TFT_COLOR_UI, TOUCH_UI_FTDI_EVE)
  #ifdef LCD_LANGUAGE_2

  #endif
#endif
#if ENABLED(TOUCH_UI_FTDI_EVE)

  #if ENABLED(OTHER_PIN_LAYOUT)

    #define CLCD_MOD_RESET  9
    #define CLCD_SPI_CS    10

    #if ENABLED(CLCD_USE_SOFT_SPI)
      #define CLCD_SOFT_SPI_MOSI 11
      #define CLCD_SOFT_SPI_MISO 12
      #define CLCD_SOFT_SPI_SCLK 13
    #endif
  #endif

  #if ENABLED(TOUCH_UI_USE_UTF8)
    #define TOUCH_UI_UTF8_WESTERN_CHARSET
    #if ENABLED(TOUCH_UI_UTF8_WESTERN_CHARSET)
    #endif

  #endif
  #define TOUCH_UI_FIT_TEXT
#endif
#if TFT_SCALED_DOGLCD
#endif
#if HAS_ADC_BUTTONS
  #define ADC_BUTTON_DEBOUNCE_DELAY 16
#endif

/**
 * The watchdog hardware timer will do a reset and disable all outputs
 * if the firmware gets too overloaded to read the temperature sensors.
 *
 * If you find that watchdog reboot causes your AVR board to hang forever,
 * enable WATCHDOG_RESET_MANUAL to use a custom timer instead of WDTO.
 * NOTE: This method is less reliable as it can only catch hangups while
 * interrupts are enabled.
 */
#define USE_WATCHDOG
#if ENABLED(USE_WATCHDOG)

#endif

/**
 * Babystepping enables movement of the axes by tiny increments without changing
 * the current position values. This feature is used primarily to adjust the Z
 * axis in the first layer of a print in real-time.
 *
 * Warning: Does not respect endstops!
 */
#define BABYSTEPPING
#if ENABLED(BABYSTEPPING)
  #define BABYSTEP_INVERT_Z false

  #define BABYSTEP_MULTIPLICATOR_Z  4
  #define BABYSTEP_MULTIPLICATOR_XY 1

  #define DOUBLECLICK_FOR_Z_BABYSTEPPING
  #if ENABLED(DOUBLECLICK_FOR_Z_BABYSTEPPING)
    #define DOUBLECLICK_MAX_INTERVAL 1250
    #if ENABLED(MOVE_Z_WHEN_IDLE)
      #define MOVE_Z_IDLE_MULTIPLICATOR 1
    #endif
  #endif

  #define BABYSTEP_ZPROBE_OFFSET
  #if ENABLED(BABYSTEP_ZPROBE_OFFSET)

    #define BABYSTEP_ZPROBE_GFX_OVERLAY
  #endif
#endif

/**
 * Linear Pressure Control v1.5
 *
 * Assumption: advance [steps] = k * (delta velocity [steps/s])
 * K=0 means advance disabled.
 *
 * NOTE: K values for LIN_ADVANCE 1.5 differ from earlier versions!
 *
 * Set K around 0.22 for 3mm PLA Direct Drive with ~6.5cm between the drive gear and heatbreak.
 * Larger K values will be needed for flexible filament and greater distances.
 * If this algorithm produces a higher speed offset than the extruder can handle (compared to E jerk)
 * print acceleration will be reduced during the affected moves to keep within the limit.
 *
 * See https:
 */
#define LIN_ADVANCE
#if ENABLED(LIN_ADVANCE)

  #define LIN_ADVANCE_K 0.0
#endif

/**
 * Points to probe for all 3-point Leveling procedures.
 * Override if the automatically selected points are inadequate.
 */
#if EITHER(AUTO_BED_LEVELING_3POINT, AUTO_BED_LEVELING_UBL)
#endif

/**
 * Probing Margins
 *
 * Override PROBING_MARGIN for each side of the build plate
 * Useful to get probe points to exact positions on targets or
 * to allow leveling to avoid plate clamps on only specific
 * sides of the bed. With NOZZLE_AS_PROBE negative values are
 * allowed, to permit probing outside the bed.
 *
 * If you are replacing the prior *_PROBE_BED_POSITION options,
 * LEFT and FRONT values in most cases will map directly over
 * RIGHT and REAR would be the inverse such as
 * (X/Y_BED_SIZE - RIGHT/BACK_PROBE_BED_POSITION)
 *
 * This will allow all positions to match at compilation, however
 * should the probe position be modified with M851XY then the
 * probe points will follow. This prevents any change from causing
 * the probe to be unable to reach any points.
 */
#if PROBE_SELECTED && !IS_KINEMATIC
#endif

#if EITHER(MESH_BED_LEVELING, AUTO_BED_LEVELING_UBL)

#endif

#if BOTH(AUTO_BED_LEVELING_UBL, EEPROM_SETTINGS)

#endif

/**
 * Repeatedly attempt G29 leveling until it succeeds.
 * Stop after G29_MAX_RETRIES attempts.
 */

#if ENABLED(G29_RETRY_AND_RECOVER)
  #define G29_MAX_RETRIES 3
  #define G29_HALT_ON_FAILURE
  /**
   * Specify the GCODE commands that will be executed when leveling succeeds,
   * between attempts, and after the maximum number of retries have been tried.
   */
  #define G29_SUCCESS_COMMANDS "M117 Bed leveling done."
  #define G29_RECOVER_COMMANDS "M117 Probe failed. Rewiping.\nG28\nG12 P0 S12 T0"
  #define G29_FAILURE_COMMANDS "M117 Bed leveling failed.\nG0 Z10\nM300 P25 S880\nM300 P50 S0\nM300 P25 S880\nM300 P50 S0\nM300 P25 S880\nM300 P50 S0\nG4 S1"

#endif

/**
 * Thermal Probe Compensation
 * Probe measurements are adjusted to compensate for temperature distortion.
 * Use G76 to calibrate this feature. Use M871 to set values manually.
 * For a more detailed explanation of the process see G76_M871.cpp.
 */
#if HAS_BED_PROBE && TEMP_SENSOR_PROBE && TEMP_SENSOR_BED

  #define PROBE_TEMP_COMPENSATION

  #if ENABLED(PROBE_TEMP_COMPENSATION)

    #define PTC_PARK_POS   { 0, 0, 100 }
    #define PTC_PROBE_POS  { 90, 100 }

  #endif
#endif

#define ARC_SUPPORT
#if ENABLED(ARC_SUPPORT)
  #define MM_PER_ARC_SEGMENT      1

  #define MIN_ARC_SEGMENTS       24

  #define N_ARC_CORRECTION       25

#endif
/**
 * Direct Stepping
 *
 * Comparable to the method used by Klipper, G6 direct stepping significantly
 * reduces motion calculations, increases top printing speeds, and results in
 * less step aliasing by calculating all motions in advance.
 * Preparing your G-code: https:
 */
/**
 * G38 Probe Target
 *
 * This option adds G38.2 and G38.3 (probe towards target)
 * and optionally G38.4 and G38.5 (probe away from target).
 * Set MULTIPLE_PROBING for G38 to probe more than once.
 */

#if ENABLED(G38_PROBE_TARGET)

  #define G38_MINIMUM_MOVE 0.0275
#endif
#define MIN_STEPS_PER_SEGMENT 6

/**
 * Minimum delay before and after setting the stepper DIR (in ns)
 *     0 : No delay (Expect at least 10µS since one Stepper ISR must transpire)
 *    20 : Minimum for TMC2xxx drivers
 *   200 : Minimum for A4988 drivers
 *   400 : Minimum for A5984 drivers
 *   500 : Minimum for LV8729 drivers (guess, no info in datasheet)
 *   650 : Minimum for DRV8825 drivers
 *  1500 : Minimum for TB6600 drivers (guess, no info in datasheet)
 * 15000 : Minimum for TB6560 drivers (guess, no info in datasheet)
 *
 * Override the default value based on the driver type set in Configuration.h.
 */

/**
 * Minimum stepper driver pulse width (in µs)
 *   0 : Smallest possible width the MCU can produce, compatible with TMC2xxx drivers
 *   0 : Minimum 500ns for LV8729, adjusted in stepper.h
 *   1 : Minimum for A4988 and A5984 stepper drivers
 *   2 : Minimum for DRV8825 stepper drivers
 *   3 : Minimum for TB6600 stepper drivers
 *  30 : Minimum for TB6560 stepper drivers
 *
 * Override the default value based on the driver type set in Configuration.h.
 */
/**
 * Maximum stepping rate (in Hz) the stepper driver allows
 *  If undefined, defaults to 1MHz / (2 * MINIMUM_STEPPER_PULSE)
 *  5000000 : Maximum for TMC2xxx stepper drivers
 *  1000000 : Maximum for LV8729 stepper driver
 *  500000  : Maximum for A4988 stepper driver
 *  250000  : Maximum for DRV8825 stepper driver
 *  150000  : Maximum for TB6600 stepper driver
 *   15000  : Maximum for TB6560 stepper driver
 *
 * Override the default value based on the driver type set in Configuration.h.
 */

#if BOTH(SDSUPPORT, DIRECT_STEPPING)
  #define BLOCK_BUFFER_SIZE  8
#elif ENABLED(SDSUPPORT)
  #define BLOCK_BUFFER_SIZE 16
#else
  #define BLOCK_BUFFER_SIZE 16
#endif
#define MAX_CMD_SIZE 96
#define BUFSIZE 4
#define TX_BUFFER_SIZE 0

#if RX_BUFFER_SIZE >= 1024

#endif

#if ENABLED(SDSUPPORT)

#endif

/**
 * Emergency Command Parser
 *
 * Add a low-level parser to intercept certain commands as they
 * enter the serial receive buffer, so they cannot be blocked.
 * Currently handles M108, M112, M410, M876
 * NOTE: Not yet implemented for all platforms.
 */
#define EMERGENCY_PARSER

/**
 * Realtime Reporting (requires EMERGENCY_PARSER)
 *
 * - Report position and state of the machine (like Grbl).
 * - Auto-report position during long moves.
 * - Useful for CNC/LASER.
 *
 * Adds support for commands:
 *  S000 : Report State and Position while moving.
 *  P000 : Instant Pause / Hold while moving.
 *  R000 : Resume from Pause / Hold.
 *
 * - During Hold all Emergency Parser commands are available, as usual.
 * - Enable NANODLP_Z_SYNC and NANODLP_ALL_AXIS for move command end-state reports.
 */

#if ENABLED(REALTIME_REPORTING_COMMANDS)

#endif
#define SERIAL_OVERRUN_PROTECTION
/**
 * Extra Fan Speed
 * Adds a secondary fan speed for each print-cooling fan.
 *   'M106 P<fan> T3-255' : Set a secondary speed for <fan>
 *   'M106 P<fan> T2'     : Use the set secondary speed
 *   'M106 P<fan> T1'     : Restore the previous fan speed
 */
/**
 * Firmware-based and LCD-controlled retract
 *
 * Add G10 / G11 commands for automatic firmware-based retract / recover.
 * Use M207 and M208 to define parameters for retract / recover.
 *
 * Use M209 to enable or disable auto-retract.
 * With auto-retract enabled, all G1 E moves within the set range
 * will be converted to firmware-based retract/recover moves.
 *
 * Be sure to turn off auto-retract during filament change.
 *
 * Note that M207 / M208 / M209 settings are saved to EEPROM.
 */

#if ENABLED(FWRETRACT)
  #define FWRETRACT_AUTORETRACT
  #if ENABLED(FWRETRACT_AUTORETRACT)
    #define MIN_AUTORETRACT             0.1
    #define MAX_AUTORETRACT            10.0
  #endif
  #define RETRACT_LENGTH                3
  #define RETRACT_LENGTH_SWAP          13
  #define RETRACT_FEEDRATE             45
  #define RETRACT_ZRAISE                0
  #define RETRACT_RECOVER_LENGTH        0
  #define RETRACT_RECOVER_LENGTH_SWAP   0
  #define RETRACT_RECOVER_FEEDRATE      8
  #define RETRACT_RECOVER_FEEDRATE_SWAP 8
  #if ENABLED(MIXING_EXTRUDER)

  #endif
#endif

/**
 * Universal tool change settings.
 * Applies to all types of extruders except where explicitly noted.
 */
#if HAS_MULTI_EXTRUDER

  #define TOOLCHANGE_ZRAISE                 2
  #if ENABLED(TOOLCHANGE_NO_RETURN)

  #endif

  /**
   * Extra G-code to run while executing tool-change commands. Can be used to use an additional
   * stepper motor (I axis, see option LINEAR_AXES in Configuration.h) to drive the tool-changer.
   */

  /**
   * Tool Sensors detect when tools have been picked up or dropped.
   * Requires the pins TOOL_SENSOR1_PIN, TOOL_SENSOR2_PIN, etc.
   */
  /**
   * Retract and prime filament on tool-change to reduce
   * ooze and stringing and to get cleaner transitions.
   */

  #if ENABLED(TOOLCHANGE_FILAMENT_SWAP)

    #define TOOLCHANGE_FS_LENGTH              12
    #define TOOLCHANGE_FS_EXTRA_RESUME_LENGTH  0
    #define TOOLCHANGE_FS_RETRACT_SPEED   (50*60)
    #define TOOLCHANGE_FS_UNRETRACT_SPEED (25*60)
    #define TOOLCHANGE_FS_EXTRA_PRIME          0
    #define TOOLCHANGE_FS_PRIME_SPEED    (4.6*60)
    #define TOOLCHANGE_FS_WIPE_RETRACT         0
    #define TOOLCHANGE_FS_FAN                 -1
    #define TOOLCHANGE_FS_FAN_SPEED          255
    #define TOOLCHANGE_FS_FAN_TIME            10

    /**
     * Tool Change Migration
     * This feature provides G-code and LCD options to switch tools mid-print.
     * All applicable tool properties are migrated so the print can continue.
     * Tools must be closely matching and other restrictions may apply.
     * Useful to:
     *   - Change filament color without interruption
     *   - Switch spools automatically on filament runout
     *   - Switch to a different nozzle on an extruder jam
     */
    #define TOOLCHANGE_MIGRATION_FEATURE

  #endif

  /**
   * Position to park head during tool change.
   * Doesn't apply to SWITCHING_TOOLHEAD, DUAL_X_CARRIAGE, or PARKING_EXTRUDER
   */

  #if ENABLED(TOOLCHANGE_PARK)
    #define TOOLCHANGE_PARK_XY    { X_MIN_POS + 10, Y_MIN_POS + 10 }
    #define TOOLCHANGE_PARK_XY_FEEDRATE 6000
  #endif
#endif

/**
 * Advanced Pause for Filament Change
 *  - Adds the G-code M600 Filament Change to initiate a filament change.
 *  - This feature is required for the default FILAMENT_RUNOUT_SCRIPT.
 *
 * Requirements:
 *  - For Filament Change parking enable and configure NOZZLE_PARK_FEATURE.
 *  - For user interaction enable an LCD display, HOST_PROMPT_SUPPORT, or EMERGENCY_PARSER.
 *
 * Enable PARK_HEAD_ON_PAUSE to add the G-code M125 Pause and Park.
 */

#if ENABLED(ADVANCED_PAUSE_FEATURE)
  #define PAUSE_PARK_RETRACT_FEEDRATE         60
  #define PAUSE_PARK_RETRACT_LENGTH            2

  #define FILAMENT_CHANGE_UNLOAD_FEEDRATE     10
  #define FILAMENT_CHANGE_UNLOAD_ACCEL        25
  #define FILAMENT_CHANGE_UNLOAD_LENGTH      100

  #define FILAMENT_CHANGE_SLOW_LOAD_FEEDRATE   6
  #define FILAMENT_CHANGE_SLOW_LOAD_LENGTH     0

  #define FILAMENT_CHANGE_FAST_LOAD_FEEDRATE   6
  #define FILAMENT_CHANGE_FAST_LOAD_ACCEL     25
  #define FILAMENT_CHANGE_FAST_LOAD_LENGTH     0

  #define ADVANCED_PAUSE_PURGE_FEEDRATE        3
  #define ADVANCED_PAUSE_PURGE_LENGTH         50

  #define ADVANCED_PAUSE_RESUME_PRIME          0

  #define FILAMENT_UNLOAD_PURGE_RETRACT       13
  #define FILAMENT_UNLOAD_PURGE_DELAY       5000
  #define FILAMENT_UNLOAD_PURGE_LENGTH         8
  #define FILAMENT_UNLOAD_PURGE_FEEDRATE      25

  #define PAUSE_PARK_NOZZLE_TIMEOUT           45
  #define FILAMENT_CHANGE_ALERT_BEEPS         10
  #define PAUSE_PARK_NO_STEPPER_TIMEOUT
#endif

/**
 * TMC26X Stepper Driver options
 *
 * The TMC26XStepper library is required for this stepper driver.
 * https:
 */
#if HAS_DRIVER(TMC26X)

  #if AXIS_DRIVER_TYPE_X(TMC26X)
    #define X_MAX_CURRENT     1000
    #define X_SENSE_RESISTOR    91
    #define X_MICROSTEPS        16
  #endif

  #if AXIS_DRIVER_TYPE_X2(TMC26X)
    #define X2_MAX_CURRENT    1000
    #define X2_SENSE_RESISTOR   91
    #define X2_MICROSTEPS       X_MICROSTEPS
  #endif

  #if AXIS_DRIVER_TYPE_Y(TMC26X)
    #define Y_MAX_CURRENT     1000
    #define Y_SENSE_RESISTOR    91
    #define Y_MICROSTEPS        16
  #endif

  #if AXIS_DRIVER_TYPE_Y2(TMC26X)
    #define Y2_MAX_CURRENT    1000
    #define Y2_SENSE_RESISTOR   91
    #define Y2_MICROSTEPS       Y_MICROSTEPS
  #endif

  #if AXIS_DRIVER_TYPE_Z(TMC26X)
    #define Z_MAX_CURRENT     1000
    #define Z_SENSE_RESISTOR    91
    #define Z_MICROSTEPS        16
  #endif

  #if AXIS_DRIVER_TYPE_Z2(TMC26X)
    #define Z2_MAX_CURRENT    1000
    #define Z2_SENSE_RESISTOR   91
    #define Z2_MICROSTEPS       Z_MICROSTEPS
  #endif

  #if AXIS_DRIVER_TYPE_Z3(TMC26X)
    #define Z3_MAX_CURRENT    1000
    #define Z3_SENSE_RESISTOR   91
    #define Z3_MICROSTEPS       Z_MICROSTEPS
  #endif

  #if AXIS_DRIVER_TYPE_Z4(TMC26X)
    #define Z4_MAX_CURRENT    1000
    #define Z4_SENSE_RESISTOR   91
    #define Z4_MICROSTEPS       Z_MICROSTEPS
  #endif

  #if AXIS_DRIVER_TYPE_I(TMC26X)
    #define I_MAX_CURRENT    1000
    #define I_SENSE_RESISTOR   91
    #define I_MICROSTEPS       16
  #endif

  #if AXIS_DRIVER_TYPE_J(TMC26X)
    #define J_MAX_CURRENT    1000
    #define J_SENSE_RESISTOR   91
    #define J_MICROSTEPS       16
  #endif

  #if AXIS_DRIVER_TYPE_K(TMC26X)
    #define K_MAX_CURRENT    1000
    #define K_SENSE_RESISTOR   91
    #define K_MICROSTEPS       16
  #endif

  #if AXIS_DRIVER_TYPE_E0(TMC26X)
    #define E0_MAX_CURRENT    1000
    #define E0_SENSE_RESISTOR   91
    #define E0_MICROSTEPS       16
  #endif

  #if AXIS_DRIVER_TYPE_E1(TMC26X)
    #define E1_MAX_CURRENT    1000
    #define E1_SENSE_RESISTOR   91
    #define E1_MICROSTEPS       E0_MICROSTEPS
  #endif

  #if AXIS_DRIVER_TYPE_E2(TMC26X)
    #define E2_MAX_CURRENT    1000
    #define E2_SENSE_RESISTOR   91
    #define E2_MICROSTEPS       E0_MICROSTEPS
  #endif

  #if AXIS_DRIVER_TYPE_E3(TMC26X)
    #define E3_MAX_CURRENT    1000
    #define E3_SENSE_RESISTOR   91
    #define E3_MICROSTEPS       E0_MICROSTEPS
  #endif

  #if AXIS_DRIVER_TYPE_E4(TMC26X)
    #define E4_MAX_CURRENT    1000
    #define E4_SENSE_RESISTOR   91
    #define E4_MICROSTEPS       E0_MICROSTEPS
  #endif

  #if AXIS_DRIVER_TYPE_E5(TMC26X)
    #define E5_MAX_CURRENT    1000
    #define E5_SENSE_RESISTOR   91
    #define E5_MICROSTEPS       E0_MICROSTEPS
  #endif

  #if AXIS_DRIVER_TYPE_E6(TMC26X)
    #define E6_MAX_CURRENT    1000
    #define E6_SENSE_RESISTOR   91
    #define E6_MICROSTEPS       E0_MICROSTEPS
  #endif

  #if AXIS_DRIVER_TYPE_E7(TMC26X)
    #define E7_MAX_CURRENT    1000
    #define E7_SENSE_RESISTOR   91
    #define E7_MICROSTEPS       E0_MICROSTEPS
  #endif

#endif

/**
 * To use TMC2130, TMC2160, TMC2660, TMC5130, TMC5160 stepper drivers in SPI mode
 * connect your SPI pins to the hardware SPI interface on your board and define
 * the required CS pins in your `pins_MYBOARD.h` file. (e.g., RAMPS 1.4 uses AUX3
 * pins `X_CS_PIN 53`, `Y_CS_PIN 49`, etc.).
 * You may also use software SPI if you wish to use general purpose IO pins.
 *
 * To use TMC2208 stepper UART-configurable stepper drivers connect #_SERIAL_TX_PIN
 * to the driver side PDN_UART pin with a 1K resistor.
 * To use the reading capabilities, also connect #_SERIAL_RX_PIN to PDN_UART without
 * a resistor.
 * The drivers can also be used with hardware serial.
 *
 * TMCStepper library is required to use TMC stepper drivers.
 * https:
 */
#if HAS_TRINAMIC_CONFIG

  #define HOLD_MULTIPLIER    0.5

  /**
   * Interpolate microsteps to 256
   * Override for each driver with <driver>_INTERPOLATE settings below
   */
  #define INTERPOLATE      true

  #if AXIS_IS_TMC(X)
    #define X_CURRENT       580
    #define X_CURRENT_HOME  X_CURRENT
    #define X_MICROSTEPS     16
    #define X_RSENSE          0.11
    #define X_CHAIN_POS      -1

  #endif

  #if AXIS_IS_TMC(X2)
    #define X2_CURRENT      800
    #define X2_CURRENT_HOME X2_CURRENT
    #define X2_MICROSTEPS    X_MICROSTEPS
    #define X2_RSENSE         0.11
    #define X2_CHAIN_POS     -1

  #endif

  #if AXIS_IS_TMC(Y)
    #define Y_CURRENT       580
    #define Y_CURRENT_HOME  Y_CURRENT
    #define Y_MICROSTEPS     16
    #define Y_RSENSE          0.11
    #define Y_CHAIN_POS      -1

  #endif

  #if AXIS_IS_TMC(Y2)
    #define Y2_CURRENT      800
    #define Y2_CURRENT_HOME Y2_CURRENT
    #define Y2_MICROSTEPS    Y_MICROSTEPS
    #define Y2_RSENSE         0.11
    #define Y2_CHAIN_POS     -1

  #endif

  #if AXIS_IS_TMC(Z)
    #define Z_CURRENT       580
    #define Z_CURRENT_HOME  Z_CURRENT
    #define Z_MICROSTEPS     16
    #define Z_RSENSE          0.11
    #define Z_CHAIN_POS      -1

  #endif

  #if AXIS_IS_TMC(Z2)
    #define Z2_CURRENT      800
    #define Z2_CURRENT_HOME Z2_CURRENT
    #define Z2_MICROSTEPS    Z_MICROSTEPS
    #define Z2_RSENSE         0.11
    #define Z2_CHAIN_POS     -1

  #endif

  #if AXIS_IS_TMC(Z3)
    #define Z3_CURRENT      800
    #define Z3_CURRENT_HOME Z3_CURRENT
    #define Z3_MICROSTEPS    Z_MICROSTEPS
    #define Z3_RSENSE         0.11
    #define Z3_CHAIN_POS     -1

  #endif

  #if AXIS_IS_TMC(Z4)
    #define Z4_CURRENT      800
    #define Z4_CURRENT_HOME Z4_CURRENT
    #define Z4_MICROSTEPS    Z_MICROSTEPS
    #define Z4_RSENSE         0.11
    #define Z4_CHAIN_POS     -1

  #endif

  #if AXIS_IS_TMC(I)
    #define I_CURRENT      800
    #define I_CURRENT_HOME I_CURRENT
    #define I_MICROSTEPS    16
    #define I_RSENSE         0.11
    #define I_CHAIN_POS     -1

  #endif

  #if AXIS_IS_TMC(J)
    #define J_CURRENT      800
    #define J_CURRENT_HOME J_CURRENT
    #define J_MICROSTEPS    16
    #define J_RSENSE         0.11
    #define J_CHAIN_POS     -1

  #endif

  #if AXIS_IS_TMC(K)
    #define K_CURRENT      800
    #define K_CURRENT_HOME K_CURRENT
    #define K_MICROSTEPS    16
    #define K_RSENSE         0.11
    #define K_CHAIN_POS     -1

  #endif

  #if AXIS_IS_TMC(E0)
    #define E0_CURRENT      650
    #define E0_MICROSTEPS    16
    #define E0_RSENSE         0.11
    #define E0_CHAIN_POS     -1

  #endif

  #if AXIS_IS_TMC(E1)
    #define E1_CURRENT      800
    #define E1_MICROSTEPS   E0_MICROSTEPS
    #define E1_RSENSE         0.11
    #define E1_CHAIN_POS     -1

  #endif

  #if AXIS_IS_TMC(E2)
    #define E2_CURRENT      800
    #define E2_MICROSTEPS   E0_MICROSTEPS
    #define E2_RSENSE         0.11
    #define E2_CHAIN_POS     -1

  #endif

  #if AXIS_IS_TMC(E3)
    #define E3_CURRENT      800
    #define E3_MICROSTEPS   E0_MICROSTEPS
    #define E3_RSENSE         0.11
    #define E3_CHAIN_POS     -1

  #endif

  #if AXIS_IS_TMC(E4)
    #define E4_CURRENT      800
    #define E4_MICROSTEPS   E0_MICROSTEPS
    #define E4_RSENSE         0.11
    #define E4_CHAIN_POS     -1

  #endif

  #if AXIS_IS_TMC(E5)
    #define E5_CURRENT      800
    #define E5_MICROSTEPS   E0_MICROSTEPS
    #define E5_RSENSE         0.11
    #define E5_CHAIN_POS     -1

  #endif

  #if AXIS_IS_TMC(E6)
    #define E6_CURRENT      800
    #define E6_MICROSTEPS   E0_MICROSTEPS
    #define E6_RSENSE         0.11
    #define E6_CHAIN_POS     -1

  #endif

  #if AXIS_IS_TMC(E7)
    #define E7_CURRENT      800
    #define E7_MICROSTEPS   E0_MICROSTEPS
    #define E7_RSENSE         0.11
    #define E7_CHAIN_POS     -1

  #endif

  /**
   * Override default SPI pins for TMC2130, TMC2160, TMC2660, TMC5130 and TMC5160 drivers here.
   * The default pins can be found in your board's pins file.
   */
  /**
   * Software option for SPI driven drivers (TMC2130, TMC2160, TMC2660, TMC5130 and TMC5160).
   * The default SW SPI pins are defined the respective pins files,
   * but you can override or define them here.
   */

  /**
   * Four TMC2209 drivers can use the same HW/SW serial port with hardware configured addresses.
   * Set the address using jumpers on pins MS1 and MS2.
   * Address | MS1  | MS2
   *       0 | LOW  | LOW
   *       1 | HIGH | LOW
   *       2 | LOW  | HIGH
   *       3 | HIGH | HIGH
   *
   * Set *_SERIAL_TX_PIN and *_SERIAL_RX_PIN to match for all drivers
   * on the same serial port, either here or in your board's pins file.
   */
  /**
   * Software enable
   *
   * Use for drivers that do not use a dedicated enable pin, but rather handle the same
   * function through a communication line such as SPI or UART.
   */
  /**
   * TMC2130, TMC2160, TMC2208, TMC2209, TMC5130 and TMC5160 only
   * Use Trinamic's ultra quiet stepping mode.
   * When disabled, Marlin will use spreadCycle stepping mode.
   */
  #define STEALTHCHOP_XY
  #define STEALTHCHOP_Z
  #define STEALTHCHOP_I
  #define STEALTHCHOP_J
  #define STEALTHCHOP_K
  #define STEALTHCHOP_E

  /**
   * Optimize spreadCycle chopper parameters by using predefined parameter sets
   * or with the help of an example included in the library.
   * Provided parameter sets are
   * CHOPPER_DEFAULT_12V
   * CHOPPER_DEFAULT_19V
   * CHOPPER_DEFAULT_24V
   * CHOPPER_DEFAULT_36V
   * CHOPPER_09STEP_24V
   * CHOPPER_PRUSAMK3_24V
   * CHOPPER_MARLIN_119
   *
   * Define your own with:
   * { <off_time[1..15]>, <hysteresis_end[-3..12]>, hysteresis_start[1..8] }
   */
  #define CHOPPER_TIMING CHOPPER_DEFAULT_24V

  /**
   * Monitor Trinamic drivers
   * for error conditions like overtemperature and short to ground.
   * To manage over-temp Marlin can decrease the driver current until the error condition clears.
   * Other detected conditions can be used to stop the current print.
   * Relevant G-codes:
   * M906 - Set or get motor current in milliamps using axis codes X, Y, Z, E. Report values if no axis codes given.
   * M911 - Report stepper driver overtemperature pre-warn condition.
   * M912 - Clear stepper driver overtemperature pre-warn condition flag.
   * M122 - Report driver parameters (Requires TMC_DEBUG)
   */
  #if ENABLED(MONITOR_DRIVER_STATUS)
    #define CURRENT_STEP_DOWN     50
    #define REPORT_CURRENT_CHANGE
    #define STOP_ON_ERROR
  #endif

  /**
   * TMC2130, TMC2160, TMC2208, TMC2209, TMC5130 and TMC5160 only
   * The driver will switch to spreadCycle when stepper speed is over HYBRID_THRESHOLD.
   * This mode allows for faster movements at the expense of higher noise levels.
   * STEALTHCHOP_(XY|Z|E) must be enabled to use HYBRID_THRESHOLD.
   * M913 X/Y/Z/E to live tune the setting
   */
  #define X_HYBRID_THRESHOLD     100
  #define X2_HYBRID_THRESHOLD    100
  #define Y_HYBRID_THRESHOLD     100
  #define Y2_HYBRID_THRESHOLD    100
  #define Z_HYBRID_THRESHOLD       3
  #define Z2_HYBRID_THRESHOLD      3
  #define Z3_HYBRID_THRESHOLD      3
  #define Z4_HYBRID_THRESHOLD      3
  #define I_HYBRID_THRESHOLD       3
  #define J_HYBRID_THRESHOLD       3
  #define K_HYBRID_THRESHOLD       3
  #define E0_HYBRID_THRESHOLD     30
  #define E1_HYBRID_THRESHOLD     30
  #define E2_HYBRID_THRESHOLD     30
  #define E3_HYBRID_THRESHOLD     30
  #define E4_HYBRID_THRESHOLD     30
  #define E5_HYBRID_THRESHOLD     30
  #define E6_HYBRID_THRESHOLD     30
  #define E7_HYBRID_THRESHOLD     30

  /**
   * Use StallGuard to home / probe X, Y, Z.
   *
   * TMC2130, TMC2160, TMC2209, TMC2660, TMC5130, and TMC5160 only
   * Connect the stepper driver's DIAG1 pin to the X/Y endstop pin.
   * X, Y, and Z homing will always be done in spreadCycle mode.
   *
   * X/Y/Z_STALL_SENSITIVITY is the default stall threshold.
   * Use M914 X Y Z to set the stall threshold at runtime:
   *
   *  Sensitivity   TMC2209   Others
   *    HIGHEST       255      -64    (Too sensitive => False positive)
   *    LOWEST         0        63    (Too insensitive => No trigger)
   *
   * It is recommended to set HOMING_BUMP_MM to { 0, 0, 0 }.
   *
   * SPI_ENDSTOPS  *** Beta feature! *** TMC2130/TMC5160 Only ***
   * Poll the driver through SPI to determine load when homing.
   * Removes the need for a wire from DIAG1 to an endstop pin.
   *
   * IMPROVE_HOMING_RELIABILITY tunes acceleration and jerk when
   * homing and adds a guard period for endstop triggering.
   *
   * Comment *_STALL_SENSITIVITY to disable sensorless homing for that axis.
   */
  #if EITHER(SENSORLESS_HOMING, SENSORLESS_PROBING)

    #define X_STALL_SENSITIVITY  8
    #define X2_STALL_SENSITIVITY X_STALL_SENSITIVITY
    #define Y_STALL_SENSITIVITY  8
    #define Y2_STALL_SENSITIVITY Y_STALL_SENSITIVITY

  #endif

  /**
   * TMC Homing stepper phase.
   *
   * Improve homing repeatability by homing to stepper coil's nearest absolute
   * phase position. Trinamic drivers use a stepper phase table with 1024 values
   * spanning 4 full steps with 256 positions each (ergo, 1024 positions).
   * Full step positions (128, 384, 640, 896) have the highest holding torque.
   *
   * Values from 0..1023, -1 to disable homing phase for that axis.
   */
  /**
   * Beta feature!
   * Create a 50/50 square wave step pulse optimal for stepper drivers.
   */
  /**
   * Enable M122 debugging command for TMC stepper drivers.
   * M122 S0/1 will enable continuous reporting.
   */
  /**
   * You can set your own advanced settings by filling in predefined functions.
   * A list of available functions can be found on the library github page
   * https:
   *
   * Example:
   * #define TMC_ADV() { \
   *   stepperX.diag0_otpw(1); \
   *   stepperY.intpol(0); \
   * }
   */
  #define TMC_ADV() {  }

#endif

/**
 * L64XX Stepper Driver options
 *
 * Arduino-L6470 library (0.8.0 or higher) is required.
 * https:
 *
 * Requires the following to be defined in your pins_YOUR_BOARD file
 *     L6470_CHAIN_SCK_PIN
 *     L6470_CHAIN_MISO_PIN
 *     L6470_CHAIN_MOSI_PIN
 *     L6470_CHAIN_SS_PIN
 *     ENABLE_RESET_L64XX_CHIPS(Q)  where Q is 1 to enable and 0 to reset
 */

#if HAS_L64XX

  #if AXIS_IS_L64XX(X)
    #define X_MICROSTEPS       128
    #define X_OVERCURRENT     2000
    #define X_STALLCURRENT    1500

    #define X_MAX_VOLTAGE      127
    #define X_CHAIN_POS         -1
    #define X_SLEW_RATE          1
  #endif

  #if AXIS_IS_L64XX(X2)
    #define X2_MICROSTEPS     X_MICROSTEPS
    #define X2_OVERCURRENT            2000
    #define X2_STALLCURRENT           1500
    #define X2_MAX_VOLTAGE             127
    #define X2_CHAIN_POS                -1
    #define X2_SLEW_RATE                 1
  #endif

  #if AXIS_IS_L64XX(Y)
    #define Y_MICROSTEPS               128
    #define Y_OVERCURRENT             2000
    #define Y_STALLCURRENT            1500
    #define Y_MAX_VOLTAGE              127
    #define Y_CHAIN_POS                 -1
    #define Y_SLEW_RATE                  1
  #endif

  #if AXIS_IS_L64XX(Y2)
    #define Y2_MICROSTEPS     Y_MICROSTEPS
    #define Y2_OVERCURRENT            2000
    #define Y2_STALLCURRENT           1500
    #define Y2_MAX_VOLTAGE             127
    #define Y2_CHAIN_POS                -1
    #define Y2_SLEW_RATE                 1
  #endif

  #if AXIS_IS_L64XX(Z)
    #define Z_MICROSTEPS               128
    #define Z_OVERCURRENT             2000
    #define Z_STALLCURRENT            1500
    #define Z_MAX_VOLTAGE              127
    #define Z_CHAIN_POS                 -1
    #define Z_SLEW_RATE                  1
  #endif

  #if AXIS_IS_L64XX(Z2)
    #define Z2_MICROSTEPS     Z_MICROSTEPS
    #define Z2_OVERCURRENT            2000
    #define Z2_STALLCURRENT           1500
    #define Z2_MAX_VOLTAGE             127
    #define Z2_CHAIN_POS                -1
    #define Z2_SLEW_RATE                 1
  #endif

  #if AXIS_IS_L64XX(Z3)
    #define Z3_MICROSTEPS     Z_MICROSTEPS
    #define Z3_OVERCURRENT            2000
    #define Z3_STALLCURRENT           1500
    #define Z3_MAX_VOLTAGE             127
    #define Z3_CHAIN_POS                -1
    #define Z3_SLEW_RATE                 1
  #endif

  #if AXIS_IS_L64XX(Z4)
    #define Z4_MICROSTEPS     Z_MICROSTEPS
    #define Z4_OVERCURRENT            2000
    #define Z4_STALLCURRENT           1500
    #define Z4_MAX_VOLTAGE             127
    #define Z4_CHAIN_POS                -1
    #define Z4_SLEW_RATE                 1
  #endif

  #if AXIS_DRIVER_TYPE_I(L6470)
    #define I_MICROSTEPS      128
    #define I_OVERCURRENT    2000
    #define I_STALLCURRENT   1500
    #define I_MAX_VOLTAGE     127
    #define I_CHAIN_POS        -1
    #define I_SLEW_RATE         1
  #endif

  #if AXIS_DRIVER_TYPE_J(L6470)
    #define J_MICROSTEPS      128
    #define J_OVERCURRENT    2000
    #define J_STALLCURRENT   1500
    #define J_MAX_VOLTAGE     127
    #define J_CHAIN_POS        -1
    #define J_SLEW_RATE         1
  #endif

  #if AXIS_DRIVER_TYPE_K(L6470)
    #define K_MICROSTEPS      128
    #define K_OVERCURRENT    2000
    #define K_STALLCURRENT   1500
    #define K_MAX_VOLTAGE     127
    #define K_CHAIN_POS        -1
    #define K_SLEW_RATE         1
  #endif

  #if AXIS_IS_L64XX(E0)
    #define E0_MICROSTEPS              128
    #define E0_OVERCURRENT            2000
    #define E0_STALLCURRENT           1500
    #define E0_MAX_VOLTAGE             127
    #define E0_CHAIN_POS                -1
    #define E0_SLEW_RATE                 1
  #endif

  #if AXIS_IS_L64XX(E1)
    #define E1_MICROSTEPS    E0_MICROSTEPS
    #define E1_OVERCURRENT            2000
    #define E1_STALLCURRENT           1500
    #define E1_MAX_VOLTAGE             127
    #define E1_CHAIN_POS                -1
    #define E1_SLEW_RATE                 1
  #endif

  #if AXIS_IS_L64XX(E2)
    #define E2_MICROSTEPS    E0_MICROSTEPS
    #define E2_OVERCURRENT            2000
    #define E2_STALLCURRENT           1500
    #define E2_MAX_VOLTAGE             127
    #define E2_CHAIN_POS                -1
    #define E2_SLEW_RATE                 1
  #endif

  #if AXIS_IS_L64XX(E3)
    #define E3_MICROSTEPS    E0_MICROSTEPS
    #define E3_OVERCURRENT            2000
    #define E3_STALLCURRENT           1500
    #define E3_MAX_VOLTAGE             127
    #define E3_CHAIN_POS                -1
    #define E3_SLEW_RATE                 1
  #endif

  #if AXIS_IS_L64XX(E4)
    #define E4_MICROSTEPS    E0_MICROSTEPS
    #define E4_OVERCURRENT            2000
    #define E4_STALLCURRENT           1500
    #define E4_MAX_VOLTAGE             127
    #define E4_CHAIN_POS                -1
    #define E4_SLEW_RATE                 1
  #endif

  #if AXIS_IS_L64XX(E5)
    #define E5_MICROSTEPS    E0_MICROSTEPS
    #define E5_OVERCURRENT            2000
    #define E5_STALLCURRENT           1500
    #define E5_MAX_VOLTAGE             127
    #define E5_CHAIN_POS                -1
    #define E5_SLEW_RATE                 1
  #endif

  #if AXIS_IS_L64XX(E6)
    #define E6_MICROSTEPS    E0_MICROSTEPS
    #define E6_OVERCURRENT            2000
    #define E6_STALLCURRENT           1500
    #define E6_MAX_VOLTAGE             127
    #define E6_CHAIN_POS                -1
    #define E6_SLEW_RATE                 1
  #endif

  #if AXIS_IS_L64XX(E7)
    #define E7_MICROSTEPS    E0_MICROSTEPS
    #define E7_OVERCURRENT            2000
    #define E7_STALLCURRENT           1500
    #define E7_MAX_VOLTAGE             127
    #define E7_CHAIN_POS                -1
    #define E7_SLEW_RATE                 1
  #endif

  /**
   * Monitor L6470 drivers for error conditions like over temperature and over current.
   * In the case of over temperature Marlin can decrease the drive until the error condition clears.
   * Other detected conditions can be used to stop the current print.
   * Relevant G-codes:
   * M906 - I1/2/3/4/5  Set or get motor drive level using axis codes X, Y, Z, E. Report values if no axis codes given.
   *         I not present or I0 or I1 - X, Y, Z or E0
   *         I2 - X2, Y2, Z2 or E1
   *         I3 - Z3 or E3
   *         I4 - Z4 or E4
   *         I5 - E5
   * M916 - Increase drive level until get thermal warning
   * M917 - Find minimum current thresholds
   * M918 - Increase speed until max or error
   * M122 S0/1 - Report driver parameters
   */
  #if ENABLED(MONITOR_L6470_DRIVER_STATUS)
    #define KVAL_HOLD_STEP_DOWN     1

  #endif

#endif

/**
 * TWI/I2C BUS
 *
 * This feature is an EXPERIMENTAL feature so it shall not be used on production
 * machines. Enabling this will allow you to send and receive I2C data from slave
 * devices on the bus.
 *
 * ; Example #1
 * ; This macro send the string "Marlin" to the slave device with address 0x63 (99)
 * ; It uses multiple M260 commands with one B<base 10> arg
 * M260 A99  ; Target slave address
 * M260 B77  ; M
 * M260 B97  ; a
 * M260 B114 ; r
 * M260 B108 ; l
 * M260 B105 ; i
 * M260 B110 ; n
 * M260 S1   ; Send the current buffer
 *
 * ; Example #2
 * ; Request 6 bytes from slave device with address 0x63 (99)
 * M261 A99 B5
 *
 * ; Example #3
 * ; Example serial output of a M261 request
 * echo:i2c-reply: from:99 bytes:5 data:hello
 */
#if ENABLED(EXPERIMENTAL_I2CBUS)
  #define I2C_SLAVE_ADDRESS  0
#endif

/**
 * Photo G-code
 * Add the M240 G-code to take a photo.
 * The photo can be triggered by a digital pin or a physical movement.
 */

#if ENABLED(PHOTO_GCODE)

  /**
   * PHOTO_PULSES_US may need adjustment depending on board and camera model.
   * Pin must be running at 48.4kHz.
   * Be sure to use a PHOTOGRAPH_PIN which can rise and fall quick enough.
   * (e.g., MKS SBase temp sensor pin was too slow, so used P1.23 on J8.)
   *
   *  Example pulse data for Nikon: https:
   *                     IR Wiring: https:
   */

  #ifdef PHOTO_PULSES_US
    #define PHOTO_PULSE_DELAY_US 13
  #endif
#endif

/**
 * Spindle & Laser control
 *
 * Add the M3, M4, and M5 commands to turn the spindle/laser on and off, and
 * to set spindle speed, spindle direction, and laser power.
 *
 * SuperPid is a router/spindle speed controller used in the CNC milling community.
 * Marlin can be used to turn the spindle on and off. It can also be used to set
 * the spindle speed from 5,000 to 30,000 RPM.
 *
 * You'll need to select a pin for the ON/OFF function and optionally choose a 0-5V
 * hardware PWM pin for the speed control and a pin for the rotation direction.
 *
 * See https:
 */
#if EITHER(SPINDLE_FEATURE, LASER_FEATURE)
  #define SPINDLE_LASER_ACTIVE_STATE    LOW
  #define SPINDLE_LASER_PWM             true
  #define SPINDLE_LASER_PWM_INVERT      false

  #define SPINDLE_LASER_FREQUENCY       2500
  #if ENABLED(AIR_EVACUATION)
    #define AIR_EVACUATION_ACTIVE       LOW

  #endif
  #if ENABLED(AIR_ASSIST)
    #define AIR_ASSIST_ACTIVE           LOW

  #endif
  #ifdef SPINDLE_SERVO
    #define SPINDLE_SERVO_NR   0
    #define SPINDLE_SERVO_MIN 10
  #endif

  /**
   * Speed / Power can be set ('M3 S') and displayed in terms of:
   *  - PWM255  (S0 - S255)
   *  - PERCENT (S0 - S100)
   *  - RPM     (S0 - S50000)  Best for use with a spindle
   *  - SERVO   (S0 - S180)
   */
  #define CUTTER_POWER_UNIT PWM255

  /**
   * Relative Cutter Power
   * Normally, 'M3 O<power>' sets
   * OCR power is relative to the range SPEED_POWER_MIN...SPEED_POWER_MAX.
   * so input powers of 0...255 correspond to SPEED_POWER_MIN...SPEED_POWER_MAX
   * instead of normal range (0 to SPEED_POWER_MAX).
   * Best used with (e.g.) SuperPID router controller: S0 = 5,000 RPM and S255 = 30,000 RPM
   */
  #if ENABLED(SPINDLE_FEATURE)

    #define SPINDLE_CHANGE_DIR_STOP
    #define SPINDLE_INVERT_DIR          false

    #define SPINDLE_LASER_POWERUP_DELAY   5000
    #define SPINDLE_LASER_POWERDOWN_DELAY 5000

    /**
     * M3/M4 Power Equation
     *
     * Each tool uses different value ranges for speed / power control.
     * These parameters are used to convert between tool power units and PWM.
     *
     * Speed/Power = (PWMDC / 255 * 100 - SPEED_POWER_INTERCEPT) / SPEED_POWER_SLOPE
     * PWMDC = (spdpwr - SPEED_POWER_MIN) / (SPEED_POWER_MAX - SPEED_POWER_MIN) / SPEED_POWER_SLOPE
     */
    #define SPEED_POWER_INTERCEPT         0
    #define SPEED_POWER_MIN            5000
    #define SPEED_POWER_MAX           30000
    #define SPEED_POWER_STARTUP       25000

  #else

    #define SPEED_POWER_INTERCEPT         0
    #define SPEED_POWER_MIN               0
    #define SPEED_POWER_MAX             100
    #define SPEED_POWER_STARTUP          80
    #define LASER_TEST_PULSE_MIN           1
    #define LASER_TEST_PULSE_MAX         999

    /**
     * Enable inline laser power to be handled in the planner / stepper routines.
     * Inline power is specified by the I (inline) flag in an M3 command (e.g., M3 S20 I)
     * or by the 'S' parameter in G0/G1/G2/G3 moves (see LASER_MOVE_POWER).
     *
     * This allows the laser to keep in perfect sync with the planner and removes
     * the powerup/down delay since lasers require negligible time.
     */
    #if ENABLED(LASER_POWER_INLINE)
      /**
       * Scale the laser's power in proportion to the movement rate.
       *
       * - Sets the entry power proportional to the entry speed over the nominal speed.
       * - Ramps the power up every N steps to approximate the speed trapezoid.
       * - Due to the limited power resolution this is only approximate.
       */
      #define LASER_POWER_INLINE_TRAPEZOID

      /**
       * Continuously calculate the current power (nominal_power * current_rate / nominal_rate).
       * Required for accurate power with non-trapezoidal acceleration (e.g., S_CURVE_ACCELERATION).
       * This is a costly calculation so this option is discouraged on 8-bit AVR boards.
       *
       * LASER_POWER_INLINE_TRAPEZOID_CONT_PER defines how many step cycles there are between power updates. If your
       * board isn't able to generate steps fast enough (and you are using LASER_POWER_INLINE_TRAPEZOID_CONT), increase this.
       * Note that when this is zero it means it occurs every cycle; 1 means a delay wait one cycle then run, etc.
       */
      /**
       * Stepper iterations between power updates. Increase this value if the board
       * can't keep up with the processing demands of LASER_POWER_INLINE_TRAPEZOID_CONT.
       * Disable (or set to 0) to recalculate power on every stepper iteration.
       */
      /**
       * Include laser power in G0/G1/G2/G3/G5 commands with the 'S' parameter
       */
      #if ENABLED(LASER_MOVE_POWER)
      #endif

      /**
       * Inline flag inverted
       *
       * WARNING: M5 will NOT turn off the laser unless another move
       *          is done (so G-code files must end with 'M5 I').
       */
      /**
       * Continuously apply inline power. ('M3 S3' == 'G1 S3' == 'M3 S3 I')
       *
       * The laser might do some weird things, so only enable this
       * feature if you understand the implications.
       */
    #else

      #define SPINDLE_LASER_POWERUP_DELAY     50
      #define SPINDLE_LASER_POWERDOWN_DELAY   50

    #endif

    #if ENABLED(I2C_AMMETER)
      #define I2C_AMMETER_IMAX            0.1
      #define I2C_AMMETER_SHUNT_RESISTOR  0.1
    #endif

  #endif
#endif

/**
 * Synchronous Laser Control with M106/M107
 *
 * Marlin normally applies M106/M107 fan speeds at a time "soon after" processing
 * a planner block. This is too inaccurate for a PWM/TTL laser attached to the fan
 * header (as with some add-on laser kits). Enable this option to set fan/laser
 * speeds with much more exact timing for improved print fidelity.
 *
 * NOTE: This option sacrifices some cooling fan speed options.
 */
/**
 * Coolant Control
 *
 * Add the M7, M8, and M9 commands to turn mist or flood coolant on and off.
 *
 * Note: COOLANT_MIST_PIN and/or COOLANT_FLOOD_PIN must also be defined.
 */

#if ENABLED(COOLANT_CONTROL)
  #define COOLANT_MIST
  #define COOLANT_FLOOD
  #define COOLANT_MIST_INVERT  false
  #define COOLANT_FLOOD_INVERT false
#endif

/**
 * Filament Width Sensor
 *
 * Measures the filament width in real-time and adjusts
 * flow rate to compensate for any irregularities.
 *
 * Also allows the measured filament diameter to set the
 * extrusion rate, so the slicer only has to specify the
 * volume.
 *
 * Only a single extruder is supported at this time.
 *
 *  34 RAMPS_14    : Analog input 5 on the AUX2 connector
 *  81 PRINTRBOARD : Analog input 2 on the Exp1 connector (version B,C,D,E)
 * 301 RAMBO       : Analog input 3
 *
 * Note: May require analog pins to be defined for other boards.
 */
#if ENABLED(FILAMENT_WIDTH_SENSOR)
  #define FILAMENT_SENSOR_EXTRUDER_NUM 0
  #define MEASUREMENT_DELAY_CM        14

  #define FILWIDTH_ERROR_MARGIN        1.0
  #define MAX_MEASUREMENT_DELAY       20

  #define DEFAULT_MEASURED_FILAMENT_DIA DEFAULT_NOMINAL_FILAMENT_DIA

#endif

/**
 * Power Monitor
 * Monitor voltage (V) and/or current (A), and -when possible- power (W)
 *
 * Read and configure with M430
 *
 * The current sensor feeds DC voltage (relative to the measured current) to an analog pin
 * The voltage sensor feeds DC voltage (relative to the measured voltage) to an analog pin
 */

#if ENABLED(POWER_MONITOR_CURRENT)
  #define POWER_MONITOR_VOLTS_PER_AMP    0.05000
  #define POWER_MONITOR_CURRENT_OFFSET   0
  #define POWER_MONITOR_FIXED_VOLTAGE   13.6
#endif

#if ENABLED(POWER_MONITOR_VOLTAGE)
  #define POWER_MONITOR_VOLTS_PER_VOLT  0.077933
  #define POWER_MONITOR_VOLTAGE_OFFSET  0
#endif

/**
 * Stepper Driver Anti-SNAFU Protection
 *
 * If the SAFE_POWER_PIN is defined for your board, Marlin will check
 * that stepper drivers are properly plugged in before applying power.
 * Disable protection if your stepper drivers don't support the feature.
 */
/**
 * CNC Coordinate Systems
 *
 * Enables G53 and G54-G59.3 commands to select coordinate systems
 * and G92.1 to reset the workspace to native machine space.
 */
/**
 * Auto-report temperatures with M155 S<seconds>
 */
#define AUTO_REPORT_TEMPERATURES

/**
 * Auto-report position with M154 S<seconds>
 */
/**
 * Include capabilities in M115 output
 */
#define EXTENDED_CAPABILITIES_REPORT
#if ENABLED(EXTENDED_CAPABILITIES_REPORT)

#endif

/**
 * Expected Printer Check
 * Add the M16 G-code to compare a string to the MACHINE_NAME.
 * M16 with a non-matching string causes the printer to halt.
 */
/**
 * Disable all Volumetric extrusion options
 */
#if DISABLED(NO_VOLUMETRICS)
  /**
   * Volumetric extrusion default state
   * Activate to make volumetric extrusion the default method,
   * with DEFAULT_NOMINAL_FILAMENT_DIA as the default diameter.
   *
   * M200 D0 to disable, M200 Dn to set a new diameter (and enable volumetric).
   * M200 S0/S1 to disable/enable volumetric extrusion.
   */

  #if ENABLED(VOLUMETRIC_EXTRUDER_LIMIT)
    /**
     * Default volumetric extrusion limit in cubic mm per second (mm^3/sec).
     * This factory setting applies to all extruders.
     * Use 'M200 [T<extruder>] L<limit>' to override and 'M502' to reset.
     * A non-zero value activates Volume-based Extrusion Limiting.
     */
    #define DEFAULT_VOLUMETRIC_EXTRUDER_LIMIT 0.00
  #endif
#endif

/**
 * Enable this option for a leaner build of Marlin that removes all
 * workspace offsets, simplifying coordinate transformations, leveling, etc.
 *
 *  - M206 and M428 are disabled.
 *  - G92 will revert to its behavior from Marlin 1.0.
 */

/**
 * Set the number of proportional font spaces required to fill up a typical character space.
 * This can help to better align the output of commands like `G29 O` Mesh Output.
 *
 * For clients that use a fixed-width font (like OctoPrint), leave this set to 1.0.
 * Otherwise, adjust according to your client and font.
 */
#define PROPORTIONAL_FONT_RATIO 1.0

/**
 * Spend 28 bytes of SRAM to optimize the G-code parser
 */
#define FASTER_GCODE_PARSER

#if ENABLED(FASTER_GCODE_PARSER)

#endif

/**
 * CNC G-code options
 * Support CNC-style G-code dialects used by laser cutters, drawing machine cams, etc.
 * Note that G0 feedrates should be used with care for 3D printing (if used at all).
 * High feedrates may cause ringing and harm print quality.
 */

#ifdef G0_FEEDRATE

#endif

/**
 * Startup commands
 *
 * Execute certain G-code commands immediately after power-on.
 */
/**
 * G-code Macros
 *
 * Add G-codes M810-M819 to define and run G-code macros.
 * Macros are not saved to EEPROM.
 */

#if ENABLED(GCODE_MACROS)
  #define GCODE_MACROS_SLOTS       5
  #define GCODE_MACROS_SLOT_SIZE  50
#endif

/**
 * User-defined menu items to run custom G-code.
 * Up to 25 may be defined, but the actual number is LCD-dependent.
 */

#if ENABLED(CUSTOM_MENU_MAIN)

  #define CUSTOM_MENU_MAIN_SCRIPT_DONE "M117 User Script Done"
  #define CUSTOM_MENU_MAIN_SCRIPT_AUDIBLE_FEEDBACK

  #define CUSTOM_MENU_MAIN_ONLY_IDLE

  #define MAIN_MENU_ITEM_1_DESC "Home & UBL Info"
  #define MAIN_MENU_ITEM_1_GCODE "G28\nG29 W"
  #define MAIN_MENU_ITEM_2_DESC "Preheat for " PREHEAT_1_LABEL
  #define MAIN_MENU_ITEM_2_GCODE "M140 S" STRINGIFY(PREHEAT_1_TEMP_BED) "\nM104 S" STRINGIFY(PREHEAT_1_TEMP_HOTEND)

#endif

#if ENABLED(CUSTOM_MENU_CONFIG)

  #define CUSTOM_MENU_CONFIG_SCRIPT_DONE "M117 Wireless Script Done"
  #define CUSTOM_MENU_CONFIG_SCRIPT_AUDIBLE_FEEDBACK

  #define CUSTOM_MENU_CONFIG_ONLY_IDLE

  #define CONFIG_MENU_ITEM_1_DESC "Wifi ON"
  #define CONFIG_MENU_ITEM_1_GCODE "M118 [ESP110] WIFI-STA pwd=12345678"
  #define CONFIG_MENU_ITEM_2_DESC "Bluetooth ON"
  #define CONFIG_MENU_ITEM_2_GCODE "M118 [ESP110] BT pwd=12345678"

#endif

/**
 * User-defined buttons to run custom G-code.
 * Up to 25 may be defined.
 */

#if ENABLED(CUSTOM_USER_BUTTONS)

  #if PIN_EXISTS(BUTTON1)
    #define BUTTON1_HIT_STATE     LOW
    #define BUTTON1_WHEN_PRINTING false
    #define BUTTON1_GCODE         "G28"
    #define BUTTON1_DESC          "Homing"
  #endif
  #if PIN_EXISTS(BUTTON2)
    #define BUTTON2_HIT_STATE     LOW
    #define BUTTON2_WHEN_PRINTING false
    #define BUTTON2_GCODE         "M140 S" STRINGIFY(PREHEAT_1_TEMP_BED) "\nM104 S" STRINGIFY(PREHEAT_1_TEMP_HOTEND)
    #define BUTTON2_DESC          "Preheat for " PREHEAT_1_LABEL
  #endif
  #if PIN_EXISTS(BUTTON3)
    #define BUTTON3_HIT_STATE     LOW
    #define BUTTON3_WHEN_PRINTING false
    #define BUTTON3_GCODE         "M140 S" STRINGIFY(PREHEAT_2_TEMP_BED) "\nM104 S" STRINGIFY(PREHEAT_2_TEMP_HOTEND)
    #define BUTTON3_DESC          "Preheat for " PREHEAT_2_LABEL
  #endif
#endif

/**
 * Host Action Commands
 *
 * Define host streamer action commands in compliance with the standard.
 *
 * See https:
 * Common commands ........ poweroff, pause, paused, resume, resumed, cancel
 * G29_RETRY_AND_RECOVER .. probe_rewipe, probe_failed
 *
 * Some features add reason codes to extend these commands.
 *
 * Host Prompt Support enables Marlin to use the host for user prompts so
 * filament runout and other processes can be managed from the host side.
 */
#define HOST_ACTION_COMMANDS
#if ENABLED(HOST_ACTION_COMMANDS)
#endif

/**
 * Cancel Objects
 *
 * Implement M486 to allow Marlin to skip objects
 */
#define CANCEL_OBJECTS
#if ENABLED(CANCEL_OBJECTS)
  #define CANCEL_OBJECTS_REPORTING
#endif

/**
 * I2C position encoders for closed loop control.
 * Developed by Chris Barr at Aus3D.
 *
 * Wiki: https:
 * Github: https:
 *
 * Supplier: https:
 * Alternative Supplier: https:
 *
 * Reliabuild encoders have been modified to improve reliability.
 */
#if ENABLED(I2C_POSITION_ENCODERS)

  #define I2CPE_ENCODER_CNT         1
  #define I2CPE_ENC_1_ADDR          I2CPE_PRESET_ADDR_X
  #define I2CPE_ENC_1_AXIS          X_AXIS
  #define I2CPE_ENC_1_TYPE          I2CPE_ENC_TYPE_LINEAR

  #define I2CPE_ENC_1_TICKS_UNIT    2048

  #define I2CPE_ENC_1_EC_METHOD     I2CPE_ECM_MICROSTEP
  #define I2CPE_ENC_1_EC_THRESH     0.10
  #define I2CPE_ENC_2_ADDR          I2CPE_PRESET_ADDR_Y
  #define I2CPE_ENC_2_AXIS          Y_AXIS
  #define I2CPE_ENC_2_TYPE          I2CPE_ENC_TYPE_LINEAR
  #define I2CPE_ENC_2_TICKS_UNIT    2048
  #define I2CPE_ENC_2_EC_METHOD     I2CPE_ECM_MICROSTEP
  #define I2CPE_ENC_2_EC_THRESH     0.10

  #define I2CPE_ENC_3_ADDR          I2CPE_PRESET_ADDR_Z
  #define I2CPE_ENC_3_AXIS          Z_AXIS

  #define I2CPE_ENC_4_ADDR          I2CPE_PRESET_ADDR_E
  #define I2CPE_ENC_4_AXIS          E_AXIS

  #define I2CPE_ENC_5_ADDR          34
  #define I2CPE_ENC_5_AXIS          E_AXIS
  #define I2CPE_DEF_TYPE            I2CPE_ENC_TYPE_LINEAR
  #define I2CPE_DEF_ENC_TICKS_UNIT  2048
  #define I2CPE_DEF_TICKS_REV       (16 * 200)
  #define I2CPE_DEF_EC_METHOD       I2CPE_ECM_NONE
  #define I2CPE_DEF_EC_THRESH       0.1

  #define I2CPE_TIME_TRUSTED        10000

  /**
   * Position is checked every time a new command is executed from the buffer but during long moves,
   * this setting determines the minimum update time between checks. A value of 100 works well with
   * error rolling average when attempting to correct only for skips and not for vibration.
   */
  #define I2CPE_MIN_UPD_TIME_MS     4
  #define I2CPE_ERR_ROLLING_AVERAGE

#endif

/**
 * Analog Joystick(s)
 */

#if ENABLED(JOYSTICK)
  #define JOY_X_PIN    5
  #define JOY_Y_PIN   10
  #define JOY_Z_PIN   12
  #define JOY_EN_PIN  44
  #define JOY_X_LIMITS { 5600, 8190-100, 8190+100, 10800 }
  #define JOY_Y_LIMITS { 5600, 8250-100, 8250+100, 11000 }
  #define JOY_Z_LIMITS { 4800, 8080-100, 8080+100, 11550 }

#endif

/**
 * Mechanical Gantry Calibration
 * Modern replacement for the Prusa TMC_Z_CALIBRATION.
 * Adds capability to work with any adjustable current drivers.
 * Implemented as G34 because M915 is deprecated.
 */

#if ENABLED(MECHANICAL_GANTRY_CALIBRATION)
  #define GANTRY_CALIBRATION_CURRENT          600
  #define GANTRY_CALIBRATION_EXTRA_HEIGHT      15
  #define GANTRY_CALIBRATION_FEEDRATE         500

  #define GANTRY_CALIBRATION_COMMANDS_POST  "G28"
#endif

/**
 * Instant freeze / unfreeze functionality
 * Specified pin has pullup and connecting to ground will instantly pause motion.
 * Potentially useful for emergency stop that allows being resumed.
 */

#if ENABLED(FREEZE_FEATURE)

#endif

/**
 * MAX7219 Debug Matrix
 *
 * Add support for a low-cost 8x8 LED Matrix based on the Max7219 chip as a realtime status display.
 * Requires 3 signal wires. Some useful debug options are included to demonstrate its usage.
 */

#if ENABLED(MAX7219_DEBUG)
  #define MAX7219_CLK_PIN   64
  #define MAX7219_DIN_PIN   57
  #define MAX7219_LOAD_PIN  44
  #define MAX7219_INIT_TEST    2
  #define MAX7219_NUMBER_UNITS 1
  #define MAX7219_ROTATE       0
  /**
   * Sample debug features
   * If you add more debug displays, be careful to avoid conflicts!
   */
  #define MAX7219_DEBUG_PRINTER_ALIVE
  #define MAX7219_DEBUG_PLANNER_HEAD  3
  #define MAX7219_DEBUG_PLANNER_TAIL  5

  #define MAX7219_DEBUG_PLANNER_QUEUE 0
#endif

/**
 * NanoDLP Sync support
 *
 * Support for Synchronized Z moves when used with NanoDLP. G0/G1 axis moves will
 * output a "Z_move_comp" string to enable synchronization with DLP projector exposure.
 * This feature allows you to use [[WaitForDoneMessage]] instead of M400 commands.
 */

#if ENABLED(NANODLP_Z_SYNC)

#endif

/**
 * Ethernet. Use M552 to enable and set the IP address.
 */
#if HAS_ETHERNET
  #define MAC_ADDRESS { 0xDE, 0xAD, 0xBE, 0xEF, 0xF0, 0x0D }
#endif

/**
 * WiFi Support (Espressif ESP32 WiFi)
 */

#if EITHER(WIFISUPPORT, ESP3D_WIFISUPPORT)
  /**
   * To set a default WiFi SSID / Password, create a file called Configuration_Secure.h with
   * the following defines, customized for your network. This specific file is excluded via
   * .gitignore to prevent it from accidentally leaking to the public.
   *
   *   #define WIFI_SSID "WiFi SSID"
   *   #define WIFI_PWD  "WiFi Password"
   */

#endif

/**
 * Průša Multi-Material Unit (MMU)
 * Enable in Configuration.h
 *
 * These devices allow a single stepper driver on the board to drive
 * multi-material feeders with any number of stepper motors.
 */
#if HAS_PRUSA_MMU1
  /**
   * This option only allows the multiplexer to switch on tool-change.
   * Additional options to configure custom E moves are pending.
   *
   * Override the default DIO selector pins here, if needed.
   * Some pins files may provide defaults for these pins.
   */

#elif HAS_PRUSA_MMU2

  #define MMU2_SERIAL_PORT 2
  #define MMU2_FILAMENT_RUNOUT_SCRIPT "M600"

  #if EITHER(MMU2_MENUS, HAS_PRUSA_MMU2S)
    #define MMU2_FILAMENTCHANGE_EJECT_FEED 80.0
    #define MMU2_LOAD_TO_NOZZLE_SEQUENCE \
      {  7.2, 1145 }, \
      { 14.4,  871 }, \
      { 36.0, 1393 }, \
      { 14.4,  871 }, \
      { 50.0,  198 }

    #define MMU2_RAMMING_SEQUENCE \
      {   1.0, 1000 }, \
      {   1.0, 1500 }, \
      {   2.0, 2000 }, \
      {   1.5, 3000 }, \
      {   2.5, 4000 }, \
      { -15.0, 5000 }, \
      { -14.0, 1200 }, \
      {  -6.0,  600 }, \
      {  10.0,  700 }, \
      { -10.0,  400 }, \
      { -50.0, 2000 }
  #endif

  /**
   * Using a sensor like the MMU2S
   * This mode requires a MK3S extruder with a sensor at the extruder idler, like the MMU2S.
   * See https:
   */
  #if HAS_PRUSA_MMU2S
    #define MMU2_C0_RETRY   5

    #define MMU2_CAN_LOAD_FEEDRATE 800
    #define MMU2_CAN_LOAD_SEQUENCE \
      {  0.1, MMU2_CAN_LOAD_FEEDRATE }, \
      {  60.0, MMU2_CAN_LOAD_FEEDRATE }, \
      { -52.0, MMU2_CAN_LOAD_FEEDRATE }

    #define MMU2_CAN_LOAD_RETRACT   6.0
    #define MMU2_CAN_LOAD_DEVIATION 0.8

    #define MMU2_CAN_LOAD_INCREMENT 0.2
    #define MMU2_CAN_LOAD_INCREMENT_SEQUENCE \
      { -MMU2_CAN_LOAD_INCREMENT, MMU2_CAN_LOAD_FEEDRATE }

  #else

    /**
     * MMU1 Extruder Sensor
     *
     * Support for a Průša (or other) IR Sensor to detect filament near the extruder
     * and make loading more reliable. Suitable for an extruder equipped with a filament
     * sensor less than 38mm from the gears.
     *
     * During loading the extruder will stop when the sensor is triggered, then do a last
     * move up to the gears. If no filament is detected, the MMU2 can make some more attempts.
     * If all attempts fail, a filament runout will be triggered.
     */

    #if ENABLED(MMU_EXTRUDER_SENSOR)
      #define MMU_LOADING_ATTEMPTS_NR 5
    #endif

  #endif

#endif

/**
 * Advanced Print Counter settings
 */
#if ENABLED(PRINTCOUNTER)
  #define SERVICE_WARNING_BUZZES  3

#endif

/**
 * Postmortem Debugging captures misbehavior and outputs the CPU status and backtrace to serial.
 * When running in the debugger it will break for debugging. This is useful to help understand
 * a crash from a remote location. Requires ~400 bytes of SRAM and 5Kb of flash.
 */
/**
 * Software Reset options
 */
