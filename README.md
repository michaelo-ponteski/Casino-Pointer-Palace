```markdown
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
    cmake --build build --config Release
    ```
6. Run the project with:
    ```sh
    ./build/CasinoPointerPalace.exe
    ```
```
