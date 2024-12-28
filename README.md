# Instructions for CMake

## UNIX:
1. If the build directory is not empty, remove all files from it.
2. Set the directory to the project root.
3. Initiate CMake with:
    ```sh
    cmake -B build
    ```
4. Build the project with:
    ```sh
    cmake --build build
    ```
5. Run the project with:
    ```sh
    ./build/CasinoPointerPalace
    ```

## WINDOWS:
1. If the build directory is not empty, remove all files from it.
2. Set the directory to the project root.
3. In case of using MinGW, set the path to the MinGW bin directory in the system PATH.
4. Make sure your MinGW is installed with the `mingw32-make` tool.
5. Initiate CMake with:
    ```sh
    cmake -B build -G "MinGW Makefiles"
    ```
6. Build the project with:
    ```sh
    cmake --build build --config Release
    ```
7. Run the project with:
    ```sh
    .\\build\\CasinoPointerPalace.exe
    ```

## Notes:
- The project is built in the `build` directory.
- Some functionallity is not final as the project is for educational purposes.

