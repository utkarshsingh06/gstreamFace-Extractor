#include <opencv2/opencv.hpp>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

void processFrame(const std::string &frameFile, int frameNumber, cv::CascadeClassifier &face_cascade) {
    // Load the frame
    cv::Mat frame = cv::imread(frameFile);
    if (frame.empty()) {
        std::cerr << "Error loading frame: " << frameFile << std::endl;
        return;
    }

    // Detect faces
    std::vector<cv::Rect> faces;
    face_cascade.detectMultiScale(frame, faces, 1.1, 4, 0, cv::Size(30, 30));

    if (faces.empty()) {
        std::cout << "No faces detected in frame " << frameNumber << std::endl;
        return;
    }

    // Create directory for the current frame
    std::string frameDir = "cropped_faces/frame_" + std::to_string(frameNumber);
    if (!fs::exists(frameDir)) {
        fs::create_directories(frameDir);  // Creates directory, including any intermediate directories
    }  // Creates directory, including any intermediate directories

    // Crop and save faces
    for (size_t i = 0; i < faces.size(); ++i) {
        cv::Mat faceROI = frame(faces[i]);
        std::string faceFilename = frameDir + "/face_" + std::to_string(i + 1) + ".jpg";
        cv::imwrite(faceFilename, faceROI);
        std::cout << "Saved face image: " << faceFilename << std::endl;
    }
}

int main() {
    // Load the face cascade classifier
    cv::CascadeClassifier face_cascade;
    if (!face_cascade.load("../src/haarcascade_frontalface_alt.xml")) {
        std::cerr << "Error loading face cascade classifier!" << std::endl;
        return -1;
    }

    // Process each frame
    int frameNumber = 0;
    while (true) {
        std::ostringstream framePath;
        framePath << "../frames/frame_" << std::setw(3) << std::setfill('0') << frameNumber << ".jpg";
        std::string frameFile = framePath.str();
        if (!fs::exists(frameFile)) {
            break; // Stop if the frame doesn't exist
        }

        processFrame(frameFile, frameNumber, face_cascade);
        frameNumber++;
    }

    std::cout << "Processing complete. Check the cropped_faces directory for results." << std::endl;

    return 0;
}

