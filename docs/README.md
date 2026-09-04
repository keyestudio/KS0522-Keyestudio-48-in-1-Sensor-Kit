# Keyestudio 48-in-1 Sensor Kit — Individual Lessons

This package splits the repaired Keyestudio KS0522 guide into **48 independent Markdown lessons**, one project per file. Start with the course overview, then open the lessons in numerical order. All local images use relative paths and work offline as long as the `media/` directory remains beside the Markdown files.

> **Safety note:** Disconnect power before changing wires. The relay lesson should be used with low-voltage loads only unless you have appropriate mains isolation, enclosure, and electrical-safety experience.

## Course Index

| Lesson | Topic | Markdown file |
| --- | --- | --- |
| 00 | Course overview, board specification, installation, and library requirements | [00-course-overview-and-setup.md](00-course-overview-and-setup.md) |
| 01 | White LED | [Open lesson](lessons/lesson-01-white-led.md) |
| 02 | RGB LED | [Open lesson](lessons/lesson-02-rgb-led.md) |
| 03 | 3W LED | [Open lesson](lessons/lesson-03-3w-led.md) |
| 04 | Traffic Light | [Open lesson](lessons/lesson-04-traffic-light.md) |
| 05 | Buzzer Beeps | [Open lesson](lessons/lesson-05-buzzer-beeps.md) |
| 06 | Passive Buzzer | [Open lesson](lessons/lesson-06-passive-buzzer.md) |
| 07 | Digital Push Button | [Open lesson](lessons/lesson-07-digital-push-button.md) |
| 08 | Collision Flash | [Open lesson](lessons/lesson-08-collision-flash.md) |
| 09 | Line -tracking Sensor | [Open lesson](lessons/lesson-09-line-tracking-sensor.md) |
| 10 | Infrared Obstacle Avoidance | [Open lesson](lessons/lesson-10-infrared-obstacle-avoidance.md) |
| 11 | Photo Interrupter | [Open lesson](lessons/lesson-11-photo-interrupter.md) |
| 12 | Hall Magnetic Sensor | [Open lesson](lessons/lesson-12-hall-magnetic-sensor.md) |
| 13 | Knock Sensor | [Open lesson](lessons/lesson-13-knock-sensor.md) |
| 14 | Digital Tilt Switch | [Open lesson](lessons/lesson-14-digital-tilt-switch.md) |
| 15 | Capacitive Touch | [Open lesson](lessons/lesson-15-capacitive-touch.md) |
| 16 | Flame Alarm | [Open lesson](lessons/lesson-16-flame-alarm.md) |
| 17 | Reed Switch | [Open lesson](lessons/lesson-17-reed-switch.md) |
| 18 | PIR Motion Sensor | [Open lesson](lessons/lesson-18-pir-motion-sensor.md) |
| 19 | Analog Temperature | [Open lesson](lessons/lesson-19-analog-temperature.md) |
| 20 | Analog Rotation | [Open lesson](lessons/lesson-20-analog-rotation.md) |
| 21 | Photocell | [Open lesson](lessons/lesson-21-photocell.md) |
| 22 | Analog Sound | [Open lesson](lessons/lesson-22-analog-sound.md) |
| 23 | Water Level | [Open lesson](lessons/lesson-23-water-level.md) |
| 24 | Soil Moisture | [Open lesson](lessons/lesson-24-soil-moisture.md) |
| 25 | Analog Gas | [Open lesson](lessons/lesson-25-analog-gas.md) |
| 26 | Analog Alcohol | [Open lesson](lessons/lesson-26-analog-alcohol.md) |
| 27 | Steam Sensor | [Open lesson](lessons/lesson-27-steam-sensor.md) |
| 28 | Analog Ceramic Vibration | [Open lesson](lessons/lesson-28-analog-ceramic-vibration.md) |
| 29 | Voltage Detection | [Open lesson](lessons/lesson-29-voltage-detection.md) |
| 30 | Pressure Detection | [Open lesson](lessons/lesson-30-pressure-detection.md) |
| 31 | Ambient Light | [Open lesson](lessons/lesson-31-ambient-light.md) |
| 32 | Ultraviolet Light | [Open lesson](lessons/lesson-32-ultraviolet-light.md) |
| 33 | Digital IR Receiver | [Open lesson](lessons/lesson-33-digital-ir-receiver.md) |
| 34 | Digital IR Transmitter | [Open lesson](lessons/lesson-34-digital-ir-transmitter.md) |
| 35 | Pulse Rate Monitor | [Open lesson](lessons/lesson-35-pulse-rate-monitor.md) |
| 36 | Joystick | [Open lesson](lessons/lesson-36-joystick.md) |
| 37 | Rotary Encoder | [Open lesson](lessons/lesson-37-rotary-encoder.md) |
| 38 | Single Relay | [Open lesson](lessons/lesson-38-single-relay.md) |
| 39 | Linear Temperature | [Open lesson](lessons/lesson-39-linear-temperature.md) |
| 40 | Temperature and Humidity Display | [Open lesson](lessons/lesson-40-temperature-and-humidity-display.md) |
| 41 | Magical Light Cup | [Open lesson](lessons/lesson-41-magical-light-cup.md) |
| 42 | Attitude Sensor | [Open lesson](lessons/lesson-42-attitude-sensor.md) |
| 43 | Optical Proximity Detection | [Open lesson](lessons/lesson-43-optical-proximity-detection.md) |
| 44 | Triaxial Digital Acceleration Detection | [Open lesson](lessons/lesson-44-triaxial-digital-acceleration-detection.md) |
| 45 | Micro Servo | [Open lesson](lessons/lesson-45-micro-servo.md) |
| 46 | Ultrasonic Ranger | [Open lesson](lessons/lesson-46-ultrasonic-ranger.md) |
| 47 | LCD Display | [Open lesson](lessons/lesson-47-lcd-display.md) |
| 48 | Dot Matrix | [Open lesson](lessons/lesson-48-dot-matrix.md) |

## Course Resources

The original manufacturer legacy libraries used by the advanced sensor examples are in `Resources/02. libraries/`. Each lesson identifies its required library. In the Arduino IDE, select **Arduino Uno** for the Keyestudio V4.0 board unless a project explicitly requires another target.

## Package Contents

| Item | Purpose |
| --- | --- |
| `00-course-overview-and-setup.md` | Shared setup and component reference. |
| `lessons/` | 48 individual Markdown lessons. |
| `media/` | Repaired offline image assets referenced by the lessons. |
| `Resources/` | Legacy Arduino libraries provided by the manufacturer. |
| `.markdownlint-cli2.yaml` | Markdown validation configuration. |

The lesson content is based on the optimized guide and keeps the code corrections, library notes, hardware compatibility warnings, and repaired media references described in `KS0522_review_report.md` from the optimized package.
