# GIA-CS2

A C++ project for implementing a Dear ImGui overlay menu within Counter-Strike 2 (`cs2.exe`) by hooking the game's DirectX 11 rendering process.

This repository serves as a starting point and educational resource for those interested in game-to-engine interaction, D3D11 hooking, and runtime UI rendering.

## Features

* **DirectX 11 Hooking**: Hooks the `Present` function of the game's swap chain to render a custom UI.
* **Dear ImGui Integration**: Pre-configured Dear ImGui backend for Win32 and DirectX 11.
* **Toggleable Menu**: A simple, clean menu that can be opened and closed with a hotkey (e.g., `INSERT`).
* **DLL-Based**: Designed to be compiled as a Dynamic-Link Library (`.dll`) for injection.
* **Clean & Modern C++**: Uses modern C++ practices for readability and maintainability.

## Getting Started

### Prerequisites

To compile this project, you will need:

* **Microsoft Visual Studio 2022** (or 2019) with the "Desktop development with C++" workload.
* **DirectX SDK**: The project links against DirectX 11 libraries (`d3d11.lib`, `dxgi.lib`). This is typically included with the Windows SDK, which comes with Visual Studio.

### Project Setup

1.  **Clone the Repository:**
    ```sh
    git clone [https://github.com/YourUsername/YourRepositoryName.git](https://github.com/YourUsername/YourRepositoryName.git)
    cd YourRepositoryName
    ```

2.  **Open in Visual Studio:**
    * Open the `.sln` (Solution) file in Visual Studio.

3.  **Configure Build Settings:**
    * Ensure your build configuration is set to **Release** and **x64**. CS2 is a 64-bit application.
    * The project should already be configured to compile as a `.dll`.

4.  **Include Dependencies:**
    * This project includes `Dear ImGui` and a hooking library (e.g., `MinHook`) as submodules or directly within the `/lib` folder.
    * If you need to link them manually, right-click the project, go to `Properties`, and ensure the following paths are correct:
        * **C/C++ > General > Additional Include Directories**: Add paths to your `ImGui` and `MinHook` header files.
        * **Linker > General > Additional Library Directories**: Add the path to the `MinHook` library file (e.g., `libMinHook.x64.lib`).

5.  **Build the Project:**
    * From the top menu, select **Build > Build Solution**.
    * This will generate the `YourProjectName.dll` file in the `build/` or `Release_x64/` directory.

## Usage

This project compiles to a DLL, which must be loaded into the target process (`cs2.exe`) to function.

1.  Launch Counter-Strike 2.
2.  Use a DLL injector to inject the compiled `.dll` into the `cs2.exe` process.
3.  Once injected, the menu should be available. Press the **`INSERT`** key (or your designated hotkey) to toggle its visibility.

**Note:** The default hotkey is defined in `main.cpp`. You can change `VK_INSERT` to any other virtual key code.

## Project Structure

## ⚠️ Disclaimer

This project is intended strictly for **educational and research purposes**. The techniques demonstrated here (DLL injection, function hooking) can be used to interfere with the normal operation of software.

**I do not condone the use of this software to violate the terms of service of any game, including Counter-Strike 2.** Using this code in a live, protected game environment may result in an account ban. You are solely responsible for your actions.

## Contributing

Contributions are welcome! If you have improvements, please feel free to fork the repository and submit a pull request.

1.  Fork the Project
2.  Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3.  Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4.  Push to the Branch (`git push origin feature/AmazingFeature`)
5.  Open a Pull Request

## License

This project is distributed under the MIT License. See `LICENSE.txt` for more information.

## Acknowledgments

* [Dear ImGui](https://github.com/ocornut/imgui)
* [MinHook](https://github.com/TsudaKageyu/minhook)
