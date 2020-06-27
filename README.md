# SpaceInvaders

## Getting started

**Tested on Visual Studio 2019 on Windows**

1. Clone the project.

        git clone https://github.com/Bojidarist/SpaceInvaders.git

2. Download the SDL2 Development Library for windows (Visual C++) from [here](https://www.libsdl.org/index.php).
3. Extract to a folder where you will not delete it.
4. Open the solution in Visual Studio, right click on the SIDesktop project and select properties.
5. Select the configuration you want (debug, x64...).
6. In C++ > General -> add the SDL2's include folder to "Additional Include Directories".
7. In Linker > General -> add the desired library found in SDL2/lib/(x64 or x86) to "Additional Library Directories".
8. In Linker > Input -> add SDL2.lib and SDL2main.lib to "Additional Dependencies".
9. From SDL2/lib/(x64 or x86) copy SDL2.dll and paste it in the SIDesktop folder.
10. Build and have fun!