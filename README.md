# TextMAN - Modern Qt-based Text Editor
<!-- ALL-CONTRIBUTORS-BADGE:START - Do not remove or modify this section -->
[![All Contributors](https://img.shields.io/badge/all_contributors-2-orange.svg?style=flat-square)](#contributors-)
<!-- ALL-CONTRIBUTORS-BADGE:END -->

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

## Contributors ✨

Thanks goes to these wonderful people ([emoji key](https://allcontributors.org/docs/en/emoji-key)):

<!-- ALL-CONTRIBUTORS-LIST:START - Do not remove or modify this section -->
<!-- prettier-ignore-start -->
<!-- markdownlint-disable -->
<table>
  <tbody>
    <tr>
      <td align="center" valign="top" width="14.28%"><a href="https://github.com/royalhub123"><img src="https://avatars.githubusercontent.com/u/168981505?v=4?s=100" width="100px;" alt="royalhub123"/><br /><sub><b>royalhub123</b></sub></a><br /><a href="https://github.com/Shailesh-Singh-Bisht/TextMAN-Text-Editor/commits?author=royalhub123" title="Code">💻</a></td>
      <td align="center" valign="top" width="14.28%"><a href="https://shailesh-singh-bisht-portfolio.vercel.app/"><img src="https://avatars.githubusercontent.com/u/107263955?v=4?s=100" width="100px;" alt="Shailesh Singh Bisht"/><br /><sub><b>Shailesh Singh Bisht</b></sub></a><br /><a href="#design-Shailesh-Singh-Bisht" title="Design">🎨</a> <a href="#maintenance-Shailesh-Singh-Bisht" title="Maintenance">🚧</a></td>
    </tr>
  </tbody>
  <tfoot>
    <tr>
      <td align="center" size="13px" colspan="7">
        <img src="https://raw.githubusercontent.com/all-contributors/all-contributors-cli/1b8533af435da9854653492b1327a23a4dbd0a10/assets/logo-small.svg">
          <a href="https://all-contributors.js.org/docs/en/bot/usage">Add your contributions</a>
        </img>
      </td>
    </tr>
  </tfoot>
</table>

<!-- markdownlint-restore -->
<!-- prettier-ignore-end -->

<!-- ALL-CONTRIBUTORS-LIST:END -->

This project follows the [all-contributors](https://github.com/all-contributors/all-contributors) specification. Contributions of any kind welcome!