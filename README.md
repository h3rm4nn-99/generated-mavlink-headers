# generated-mavlink-headers
The MAVLink library is usally generated when ArduPilot is built and "destroyed" when `waf clean` is executed. To avoid losing the customization, this repository contains the headers generated during the first compilation of ArduPilot after the merge of the new messages and it serves as a **snapshot**. All the customizations will be merged in this repo.

## How to use the headers
You'll need to copy this whole repository in the `/build/sitl/libraries/GCS_MAVLink/include/mavlink/v2.0` in the ArduPilot project after the build.

This repo will also be configured as a **submodule** in the qgroundcontrol project so it will be included automatically.
