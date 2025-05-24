# TextMAN - Modern Qt-based Text Editor

A feature-rich text editor built with Qt 5, offering a clean and intuitive interface for document editing.

## Features

### Document Management
- Create, open, and save text documents
- Automatic word and character counting
- Clean document interface

### Rich Text Formatting
- **Font Customization**
  - Font family selection via dropdown
  - Font size options (8pt to 24pt)
  - Text color picker
- **Text Styling**
  - Bold, Italic, Underline controls
  - Text alignment (Left, Center, Right)
  
### Modern UI Elements
- **Customized Dark Theme**
  - Dark menubar and toolbar (#2c3e50)
  - White text editing area
  - Status footer with statistics
- **Responsive Layout**
  - Window scales to 80% of screen size
  - Minimum window size: 800x600
  - Centered on launch

## Technical Details

### Architecture
```
src/
├── app/
│   ├── AppController.cpp     # Application lifecycle
│   └── DocumentManager.cpp   # Document handling
└── ui/
    ├── MainWindow.cpp        # Main application window
    ├── MenuBar.cpp          # File operations menu
    ├── Toolbar.cpp          # Formatting controls
    ├── TextArea.cpp         # Text editing widget
    └── Footer.cpp           # Status information
```

### Build Requirements
- Qt 5.5 or later
- CMake 3.16+
- C++14 compliant compiler

### Building from Source
```bash
mkdir build && cd build
cmake ..
cmake --build .
```

## Development

### Key Classes
- `AppController`: Main application controller
- `DocumentManager`: Handles file operations
- `MainWindow`: Core UI container
- `TextArea`: Custom QTextEdit implementation
- `Toolbar`: Text formatting controls

### Adding New Features
1. Define interface in relevant header under `include/`
2. Implement in corresponding source under `src/`
3. Connect to UI through signals/slots
4. Update CMakeLists.txt if adding new files

## License
This project is available under the MIT License.
