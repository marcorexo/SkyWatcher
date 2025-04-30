# SkyWatcher

A cross-platform motion detection and tracking system built with OpenFrameworks and OpenCV.

## Overview

SkyWatcher is a hobby project designed to detect and track moving objects using a webcam. The application processes video frames in real-time, identifies motion, and provides visual feedback by drawing bounding boxes around detected objects.

## Features

- **Real-time Motion Detection**: Processes webcam input to identify moving objects
- **Adjustable Sensitivity**: Customize detection thresholds to suit different environments
- **Object Tracking**: Draws bounding boxes around detected moving objects
- **Image Capture**: Automatically saves images when motion is detected
- **Cross-Platform**: Works on Windows, macOS, and Linux

## Technologies

- **C++**: Core programming language
- **OpenFrameworks**: Application framework for creative coding
- **OpenCV**: Computer vision library for image processing and motion detection
- **Webcam Integration**: Captures live video feed for processing

## Requirements

- OpenFrameworks 0.11.0 or later
- OpenCV 4.x
- C++ compiler (Visual Studio, Xcode, GCC, etc.)
- Webcam or camera device

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/marcorexo/SkyWatcher.git
   ```

2. Make sure you have OpenFrameworks installed on your system
   - Download from: [https://openframeworks.cc/download/](https://openframeworks.cc/download/)

3. Install OpenCV addon for OpenFrameworks:
   - Place in the `addons` folder of your OpenFrameworks installation

4. Open the project with your preferred IDE:
   - **Windows**: Use Visual Studio solution file
   - **macOS**: Use Xcode project file
   - **Linux**: Use the provided Makefile

5. Build and run the application

## Usage

1. Launch the SkyWatcher application
2. Adjust the sensitivity settings using the provided interface
3. Position the webcam to monitor the desired area
4. The application will automatically:
   - Detect motion in the camera's field of view
   - Draw bounding boxes around moving objects
   - Save images when motion is detected

## Configuration

SkyWatcher provides several adjustable parameters:

- **Detection Sensitivity**: Adjust how sensitive the motion detection is
- **Minimum Object Size**: Filter out motion detections below a certain size
- **Capture Frequency**: Control how often images are saved when motion is detected
- **Display Options**: Toggle visual elements like bounding boxes and motion trails

## Contributing

Contributions to SkyWatcher are welcome! Please feel free to submit pull requests, create issues, or suggest improvements.

1. Fork the repository
2. Create your feature branch: `git checkout -b feature/AmazingFeature`
3. Commit your changes: `git commit -m 'Add some AmazingFeature'`
4. Push to the branch: `git push origin feature/AmazingFeature`
5. Open a Pull Request

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments

- OpenFrameworks community for providing an excellent framework
- OpenCV developers for the powerful computer vision library

## Contact

Project Link: [https://github.com/marcorexo/SkyWatcher](https://github.com/marcorexo/SkyWatcher)
