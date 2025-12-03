/**
 * G299: Virtual Joystick Control
 * 
 * Parameters:
 *   X[float] - X axis jog value (-1.0 to 1.0)
 *   Y[float] - Y axis jog value (-1.0 to 1.0)  
 *   Z[float] - Z axis jog value (-1.0 to 1.0)
 *   E[float] - Enable/disable (1=enable, 0=disable)
 */

#include "../../inc/MarlinConfig.h"

#if ENABLED(JOYSTICK)

#include "../gcode.h"
#include "../../feature/joystick.h"

// Global variables to store virtual joystick state
// xyz_float_t virtual_joystick_values = {0};
// bool virtual_joystick_active = false;

extern xyz_float_t virtual_joystick_values;
extern bool virtual_joystick_active;

void GcodeSuite::G299() {
  if (parser.seen('E')) {
    virtual_joystick_active = parser.value_bool();
  }
  
  if (virtual_joystick_active) {
    if (parser.seen('X')) virtual_joystick_values.x = constrain(parser.value_float(), -1.0f, 1.0f);
    if (parser.seen('Y')) virtual_joystick_values.y = constrain(parser.value_float(), -1.0f, 1.0f);
    if (parser.seen('Z')) virtual_joystick_values.z = constrain(parser.value_float(), -1.0f, 1.0f);
  }
}

#endif // JOYSTICK