# SimpleSafeTensorsParser
A simple safetensors file meta reader


## Build Instructions

To build the project using CMake, follow these steps:

1. **Install CMake**: Ensure that CMake is installed on your system. You can download it from [cmake.org](https://cmake.org/download/).

2. **Create a Build Directory**: It's a good practice to build the project in a separate directory to keep the source directory clean. Create a directory named `build` inside the project root:

    ```bash
    mkdir build
    cd build
    ```

3. **Generate Build Files**: Run CMake to generate the necessary build files. This will configure the project:

    ```bash
    cmake ..
    ```

4. **Compile the Project**: Use the generated build files to compile the project:

    ```bash
    cmake --build .
    ```

5. **Run the Executable**: After building the project, you can run the executable. For example:

    ```bash
    ./SafetensorsReader <path_to_safetensors_file>
    ```

Replace `<path_to_safetensors_file>` with the actual path to the safetensors file you want to read.
