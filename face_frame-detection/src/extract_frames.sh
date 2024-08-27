#!/bin/bash

# Set variables
GST_BIN=/usr/bin
INPUT_FILE=/home/bladerunner/face-detection-project/input.mp4
OUTPUT_DIR=/home/bladerunner/face-detection-project/frames
mkdir -p $OUTPUT_DIR

$GST_BIN/gst-launch-1.0 filesrc location=$INPUT_FILE ! decodebin ! videoscale ! video/x-raw,width=640,height=640 ! jpegenc ! multifilesink location=$OUTPUT_DIR/frame_%03d.jpg




