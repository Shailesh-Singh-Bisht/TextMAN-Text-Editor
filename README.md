<<<<<<< HEAD
# TextMAN - Lightweight Text Editor for MiniOS

![TextMAN Logo](D:\MiniOS TextMan\TextMan\icons\app_logo.ico)

TextMAN is a lightweight, feature-rich text editor designed specifically for MiniOS. Built with Qt 5.5, it offers a clean interface with essential text editing capabilities while maintaining compatibility with ReactOS.

## Features

- **File Operations**:
  - Create new documents
  - Open existing `.txt` files
  - Save documents

- **Text Formatting**:
  - Font size selection
  - Text color customization
  - Bold, italic, and underline styling
  - Text alignment (left, center, right)

- **User Interface**:
  - Sticky menu bar and toolbar
  - Scrollable text area with white background
  - Status footer with word and character count

- **Additional Tools**:
  - Hard word limit of 10,000 words

## System Requirements

- Windows or ReactOS system
- Qt 5.5 runtime libraries (included in package)
- 4GB RAM recommended

## Installation

1. Download the TextMAN package
2. Extract the contents to your preferred location
3. The application requires no additional installation - simply run `TextMAN.exe`

## Included Files

```
TextMAN/
├── TextMAN.exe            # Main executable
├── assets/                # Application assets
│   └── icons/             # Application icons
├── platforms/             # Qt platform plugins
├── *.dll                  # Required DLL files
└── README.md              # This documentation
```

## Usage

1. Launch `TextMAN.exe`
2. Use the menu bar for file operations:
   - **New**: Create a new document
   - **Open**: Open an existing text file
   - **Save**: Save the current document

3. Format text using the toolbar options:
   - Change font size and color
   - Apply bold, italic, or underline styling
   - Adjust text alignment

4. The footer displays real-time word and character counts

## Building from Source

If you want to build TextMAN yourself, you'll need:

- MSYS2 with MinGW-w64
- Qt 5.5 development libraries
- CMake 3.13.5 or later

Build instructions:
```bash
mkdir build
cd build
cmake -G "Ninja" ..
ninja
```

## Deployment

After building, use `windeployqt` to package required Qt libraries:
```bash
windeployqt TextMAN.exe
```

## Known Issues

- Limited to plain text editing
- Maximum document size of 10,000 words
- Shape tools are basic and limited

## License

TextMAN is released under the [MIT License](LICENSE).

## Support

For issues or feature requests, please contact the MiniOS development team.

---
=======
# MiniOs-PBL
>>>>>>> 932a1eecf986931ce3b5bfd1ed0f9d956e08d979
