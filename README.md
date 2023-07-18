##Video to ASCII Converter

This is a simple program written in C++ using the Qt framework and OpenCV library that converts a video into ASCII art and displays it in the console.

#Features

Choose a video file using QFileDialog.
Resize each frame to the desired size (80x40).
Convert each pixel to an ASCII character based on its RGB color.
Print the ASCII characters in the console, creating an ASCII art representation of the video.
Add a delay between frames for realistic video output.
#Requirements

To build and run this program, you will need the following installed on your system:

Qt framework
OpenCV library
#How to Use

Clone the repository or download the source code files.
Open the Video_to_ASCII.pro file in Qt Creator.
Build the project to generate the executable.
Run the executable.
A QFileDialog will appear to choose the video file you want to convert.
The video will be converted into ASCII art and displayed in the console.
To exit the program, close the console window or press Ctrl+C.
#Notes

The program resizes each frame of the video to fit an 80x40 grid of characters. For better results, consider adjusting the size or aspect ratio of the output.
The ASCII characters used for the conversion are "@%#*+=-:.", providing a dark to light gradation.
The video output may vary depending on the characteristics of the chosen video file.

#Acknowledgments

The program was created as an educational project to demonstrate the capabilities of the Qt framework and OpenCV library for working with videos and images in C++. It is not intended for commercial or production use.

Feel free to use, modify, and distribute this program for non-commercial purposes. If you find it helpful, I would appreciate giving credit by linking back to this repository.
