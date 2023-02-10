.. _capsense-sample:

CAPSENSE Buttons and Slider
######

Overview
********

This code example features a 5-segment CAPSENSE&trade; slider and two CAPSENSE&trade; buttons.
Button 0 turns the LED ON, button 1 turns the LED OFF, and the slider controls the brightness of the LED.
The code example also demonstrates monitoring CAPSENSE&trade; data using the CAPSENSE&trade; tuner GUI tool.
This project uses the `CAPSENSE&trade; Middleware Library <https://github.com/Infineon/capsense>`.

Requirements
************

The board hardware must have CAPSENSE buttons and leanier slider connected via a GPIO pin.
This sample is intended to be used with `CY8CPROTO-062-4343W PSoC&trade; 6 Wi-Fi Bluetooth® prototyping kit <https://www.cypress.com/CY8CPROTO-062-4343W>`.

Building and Running
********************

In this example we will build it for the cy8cproto_062_4343w board:

.. zephyr-app-commands::
   :zephyr-app: samples/basic/capsense
   :board: cy8cproto_062_4343w
   :goals: build
   :compact:

1. After programming, the application starts automatically. Confirm that the user LED is glowing.

2. To test the application, touch CAPSENSE&trade; button 1 (BTN1) to turn the LED OFF, touch CAPSENSE&trade; Button 0 (BTN0) to turn the LED ON, and touch the slider in different positions to change the brightness.

5. You can also monitor the CAPSENSE&trade; data using the CAPSENSE&trade; Tuner application.
