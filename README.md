# Water Clock

Water Clock is a drawing machine that tells time by continuously redrawing an analog clock face using water instead of ink.

An XY pen plotter uses a water brush to draw onto reusable calligraphy practice paper that darkens when wet and gradually fades back to blank as it dries. The result is a functioning analog clock that constantly renews itself.

Unlike a conventional clock that preserves time through permanent marks or digital displays, Water Clock measures time through cycles of evaporation and repetition.

---

## Concept

Water Clock transforms timekeeping into a temporary drawing process.

Each minute, the machine redraws the clock face and current hands using only water. As earlier marks evaporate and the clock keeps time, the image slowly evolves.

The project references both traditional analog clocks and historical water clocks while replacing gears, batteries, and static displays with motion, moisture, and decay.

---

## How It Works

- A custom XY plotter moves a water brush across the page
- A XIAO ESP32 microcontroller controls motion and timing
- Limit switches allow the machine to home itself on startup
- A servo lifts and lowers the brush
- Every minute, the machine redraws:
  - clock perimeter
  - hour hand
  - minute hand
- The water marks fade naturally as the paper dries

---

## Materials

- XY pen plotter
- Seeed Studio XIAO ESP32
- Stepper motors + drivers
- Servo motor
- Limit switches
- Water brush
- Water calligraphy paper

---

## Why Water?

Water creates marks that are visible but temporary.

This allows the clock to function without accumulating history. Instead of leaving permanent traces, each drawing is erased by time itself.

The surface becomes both display and timer.

---

## Behavior

Because drying conditions vary, the clock changes with its environment.

Humidity, temperature, airflow, brush saturation, and paper condition all subtly affect how long marks remain visible. Time is therefore shown not only mechanically, but atmospherically.

---

## Software Features

- Manual time setting over serial
- Automatic homing sequence
- Repeating clock redraw cycle
- Adjustable clock size and position
- Configurable pen up/down servo positions

---

## Repository Contents

```text
.
├── .gitattributes
│   Git configuration file that normalizes text line endings across systems.
│
├── clockdrawing/
│   Earlier development folder for clock-drawing experiments.
│
│   ├── Cart.h
│   │   Header file for a differential-drive robot/cart motion class.
│   │   Declares movement, rotation, motor setup, reset, run, and completion-check functions.
│
│   ├── Cart.cpp
│   │   Implementation of the Cart motion class.
│   │   Converts movement/rotation commands into stepper motor motion using wheel radius,
│   │   axle length, microstepping, speed, and acceleration settings.
│
│   ├── Website.h
│   │   Embedded browser interface for building a list of move/rotate instructions.
│   │   Sends instructions to the microcontroller over a websocket connection.
│
│   ├── finalClockDraw/
│   │   Final standalone Water Clock firmware.
│   │
│   │   └── finalClockDraw.ino
│   │       Main project file.
│   │       Runs on the XIAO ESP32, homes the XY plotter, accepts the current time over Serial,
│   │       and draws an analog clock using a water brush on water calligraphy paper.
│   │       This version does not require Wi-Fi or websocket control.
│
│   └── __MACOSX/
│       └── ._clockdrawing.ino
│           macOS metadata file created during archive/export.
│           Not needed for the Arduino project.
│
└── drawing_machine_websocket/
    Earlier web-controlled XY plotter firmware.
    
    ├── drawing_machine_websocket.ino
    │   Firmware for controlling the XY drawing machine from a browser.
    │   The XIAO ESP32 creates a Wi-Fi access point, serves a webpage, receives websocket
    │   commands, homes with limit switches, moves to XY coordinates, and controls the pen servo.
    │
    └── html.h
        Embedded webpage used by drawing_machine_websocket.ino.
        Provides a draggable canvas interface plus buttons for homing, pen up, and pen down.
```


## Main File

The finished Water Clock firmware is located at:

```text
clockdrawing/finalClockDraw/finalClockDraw.ino
