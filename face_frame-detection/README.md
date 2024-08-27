

PART-1
Create a simple gstreamer pipeline and run using gst-launch command line tool to read the mp4 video file, scale down the input to 640x640 resolution and write JPEG encoded frames.

PART-2

• Continuing the part 1 of the assignment, write a C++ application to read each JPEG frame one by one
• Use OpenCV’s pre-trained XML classifier for detecting faces from the image and crop it.
• Create a frame wise folder structure of cropped faces.


FACE-DETECTION-PROJECT

face-detection-project/
├── CMakeLists.txt
├── input.mp4
├── src/
│   ├── extract_frames.sh
│   ├── face_cropper.cpp
│   └── haarcascade_frontalface_alt.xml
├── frames/
│   └── output 1
└── build/
    ├── face_cropper
    ├── output 2

 PART-1 output has been stored in frames folder under root directory

 PART-2 output has been stored in cropped_faces folder under build directory



 STEPS INVOVLVED:

 Firstly we need to compile the face_cropper.cpp file via cmake by correctly linking with openCV and specify path for XML classifier and frames directory.
 This will create executable file for face_cropper
 
 Then we need to compile the sheel script to extract the frames from the mp4 videos. We nedd to execute ./extract_frames.sh which will store the frames images in frames directory.

 Then finally under build directory execute the ./face_cropper which will cretae frame wise images extracted from each frame.
 For each frame which has no images extracted , error will be printed.

 


