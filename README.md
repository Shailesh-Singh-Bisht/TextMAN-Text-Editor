# TextMAN - Modern Qt-based Text Editor

A **lightweight and efficient text editor** built with Qt 5, offering a clean and intuitive interface for document editing on Windows.

-----

## Features

### Document Management

  * Create, open, and save text documents.
  * **Automatic word and character counting** that updates in real-time.
  * Clean, single-page document interface with a white background and a **10,000-word limit**.

### Rich Text Formatting

  * **Font Customization**:
      * Font family selection via dropdown.
      * Font size options (8pt to 24pt).
      * Text color picker.
  * **Text Styling**:
      * Bold, Italic, Underline controls.
      * Text alignment (Left, Center, Right).

### Modern UI Elements

  * **Visual Theme**:
      * Dark menubar and toolbar (`#2c3e50`).
      * White text editing area.
      * Sticky status footer with real-time statistics.
  * **Responsive Layout**:
      * Window scales to 80% of screen size.
      * Minimum window size: 800x600.
      * Centered on launch.
  * The Menubar and Toolbar remain visible while scrolling through the text area.

-----

## How to Run TextMAN

To get started with TextMAN, simply:

1.  **Download the latest release ZIP** from the [releases page]()
2.  **Extract the contents** of the downloaded ZIP file to your preferred location on your system.
3.  Navigate into the extracted folder and **run `TextMAN.exe`**. The application should launch directly.

-----

## Technical Details

### Architecture

```
src/
├── app/
│   ├── AppController.cpp       # Application lifecycle management
│   └── DocumentManager.cpp     # Handles file operations (create, open, save)
└── ui/
    ├── MainWindow.cpp          # Main application window and UI component organization
    ├── MenuBar.cpp             # Implements file-related actions in the menu bar
    ├── Toolbar.cpp             # Provides text formatting and alignment options
    ├── TextArea.cpp            # Offers rich text editing functionality with scrolling
    └── Footer.cpp              # Displays real-time word and character counts
```

### Build Requirements

  * Qt 5.5 or later
  * CMake 3.16+
  * C++14 compliant compiler

### Building from Source

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

-----

## Development

### Key Classes

  * `AppController`: The central application controller, managing initialization and signal/slot connections.
  * `DocumentManager`: Manages all document-related operations, including file creation, opening, and saving.
  * `MainWindow`: The primary UI container, organizing and hosting all other visual components.
  * `TextArea`: A custom `QTextEdit` implementation providing rich text editing features.
  * `Toolbar`: Handles all text formatting and alignment controls.

### Adding New Features

1.  **Define the interface** for the new feature in the relevant header file under `include/`.
2.  **Implement the functionality** in the corresponding source file under `src/`.
3.  **Connect the new feature to the UI** using Qt's signal and slot mechanism.
4.  **Update `CMakeLists.txt`** if you've added new files or dependencies.

-----

## License

This project is available under the MIT License.
