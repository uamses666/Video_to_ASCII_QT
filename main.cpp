#include <QApplication>
#include <QFileDialog>
#include <QTextStream>
#include <opencv2/opencv.hpp>
#include <thread>
#include <cmath>

// Function to convert RGB color to corresponding ASCII character
char rgbToASCII(int r, int g, int b) {
    int grayValue = std::round(0.2126 * r + 0.7152 * g + 0.0722 * b);
    const std::string asciiChars = "@%#*+=-:. ";
    int charIndex = std::round(grayValue / 255.0 * (asciiChars.size() - 1));
    return asciiChars[charIndex];
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Step 1: Choose the video file using QFileDialog
    QString filePath = QFileDialog::getOpenFileName(nullptr, "Select Video File", "", "Video Files (*.mp4 *.avi)");

    cv::VideoCapture video(filePath.toStdString());
    if (!video.isOpened()) {
        QTextStream(stdout) << "Error loading the video" << Qt::endl;
        return -1;
    }

    cv::Mat frame;
    while (video.read(frame)) {
        // Step 2: Resize the frame to the desired size
        cv::resize(frame, frame, cv::Size(80, 40));

        // Step 3: Convert each pixel to ASCII character
        std::string asciiFrame;
        for (int y = 0; y < frame.rows; ++y) {
            for (int x = 0; x < frame.cols; ++x) {
                cv::Vec3b pixel = frame.at<cv::Vec3b>(y, x);
                asciiFrame += rgbToASCII(pixel[2], pixel[1], pixel[0]);
            }
            asciiFrame += "\n";
        }

        // Step 4: Clear the console and print the ASCII characters with cursor movement to the beginning
        std::cout << "\033[2J\033[1;1H"; // Clear console and move cursor to the beginning
        std::cout << asciiFrame;

        // Step 5: Add a delay between frames for realistic video output
        std::this_thread::sleep_for(std::chrono::milliseconds(33)); // 33 ms = 30 frames per second
    }

    // Release the video and free resources
    video.release();

    return a.exec();
}
