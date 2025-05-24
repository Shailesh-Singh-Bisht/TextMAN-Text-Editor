# TextMAN - Modern Qt-based Text Editor
<!-- ALL-CONTRIBUTORS-BADGE:START - Do not remove or modify this section -->
[![All Contributors](https://img.shields.io/badge/all_contributors-4-orange.svg?style=flat-square)](#contributors-)
<!-- ALL-CONTRIBUTORS-BADGE:END -->

A **lightweight and efficient text editor** built with Qt 5, offering a clean and intuitive interface for document editing on Windows.

-----

## Features

### Document Management

  * Create, open, and save text documents.
  * **Automatic word and character counting** that updates in real-time.
  * Clean, single-page document interface with a white background.

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
    git clone https://github.com/Shailesh-Singh-Bisht/TextMAN-Text-Editor.git
    cd TextMan
    mkdir build
    cd build
    cmake .. -G "MinGW Makefiles" 
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
      <td align="center" valign="top" width="14.28%"><a href="https://github.com/Akhilnautiyal5"><img src="https://avatars.githubusercontent.com/u/113812781?v=4?s=100" width="100px;" alt="Akhil Nautiyal"/><br /><sub><b>Akhil Nautiyal</b></sub></a><br /><a href="https://github.com/Shailesh-Singh-Bisht/TextMAN-Text-Editor/commits?author=Akhilnautiyal5" title="Code">💻</a></td>
      <td align="center" valign="top" width="14.28%"><a href="https://github.com/Vivek-Pokhriyal"><img src="https://avatars.githubusercontent.com/u/202429019?v=4?s=100" width="100px;" alt="Vivek-Pokhriyal"/><br /><sub><b>Vivek-Pokhriyal</b></sub></a><br /><a href="https://github.com/Shailesh-Singh-Bisht/TextMAN-Text-Editor/commits?author=Vivek-Pokhriyal" title="Code">💻</a> <a href="https://github.com/Shailesh-Singh-Bisht/TextMAN-Text-Editor/pulls?q=is%3Apr+reviewed-by%3AVivek-Pokhriyal" title="Reviewed Pull Requests">👀</a> <a href="https://github.com/Shailesh-Singh-Bisht/TextMAN-Text-Editor/commits?author=Vivek-Pokhriyal" title="Tests">⚠️</a></td>
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

## How to Contribute

We welcome contributions of all kinds! Here's how you can help make TextMAN even better:

### Getting Started
1. Fork the repository
2. Clone your fork: `git clone https://github.com/Shailesh-Singh-Bisht/TextMAN-Text-Editor.git`
3. Create a new branch: `git checkout -b feature/your-feature-name`

### Making Changes
1. Make your changes in the appropriate files
2. Follow the project's coding style and conventions
3. Add tests if applicable
4. Update documentation as needed
5. Ensure all tests pass by building the project

### Submitting Changes
1. Commit your changes: `git commit -m "Add your descriptive commit message"`
2. Push to your fork: `git push origin feature/your-feature-name`
3. Open a Pull Request from your fork to our main repository

### Areas Where You Can Contribute
- 🐛 Bug fixes
- ✨ New features
- 📚 Documentation improvements
- 🎨 UI/UX enhancements
- 🧪 Test coverage
- 🌐 Internationalization

### Development Environment Setup
1. Ensure you have all [Build Requirements](#build-requirements)
2. Follow the [Building from Source](#building-from-source) instructions
3. For development, we recommend using Qt Creator or Visual Studio with Qt extension

### Need Help?
- Open an issue for bugs or feature requests
- Join our discussions for questions
- Check existing issues and pull requests before creating new ones

Your contributions help make TextMAN better for everyone! Thank you for being part of our community. 💖
