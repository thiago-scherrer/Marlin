/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
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
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

#define CONFIGURATION_H_VERSION 02000901

#define STRING_CONFIG_H_AUTHOR "(thiago-scherrer, Ender-3)" // Who made the changes.

#define SHOW_BOOTSCREEN

#define SHOW_CUSTOM_BOOTSCREEN

#define CUSTOM_STATUS_SCREEN_IMAGE

#define SERIAL_PORT 2

#define SERIAL_PORT_2 -1

#define BAUDRATE 115200

#ifndef MOTHERBOARD
  #define MOTHERBOARD BOARD_BTT_SKR_MINI_E3_V2_0
#endif

#define CUSTOM_MACHINE_NAME "Ender-3"

#define EXTRUDERS 1

#define DEFAULT_NOMINAL_FILAMENT_DIA 1.75

#if LINEAR_AXES >= 4
  #define AXIS4_NAME 'A' // :['A', 'B', 'C', 'U', 'V', 'W']
#endif
#if LINEAR_AXES >= 5
  #define AXIS5_NAME 'B' // :['A', 'B', 'C', 'U', 'V', 'W']
#endif
#if LINEAR_AXES >= 6
  #define AXIS6_NAME 'C' // :['A', 'B', 'C', 'U', 'V', 'W']
#endif

#if ENABLED(SWITCHING_EXTRUDER)
  #define SWITCHING_EXTRUDER_SERVO_NR 0
  #define SWITCHING_EXTRUDER_SERVO_ANGLES { 0, 90 } // Angles for E0, E1[, E2, E3]
  #if EXTRUDERS > 3
    #define SWITCHING_EXTRUDER_E23_SERVO_NR 1
  #endif
#endif

#if ENABLED(SWITCHING_NOZZLE)
  #define SWITCHING_NOZZLE_SERVO_NR 0
  #define SWITCHING_NOZZLE_SERVO_ANGLES { 0, 90 }   // Angles for E0, E1 (single servo) or lowered/raised (dual servo)
#endif

#if EITHER(PARKING_EXTRUDER, MAGNETIC_PARKING_EXTRUDER)

  #define PARKING_EXTRUDER_PARKING_X { -78, 184 }     // X positions for parking the extruders
  #define PARKING_EXTRUDER_GRAB_DISTANCE 1            // (mm) Distance to move beyond the parking point to grab the extruder
  #if ENABLED(PARKING_EXTRUDER)

    #define PARKING_EXTRUDER_SOLENOIDS_INVERT           // If enabled, the solenoid is NOT magnetized with applied voltage
    #define PARKING_EXTRUDER_SOLENOIDS_PINS_ACTIVE LOW  // LOW or HIGH pin signal energizes the coil
    #define PARKING_EXTRUDER_SOLENOIDS_DELAY 250        // (ms) Delay for magnetic field. No delay if 0 or not defined.

  #elif ENABLED(MAGNETIC_PARKING_EXTRUDER)

    #define MPE_FAST_SPEED      9000      // (mm/min) Speed for travel before last distance point
    #define MPE_SLOW_SPEED      4500      // (mm/min) Speed for last distance travel to park and couple
    #define MPE_TRAVEL_DISTANCE   10      // (mm) Last distance point
    #define MPE_COMPENSATION       0      // Offset Compensation -1 , 0 , 1 (multiplier) only for coupling

  #endif

#endif

#if ANY(SWITCHING_TOOLHEAD, MAGNETIC_SWITCHING_TOOLHEAD, ELECTROMAGNETIC_SWITCHING_TOOLHEAD)
  #define SWITCHING_TOOLHEAD_Y_POS          235         // (mm) Y position of the toolhead dock
  #define SWITCHING_TOOLHEAD_Y_SECURITY      10         // (mm) Security distance Y axis
  #define SWITCHING_TOOLHEAD_Y_CLEAR         60         // (mm) Minimum distance from dock for unobstructed X axis
  #define SWITCHING_TOOLHEAD_X_POS          { 215, 0 }  // (mm) X positions for parking the extruders
  #if ENABLED(SWITCHING_TOOLHEAD)
    #define SWITCHING_TOOLHEAD_SERVO_NR       2         // Index of the servo connector
    #define SWITCHING_TOOLHEAD_SERVO_ANGLES { 0, 180 }  // (degrees) Angles for Lock, Unlock
  #elif ENABLED(MAGNETIC_SWITCHING_TOOLHEAD)
    #define SWITCHING_TOOLHEAD_Y_RELEASE      5         // (mm) Security distance Y axis
    #define SWITCHING_TOOLHEAD_X_SECURITY   { 90, 150 } // (mm) Security distance X axis (T0,T1)
    #if ENABLED(PRIME_BEFORE_REMOVE)
      #define SWITCHING_TOOLHEAD_PRIME_MM           20  // (mm)   Extruder prime length
      #define SWITCHING_TOOLHEAD_RETRACT_MM         10  // (mm)   Retract after priming length
      #define SWITCHING_TOOLHEAD_PRIME_FEEDRATE    300  // (mm/min) Extruder prime feedrate
      #define SWITCHING_TOOLHEAD_RETRACT_FEEDRATE 2400  // (mm/min) Extruder retract feedrate
    #endif
  #elif ENABLED(ELECTROMAGNETIC_SWITCHING_TOOLHEAD)
    #define SWITCHING_TOOLHEAD_Z_HOP          2         // (mm) Z raise for switching
  #endif
#endif

#if ENABLED(MIXING_EXTRUDER)
  #define MIXING_STEPPERS 2        // Number of steppers in your mixing extruder
  #define MIXING_VIRTUAL_TOOLS 16  // Use the Virtual Tool method with M163 and M164
  #if ENABLED(GRADIENT_MIX)
  #endif
#endif


#if ENABLED(PSU_CONTROL)
  #define PSU_ACTIVE_STATE LOW      // Set 'LOW' for ATX, 'HIGH' for X-Box
  #if ENABLED(AUTO_POWER_CONTROL)
    #define AUTO_POWER_FANS         // Turn on PSU if fans need power
    #define AUTO_POWER_E_FANS
    #define AUTO_POWER_CONTROLLERFAN
    #define AUTO_POWER_CHAMBER_FAN
    #define AUTO_POWER_COOLER_FAN
    #define POWER_TIMEOUT              30 // (s) Turn off power if the machine is idle for this duration
  #endif
#endif

#define TEMP_SENSOR_0 1
#define TEMP_SENSOR_1 0
#define TEMP_SENSOR_2 0
#define TEMP_SENSOR_3 0
#define TEMP_SENSOR_4 0
#define TEMP_SENSOR_5 0
#define TEMP_SENSOR_6 0
#define TEMP_SENSOR_7 0
#define TEMP_SENSOR_BED 1
#define TEMP_SENSOR_PROBE 0
#define TEMP_SENSOR_CHAMBER 0
#define TEMP_SENSOR_COOLER 0
#define TEMP_SENSOR_BOARD 0
#define TEMP_SENSOR_REDUNDANT 0

// Dummy thermistor constant temperature readings, for use with 998 and 999
#define DUMMY_THERMISTOR_998_VALUE  25
#define DUMMY_THERMISTOR_999_VALUE 100

// Resistor values when using MAX31865 sensors (-5) on TEMP_SENSOR_0 / 1
//#define MAX31865_SENSOR_OHMS_0      100   // (Ω) Typically 100 or 1000 (PT100 or PT1000)
//#define MAX31865_CALIBRATION_OHMS_0 430   // (Ω) Typically 430 for AdaFruit PT100; 4300 for AdaFruit PT1000
//#define MAX31865_SENSOR_OHMS_1      100
//#define MAX31865_CALIBRATION_OHMS_1 430

#define TEMP_RESIDENCY_TIME         10  // (seconds) Time to wait for hotend to "settle" in M109
#define TEMP_WINDOW                  1  // (°C) Temperature proximity for the "temperature reached" timer
#define TEMP_HYSTERESIS              3  // (°C) Temperature proximity considered "close enough" to the target

#define TEMP_BED_RESIDENCY_TIME     10  // (seconds) Time to wait for bed to "settle" in M190
#define TEMP_BED_WINDOW              1  // (°C) Temperature proximity for the "temperature reached" timer
#define TEMP_BED_HYSTERESIS          3  // (°C) Temperature proximity considered "close enough" to the target

#define TEMP_CHAMBER_RESIDENCY_TIME 10  // (seconds) Time to wait for chamber to "settle" in M191
#define TEMP_CHAMBER_WINDOW          1  // (°C) Temperature proximity for the "temperature reached" timer
#define TEMP_CHAMBER_HYSTERESIS      3  // (°C) Temperature proximity considered "close enough" to the target

/**
 * Redundant Temperature Sensor (TEMP_SENSOR_REDUNDANT)
 *
 * Use a temp sensor as a redundant sensor for another reading. Select an unused temperature sensor, and another
 * sensor you'd like it to be redundant for. If the two thermistors differ by TEMP_SENSOR_REDUNDANT_MAX_DIFF (°C),
 * the print will be aborted. Whichever sensor is selected will have its normal functions disabled; i.e. selecting
 * the Bed sensor (-1) will disable bed heating/monitoring.
 *
 * For selecting source/target use: COOLER, PROBE, BOARD, CHAMBER, BED, E0, E1, E2, E3, E4, E5, E6, E7
 */
#if TEMP_SENSOR_REDUNDANT
  #define TEMP_SENSOR_REDUNDANT_SOURCE    E1  // The sensor that will provide the redundant reading.
  #define TEMP_SENSOR_REDUNDANT_TARGET    E0  // The sensor that we are providing a redundant reading for.
  #define TEMP_SENSOR_REDUNDANT_MAX_DIFF  10  // (°C) Temperature difference that will trigger a print abort.
#endif

#define HEATER_0_MINTEMP   5
#define HEATER_1_MINTEMP   5
#define HEATER_2_MINTEMP   5
#define HEATER_3_MINTEMP   5
#define HEATER_4_MINTEMP   5
#define HEATER_5_MINTEMP   5
#define HEATER_6_MINTEMP   5
#define HEATER_7_MINTEMP   5
#define BED_MINTEMP        5
#define CHAMBER_MINTEMP    5

#define HEATER_0_MAXTEMP 275
#define HEATER_1_MAXTEMP 275
#define HEATER_2_MAXTEMP 275
#define HEATER_3_MAXTEMP 275
#define HEATER_4_MAXTEMP 275
#define HEATER_5_MAXTEMP 275
#define HEATER_6_MAXTEMP 275
#define HEATER_7_MAXTEMP 275
#define BED_MAXTEMP      125
#define CHAMBER_MAXTEMP  60

#define HOTEND_OVERSHOOT 15   // (°C) Forbid temperatures over MAXTEMP - OVERSHOOT
#define BED_OVERSHOOT    10   // (°C) Forbid temperatures over MAXTEMP - OVERSHOOT
#define COOLER_OVERSHOOT  2   // (°C) Forbid temperatures closer than OVERSHOOT

#define PIDTEMP
#define BANG_MAX 255     // Limits current to nozzle while in bang-bang mode; 255=full current
#define PID_MAX BANG_MAX // Limits current to nozzle while PID is active (see PID_FUNCTIONAL_RANGE below); 255=full current
#define PID_K1 0.95      // Smoothing factor within any PID loop

#if ENABLED(PIDTEMP)
  #if ENABLED(PID_PARAMS_PER_HOTEND)
    #define DEFAULT_Kp_LIST {  21.73,  21.73 }
    #define DEFAULT_Ki_LIST {   1.54,   1.54 }
    #define DEFAULT_Kd_LIST {  76.55,  76.55 }
  #else
    #define DEFAULT_Kp  21.73
    #define DEFAULT_Ki   1.54
    #define DEFAULT_Kd  76.55
  #endif
#endif // PIDTEMP

//===========================================================================
//==================== PID > Chamber Temperature Control ====================
//===========================================================================

#define MAX_CHAMBER_POWER 255 // limits duty cycle to chamber heater; 255=full current

#if ENABLED(PIDTEMPBED)
  #define DEFAULT_bedKp 50.71
  #define DEFAULT_bedKi 9.88
  #define DEFAULT_bedKd 173.43
#endif // PIDTEMPBED

#if ENABLED(PIDTEMPCHAMBER)
  #define MIN_CHAMBER_POWER 0
  #define DEFAULT_chamberKp 37.04
  #define DEFAULT_chamberKi 1.40
  #define DEFAULT_chamberKd 655.17
#endif // PIDTEMPCHAMBER

#if ANY(PIDTEMP, PIDTEMPBED, PIDTEMPCHAMBER)
  #define PID_FUNCTIONAL_RANGE 10 // If the temperature difference between the target temperature and the actual temperature
#endif

#define PREVENT_COLD_EXTRUSION
#define EXTRUDE_MINTEMP 170

#define PREVENT_LENGTHY_EXTRUDE
#define EXTRUDE_MAXLENGTH 235

#define THERMAL_PROTECTION_HOTENDS // Enable thermal protection for all extruders
#define THERMAL_PROTECTION_BED     // Enable thermal protection for the heated bed
#define THERMAL_PROTECTION_CHAMBER // Enable thermal protection for the heated chamber
#define THERMAL_PROTECTION_COOLER  // Enable thermal protection for the laser cooling

#define USE_XMIN_PLUG
#define USE_YMIN_PLUG
#define USE_ZMIN_PLUG

// Enable pullup for all endstops to prevent a floating state
#define ENDSTOPPULLUPS
#if DISABLED(ENDSTOPPULLUPS)

#endif

#if DISABLED(ENDSTOPPULLDOWNS)

#endif

// Mechanical endstop with COM to ground and NC to Signal uses "false" here (most common setup).
#define X_MIN_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define Y_MIN_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define Z_MIN_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define I_MIN_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define J_MIN_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define K_MIN_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define X_MAX_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define Y_MAX_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define Z_MAX_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define I_MAX_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define J_MAX_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define K_MAX_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define Z_MIN_PROBE_ENDSTOP_INVERTING false // Set to true to invert the logic of the probe.

#define X_DRIVER_TYPE  TMC2209
#define Y_DRIVER_TYPE  TMC2209
#define Z_DRIVER_TYPE  TMC2209
#define E0_DRIVER_TYPE TMC2209
//#define ENDSTOP_INTERRUPTS_FEATURE
//#define DETECT_BROKEN_ENDSTOP

#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 400, 100.98 }

/**
 * Default Max Feed Rate (mm/s)
 * Override with M203
 *                                      X, Y, Z, E0 [, E1[, E2...]]
 */
#define DEFAULT_MAX_FEEDRATE          { 500, 500, 20, 120 }

#if ENABLED(LIMITED_MAX_FR_EDITING)
  #define MAX_FEEDRATE_EDIT_VALUES    { 600, 600, 10, 50 } // ...or, set your own edit limits
#endif

/**
 * Default Max Acceleration (change/s) change = mm/s
 * (Maximum start speed for accelerated moves)
 * Override with M201
 *                                      X, Y, Z, E0 [, E1[, E2...]]
 */
#define DEFAULT_MAX_ACCELERATION      { 500, 500, 100, 5000 }

#if ENABLED(LIMITED_MAX_ACCEL_EDITING)
  #define MAX_ACCEL_EDIT_VALUES       { 6000, 6000, 200, 20000 } // ...or, set your own edit limits
#endif

#define DEFAULT_ACCELERATION          500    // X, Y, Z and E acceleration for printing moves
#define DEFAULT_RETRACT_ACCELERATION  500    // E acceleration for retracts
#define DEFAULT_TRAVEL_ACCELERATION   500    // X, Y, Z acceleration for travel (non printing) moves

#define CLASSIC_JERK
#if ENABLED(CLASSIC_JERK)
  #define DEFAULT_XJERK 10.0
  #define DEFAULT_YJERK 10.0
  #define DEFAULT_ZJERK  0.3

//#define TRAVEL_EXTRA_XYJERK 5.0     // Additional jerk allowance for all travel moves

  #if ENABLED(LIMITED_JERK_EDITING)
    #define MAX_JERK_EDIT_VALUES { 20, 20, 0.6, 10 } // ...or, set your own edit limits
  #endif
#endif

#define DEFAULT_EJERK    5.0  // May be used by Linear Advance

#if DISABLED(CLASSIC_JERK)
  #define JUNCTION_DEVIATION_MM 0.08 // (mm) Distance from real junction edge
  #define JD_HANDLE_SMALL_SEGMENTS    // Use curvature estimation instead of just the junction angle
                                      // for small segments (< 1mm) with large junction angles (> 135°).
#endif

#define S_CURVE_ACCELERATION

#define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN

#define BLTOUCH

#if ENABLED(TOUCH_MI_PROBE)
  #define TOUCH_MI_RETRACT_Z 0.5                  // Height at which the probe retracts
#endif

#if ENABLED(RACK_AND_PINION_PROBE)
  #define Z_PROBE_DEPLOY_X  X_MIN_POS
  #define Z_PROBE_RETRACT_X X_MAX_POS
#endif

#if ENABLED(DUET_SMART_EFFECTOR)
  #define SMART_EFFECTOR_MOD_PIN  -1  // Connect a GPIO pin to the Smart Effector MOD pin
#endif

#define NOZZLE_TO_PROBE_OFFSET { -40, -12, 0 }

#define PROBING_MARGIN 15

#define XY_PROBE_FEEDRATE (133*60)

#define Z_PROBE_FEEDRATE_FAST (4*60)

#define Z_PROBE_FEEDRATE_SLOW (Z_PROBE_FEEDRATE_FAST / 2)

#if ENABLED(PROBE_ACTIVATION_SWITCH)
  #define PROBE_ACTIVATION_SWITCH_STATE LOW // State indicating probe is active
#endif

#if ENABLED(PROBE_TARE)
  #define PROBE_TARE_TIME  200    // (ms) Time to hold tare pin
  #define PROBE_TARE_DELAY 200    // (ms) Delay after tare before
  #define PROBE_TARE_STATE HIGH   // State to write pin for tare
  #if ENABLED(PROBE_ACTIVATION_SWITCH)
  #endif
#endif

#define Z_CLEARANCE_DEPLOY_PROBE   10 // Z Clearance for Deploy/Stow
#define Z_CLEARANCE_BETWEEN_PROBES  5 // Z Clearance between probe points
#define Z_CLEARANCE_MULTI_PROBE     5 // Z Clearance between multiple probes

#define Z_PROBE_LOW_POINT          -2 // Farthest distance below the trigger-point to go before stopping

#define Z_PROBE_OFFSET_RANGE_MIN -20
#define Z_PROBE_OFFSET_RANGE_MAX 20

//#define Z_MIN_PROBE_REPEATABILITY_TEST

#if ENABLED(PAUSE_BEFORE_DEPLOY_STOW)
#endif

#if ENABLED(PROBING_HEATERS_OFF)
#endif

#if ENABLED(PREHEAT_BEFORE_PROBING)
  #define PROBING_NOZZLE_TEMP 120   // (°C) Only applies to E0 at this time
  #define PROBING_BED_TEMP     50
#endif

#define X_ENABLE_ON 0
#define Y_ENABLE_ON 0
#define Z_ENABLE_ON 0
#define E_ENABLE_ON 0 // For all extruders

#define DISABLE_X false
#define DISABLE_Y false
#define DISABLE_Z false

#define DISABLE_E false             // Disable the extruder when not stepping
#define DISABLE_INACTIVE_EXTRUDER   // Keep only the active extruder enabled

#define INVERT_X_DIR true
#define INVERT_Y_DIR true
#define INVERT_Z_DIR false

#define INVERT_E0_DIR true
#define INVERT_E1_DIR false
#define INVERT_E2_DIR false
#define INVERT_E3_DIR false
#define INVERT_E4_DIR false
#define INVERT_E5_DIR false
#define INVERT_E6_DIR false
#define INVERT_E7_DIR false

#define X_HOME_DIR -1
#define Y_HOME_DIR -1
#define Z_HOME_DIR -1

#define X_BED_SIZE 235
#define Y_BED_SIZE 235

#define X_MIN_POS 0
#define Y_MIN_POS 0
#define Z_MIN_POS 0
#define X_MAX_POS X_BED_SIZE
#define Y_MAX_POS Y_BED_SIZE
#define Z_MAX_POS 250

#define MIN_SOFTWARE_ENDSTOPS
#if ENABLED(MIN_SOFTWARE_ENDSTOPS)
  #define MIN_SOFTWARE_ENDSTOP_X
  #define MIN_SOFTWARE_ENDSTOP_Y
  #define MIN_SOFTWARE_ENDSTOP_Z
  #define MIN_SOFTWARE_ENDSTOP_I
  #define MIN_SOFTWARE_ENDSTOP_J
  #define MIN_SOFTWARE_ENDSTOP_K
#endif

#define MAX_SOFTWARE_ENDSTOPS
#if ENABLED(MAX_SOFTWARE_ENDSTOPS)
  #define MAX_SOFTWARE_ENDSTOP_X
  #define MAX_SOFTWARE_ENDSTOP_Y
  #define MAX_SOFTWARE_ENDSTOP_Z
  #define MAX_SOFTWARE_ENDSTOP_I
  #define MAX_SOFTWARE_ENDSTOP_J
  #define MAX_SOFTWARE_ENDSTOP_K
#endif

#if EITHER(MIN_SOFTWARE_ENDSTOPS, MAX_SOFTWARE_ENDSTOPS)
#endif

#if ENABLED(FILAMENT_RUNOUT_SENSOR)
  #define FIL_RUNOUT_ENABLED_DEFAULT true // Enable the sensor on startup. Override with M412 followed by M500.
  #define NUM_RUNOUT_SENSORS   1          // Number of sensors, up to one per extruder. Define a FIL_RUNOUT#_PIN for each.

  #define FIL_RUNOUT_STATE     LOW        // Pin state indicating that filament is NOT present.
  #define FIL_RUNOUT_PULLUP               // Use internal pullup for filament runout pins.
  #define FILAMENT_RUNOUT_SCRIPT "M600"

  #ifdef FILAMENT_RUNOUT_DISTANCE_MM
  #endif
#endif

#define AUTO_BED_LEVELING_BILINEAR
#define RESTORE_LEVELING_AFTER_G28
#if ENABLED(PREHEAT_BEFORE_LEVELING)
  #define LEVELING_NOZZLE_TEMP 120   // (°C) Only applies to E0 at this time
  #define LEVELING_BED_TEMP     50
#endif


#if ANY(MESH_BED_LEVELING, AUTO_BED_LEVELING_UBL, PROBE_MANUALLY)
  #define MANUAL_PROBE_START_Z 0.2  // (mm) Comment out to use the last-measured height
#endif

#if ANY(MESH_BED_LEVELING, AUTO_BED_LEVELING_BILINEAR, AUTO_BED_LEVELING_UBL)
  #define ENABLE_LEVELING_FADE_HEIGHT
  #if ENABLED(ENABLE_LEVELING_FADE_HEIGHT)
    #define DEFAULT_LEVELING_FADE_HEIGHT 10.0 // (mm) Default fade height.
  #endif

  #define SEGMENT_LEVELED_MOVES
  #define LEVELED_SEGMENT_LENGTH 5.0 // (mm) Length of all segments (except the last one)

  #if ENABLED(G26_MESH_VALIDATION)
    #define MESH_TEST_NOZZLE_SIZE    0.4  // (mm) Diameter of primary nozzle.
    #define MESH_TEST_LAYER_HEIGHT   0.2  // (mm) Default layer height for G26.
    #define MESH_TEST_HOTEND_TEMP  205    // (°C) Default nozzle temperature for G26.
    #define MESH_TEST_BED_TEMP      60    // (°C) Default bed temperature for G26.
    #define G26_XY_FEEDRATE         20    // (mm/s) Feedrate for G26 XY moves.
    #define G26_XY_FEEDRATE_TRAVEL 100    // (mm/s) Feedrate for G26 XY travel moves.
    #define G26_RETRACT_MULTIPLIER   1.0  // G26 Q (retraction) used by default between mesh test elements.
  #endif

#endif

#if EITHER(AUTO_BED_LEVELING_LINEAR, AUTO_BED_LEVELING_BILINEAR)

  #define GRID_MAX_POINTS_X 5
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

  #if ENABLED(AAUTO_BED_LEVELING_BILINEARUTO_BED_LEVELING_BILINEAR)

      #if ENABLED(ABL_BILINEAR_SUBDIVISION)
      #define BILINEAR_SUBDIVISIONS 3
    #endif

  #endif

#elif ENABLED(AUTO_BED_LEVELING_UBL)

  #define MESH_INSET 1              // Set Mesh bounds as an inset region of the bed
  #define GRID_MAX_POINTS_X 10      // Don't use more than 15 points per axis, implementation limited.
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X
  #define UBL_MESH_EDIT_MOVES_Z     // Sophisticated users prefer no movement of nozzle
  #define UBL_SAVE_ACTIVE_ON_M500   // Save the currently active mesh in the current slot on M500
#elif ENABLED(MESH_BED_LEVELING)
  #define MESH_INSET 10          // Set Mesh bounds as an inset region of the bed
  #define GRID_MAX_POINTS_X 3    // Don't use more than 7 points per axis, implementation limited.
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X
#endif // BED_LEVELING

#if ENABLED(LCD_BED_LEVELING)
  #define MESH_EDIT_Z_STEP  0.025 // (mm) Step size while manually probing Z axis.
  #define LCD_PROBE_Z_RANGE 4     // (mm) Z Range centered on Z_MIN_POS for LCD Z adjustment
  #define MESH_EDIT_MENU        // Add a menu to edit mesh points
#endif

#define LEVEL_BED_CORNERS

#if ENABLED(LEVEL_BED_CORNERS)
  #define LEVEL_CORNERS_INSET_LFRB { 30, 30, 30, 30 } // (mm) Left, Front, Right, Back insets
  #define LEVEL_CORNERS_HEIGHT      0.5   // (mm) Z height of nozzle at leveling points
  #define LEVEL_CORNERS_Z_HOP       4.0   // (mm) Z height of nozzle between leveling points
  #if ENABLED(LEVEL_CORNERS_USE_PROBE)
    #define LEVEL_CORNERS_PROBE_TOLERANCE 0.1
    #define LEVEL_CORNERS_VERIFY_RAISED   // After adjustment triggers the probe, re-probe to verify
  #endif

  #define LEVEL_CORNERS_LEVELING_ORDER { LF, RF, RB, LB }
#endif

#define Z_SAFE_HOMING

#if ENABLED(Z_SAFE_HOMING)
  #define Z_SAFE_HOMING_X_POINT X_CENTER  // X point for Z homing
  #define Z_SAFE_HOMING_Y_POINT Y_CENTER  // Y point for Z homing
#endif

#define HOMING_FEEDRATE_MM_M { (50*60), (50*60), (4*60) }

#define VALIDATE_HOMING_ENDSTOPS

#if ENABLED(SKEW_CORRECTION)
  #define XY_DIAG_AC 282.8427124746
  #define XY_DIAG_BD 282.8427124746
  #define XY_SIDE_AD 200

  #define XY_SKEW_FACTOR 0.0

  #if ENABLED(SKEW_CORRECTION_FOR_Z)
    #define XZ_DIAG_AC 282.8427124746
    #define XZ_DIAG_BD 282.8427124746
    #define YZ_DIAG_AC 282.8427124746
    #define YZ_DIAG_BD 282.8427124746
    #define YZ_SIDE_AD 200
    #define XZ_SKEW_FACTOR 0.0
    #define YZ_SKEW_FACTOR 0.0
  #endif

#endif

#define EEPROM_SETTINGS     // Persistent storage with M500 and M501
#define EEPROM_CHITCHAT       // Give feedback on EEPROM commands. Disable to save PROGMEM.
#define EEPROM_BOOT_SILENT    // Keep M503 quiet and only give errors during first load
#if ENABLED(EEPROM_SETTINGS)
  #define EEPROM_AUTO_INIT  // Init EEPROM automatically on any errors.
#endif

#define HOST_KEEPALIVE_FEATURE        // Disable this if your host doesn't like keepalive messages
#define DEFAULT_KEEPALIVE_INTERVAL 2  // Number of seconds between "busy" messages. Set with M113.
#define BUSY_WHILE_HEATING            // Some hosts require "busy" messages even during heating

#define PREHEAT_1_LABEL       "PLA"
#define PREHEAT_1_TEMP_HOTEND 185
#define PREHEAT_1_TEMP_BED     45
#define PREHEAT_1_TEMP_CHAMBER 35
#define PREHEAT_1_FAN_SPEED   255 // Value from 0 to 255

#define PREHEAT_2_LABEL       "ABS"
#define PREHEAT_2_TEMP_HOTEND 240
#define PREHEAT_2_TEMP_BED    110
#define PREHEAT_2_TEMP_CHAMBER 35
#define PREHEAT_2_FAN_SPEED   255 // Value from 0 to 255

#define NOZZLE_PARK_FEATURE

#if ENABLED(NOZZLE_PARK_FEATURE)
  #define NOZZLE_PARK_POINT { (X_MIN_POS + 10), (Y_MAX_POS - 10), 20 }
  #define NOZZLE_PARK_Z_RAISE_MIN   2   // (mm) Always raise Z by at least this distance
  #define NOZZLE_PARK_XY_FEEDRATE 100   // (mm/s) X and Y axes feedrate (also used for delta Z axis)
  #define NOZZLE_PARK_Z_FEEDRATE    5   // (mm/s) Z axis feedrate (not used for delta printers)
#endif

//#define NOZZLE_CLEAN_FEATURE

#if ENABLED(NOZZLE_CLEAN_FEATURE)
  #define NOZZLE_CLEAN_STROKES  12

  #define NOZZLE_CLEAN_TRIANGLES  3

  #define NOZZLE_CLEAN_START_POINT { {  30, 30, (Z_MIN_POS + 1) } }
  #define NOZZLE_CLEAN_END_POINT   { { 100, 60, (Z_MIN_POS + 1) } }

  #define NOZZLE_CLEAN_CIRCLE_RADIUS 6.5
  #define NOZZLE_CLEAN_CIRCLE_FN 10
  #define NOZZLE_CLEAN_CIRCLE_MIDDLE NOZZLE_CLEAN_START_POINT

  #define NOZZLE_CLEAN_GOBACK

  #define NOZZLE_CLEAN_MIN_TEMP 170
#endif

#define PRINTJOB_TIMER_AUTOSTART

#if ENABLED(PRINTCOUNTER)
  #define PRINTCOUNTER_SAVE_INTERVAL 60 // (minutes) EEPROM save interval during print
#endif

//#define PASSWORD_FEATURE
#if ENABLED(PASSWORD_FEATURE)
  #define PASSWORD_LENGTH 4                 // (#) Number of digits (1-9). 3 or 4 is recommended
  #define PASSWORD_ON_STARTUP
  #define PASSWORD_UNLOCK_GCODE             // Unlock with the M511 P<password> command. Disable to prevent brute-force attack.
  #define PASSWORD_CHANGE_GCODE             // Change the password with M512 P<old> S<new>.
#endif

#define LCD_LANGUAGE en

#define DISPLAY_CHARSET_HD44780 JAPANESE

#define LCD_INFO_SCREEN_STYLE 0

#define SDSUPPORT

#define INDIVIDUAL_AXIS_HOMING_MENU

#define CR10_STOCKDISPLAY

#if ENABLED(SAV_3DGLCD)
  #define U8GLIB_SSD1306
#endif

#if ENABLED(DGUS_LCD_UI_MKS)
  #define USE_MKS_GREEN_UI
#endif

#if ENABLED(MALYAN_LCD)
  #define LCD_SERIAL_PORT 1  // Default is 1 for Malyan M200
#endif

#if EITHER(ANYCUBIC_LCD_I3MEGA, ANYCUBIC_LCD_CHIRON)
  #define LCD_SERIAL_PORT 3  // Default is 3 for Anycubic
#endif

#if ENABLED(NEXTION_TFT)
  #define LCD_SERIAL_PORT 1  // Default is 1 for Nextion
#endif

#if ENABLED(EXTENSIBLE_UI)
#endif

#if ENABLED(TFT_GENERIC)
  #define TFT_DRIVER AUTO
#endif

#if ENABLED(TFT_LVGL_UI)
#endif

#if ENABLED(TOUCH_SCREEN)
  #define BUTTON_DELAY_EDIT  50 // (ms) Button repeat delay for edit screens
  #define BUTTON_DELAY_MENU 250 // (ms) Button repeat delay for menus

  #define TOUCH_SCREEN_CALIBRATION

  #if BOTH(TOUCH_SCREEN_CALIBRATION, EEPROM_SETTINGS)
    #define TOUCH_CALIBRATION_AUTO_SAVE // Auto save successful calibration values to EEPROM
  #endif

  #if ENABLED(TFT_COLOR_UI)
  #endif
#endif

//#define FAN_SOFT_PWM

#define SOFT_PWM_SCALE 0

#if EITHER(RGB_LED, RGBW_LED)
#endif

#if ENABLED(NEOPIXEL_LED)
  #define NEOPIXEL_TYPE   NEO_GRBW // NEO_GRBW / NEO_GRB - four/three channel driver type (defined in Adafruit_NeoPixel.h)
  #define NEOPIXEL_PIN     4       // LED driving pin
  #define NEOPIXEL_PIXELS 30       // Number of LEDs in the strip. (Longest strip when NEOPIXEL2_SEPARATE is disabled.)
  #define NEOPIXEL_IS_SEQUENTIAL   // Sequential display for temperature change - LED by LED. Disable to change all LEDs at once.
  #define NEOPIXEL_BRIGHTNESS 127  // Initial brightness (0-255)
  #if ENABLED(NEOPIXEL2_SEPARATE)
    #define NEOPIXEL2_PIXELS      15  // Number of LEDs in the second strip
    #define NEOPIXEL2_BRIGHTNESS 127  // Initial brightness (0-255)
    #define NEOPIXEL2_STARTUP_TEST    // Cycle through colors at startup
  #else
  #endif
#endif

#if ANY(BLINKM, RGB_LED, RGBW_LED, PCA9632, PCA9533, NEOPIXEL_LED)
  #define PRINTER_EVENT_LEDS
#endif

#define SERVO_DELAY { 300 }
