/*  7-Segment Display Control
 *  
 *  File:       seven_segment_control.ino
 *  Version:    1.01
 *  Author:     Trey Harrison (CWID: 11368768)
 *  Email:      ntharrison@crimson.ua.edu
 *  Created:    08 February, 2016
 *  Modified:   12 February, 2016
 *  
 *  This is a useful function for controlling a 7-segment display tied
 *  to a single IO register in one of the arduino platforms.
 *  
 *  Copyright (C) 2016, Trey Harrison
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *  
 *  Source: <https://github.com/Attrit1on/useful_functions>
 *  
 */
 
void setup() {
  DDRC = 0xFF;
  // put your setup code here, to run once:
  // Display the value 12 on the 7-segment display in hex(0xC)
  PORTC = 0xFF;//sevenSegmentControl(8);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Do nothing
}

/* sevenSegmentControl(uint8_t displayVal)
 * Returns the byte needed in a register to represent displayVal on 
 * a seven segment display in hex wired with all segments to a single 
 * port as described in the table below.  This code was executed with 
 * the display wired to PORTC of the Arduino Mega platform.
 * 
 * The segment field corresponds to the segment of the display to be
 * controlled(segment map to right of table).  The port_bit refers 
 * to the bits in a single port of the arduino to be used.  In this  
 * case, the pin field corresponds to the appropriate pins needed to 
 * correctly utilize PORTC of the Arduino Mega platform.
 * 
 * ---THIS ONLY WORKS FOR COMMON CATHODE DISPLAYS---
 * 
 *   PORTC[0:6] => Digital Pins 37:31
 *   ---------------------------
 *   |segment    port_bit   pin|
 *   |   o          7       30 |     segments
 *   |   G          6       31 |     |--A--|
 *   |   F          5       32 |     F     B
 *   |   E          4       33 |     |--G--|
 *   |   D          3       34 |     E     C
 *   |   C          2       35 |     |--D--| o
 *   |   B          1       36 |
 *   |   A          0       37 |
 *   ---------------------------
 *
 */
uint8_t sevenSegmentControl(uint8_t displayVal) {
  switch (displayVal) {
    case 0:  return 0x3F; break;
    case 1:  return 0x06; break;
    case 2:  return 0x5B; break;
    case 3:  return 0x4F; break;
    case 4:  return 0x66; break;
    case 5:  return 0x6D; break;
    case 6:  return 0x7D; break;
    case 7:  return 0x07; break;
    case 8:  return 0x7F; break;
    case 9:  return 0x6F; break;
    case 10: return 0x77; break;
    case 11: return 0x7C; break;
    case 12: return 0x39; break;
    case 13: return 0x5E; break;
    case 14: return 0x79; break;
    case 15: return 0x71; break;
    case 20: return 0x80; break;
    case 30: return 0x49; break;
    default: return 0x00; break;
  }
}
