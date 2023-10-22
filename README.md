## VCMP-CMake: A step forward automating plugin development for [VC:MP](https://vc-mp.org/). Powered to you by [CMAKE](https://cmake.org/cmake/help/latest/)!

![](2023-10-22 09-09-37.mp4)

A plug & play template which automatically helps you get started with the VC:MP SDK.

When it finishes building, it moves the plugin into `server/plugins` and automatically loads the plugin! Simply type `cmake . && make` on the root directory, no need for making a *build* folder

Currently, it is kinda buggy

| Features | Status |
| - | - |
| server.cfg|✔️|
| Linux works and VS2022 works too but it won't show the server on the Output monitor|⚠️|
| basic example code w/ plugin sdk|✔️|
| rename the library if in Debug or Release|✔️|
| server binaries in the `server` folder|✔️|
| architecture check |✔️|

