# Cerberus-24 (Micromouse Project using RP2040)

This project involves the design and development of a micromouse robot using the RP2040 microcontroller. The system includes a custom 4-layer PCB design and utilizes 3D-printed components for the physical structure. The micromouse is tuned for efficient cell navigation in maze environments, employing various sensors and motors for precision control.

<div align="center">
  <figure>
    <img src="img/front1.jpeg" alt="Micromouse Side View" width="300"/>
    <figcaption><b>Micromouse Side View</b></figcaption>
  </figure>
  
  <figure>
    <img src="img/front.jpeg" width="300"/>
    <figcaption><b>Micromouse Front View</b></figcaption>
  </figure>
</div

## Key Features
- **Microcontroller**: RP2040
- **Sensors**: VL6180X Time-of-Flight (ToF) sensors (x5) for distance readings and integration with PID control.
- **Motors**: N20 motors equipped with encoders to provide precise feedback for movement control.
- **Motor Controller**: TB6612FNG to drive the motors efficiently.
- **Navigation**: The micromouse utilizes PID control for motor adjustments, relying on both encoder feedback and ToF sensor readings to maintain accurate movement and direction within the maze.
- **Custom Design**: Features a 4-layer PCB and 3D-printed parts to ensure a compact and optimized layout.

<div align="center">
  <figure>
    <img src="img/schematic.jpeg" alt="Micromouse Main Schematic" width="600"/>
    <figcaption><b>Micromouse Side View</b></figcaption>
  </figure>
  
  <figure>
    <img src="img/layers.jpeg" width="600"/>
    <figcaption><b>Micromouse 4- Layer PCB</b></figcaption>
  </figure>

  <figure>
    <img src="img/3dview.jpeg" width="600"/>
    <figcaption><b>Micromouse PCB 3D View</b></figcaption>
  </figure>

</div

## Highlights
- Tuned the micromouse for efficient cell-to-cell navigation, utilizing data from the VL6180X sensors and encoder feedback.
- Designed a stable and responsive PID control system that integrates data from both the ToF sensors and motor encoders.
- 3D-printed components were used to create a lightweight and durable chassis.
  
## Future Improvements
- Further optimization of the PID tuning for even more precise movement.
- Potential upgrades to the sensor array for enhanced environmental awareness.


