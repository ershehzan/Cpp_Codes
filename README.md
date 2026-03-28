
# Cpp Code Collection

Welcome to **Cpp Code Collection**!  
This repository contains a collection of C programs designed to help you understand both fundamental and advanced concepts in C programming.  
Each program focuses on a specific topic, covering syntax, conditional statements, loops, functions, arrays, pointers, and more.

---

## 📂 Overview
This repository includes C programs covering various topics such as:

- Basic syntax and introductory programs
- Conditional statements and loops
- Arrays and searching techniques
- Number theory and mathematical computations
- Functions and recursion
- Pointers and memory management
- Sorting and searching algorithms
- File handling
- Advanced C features
- Patterns and miscellaneous concepts

Each program is designed to help understand key C concepts with practical examples and implementations.

---

## 🚀 Getting Started

1. **Clone this repository**:  
   ```bash
   git clone https://github.com/ershehzan/C-Code-s.git
   ```

2. **Navigate to the directory**:  
   ```bash
   cd C-Code-s
   ```

3. **Compile and run the programs**:  
   Use a C compiler like GCC to compile and execute the programs. Example:  
   ```bash
   gcc program-name.c -o program-name
   ./program-name
   ```

---

## 🌟 Features

- A comprehensive list of beginner to advanced-level C programs.  
- Well-commented code for easy understanding.  
- Covers a wide range of topics, from basic operations to advanced concepts like memory management and sorting algorithms.  
- Regularly updated with new programs and improvements.  

---

## 🤝 Contributions

Contributions are welcome! If you'd like to add more programs or improve existing ones, feel free to submit a pull request.

---

## 📜 License

This project is licensed under the [MIT License](LICENSE).

---

## 📧 Contact

For questions or suggestions, reach out to:  
- **GitHub**: ershehzan (https://github.com/ershehzan)

---

Happy Coding! 🎉

---

# 🎯 YOLOv8 Live Object Detection & Tracking

A real-time web application for object detection and tracking using YOLOv8 and Deep SORT algorithms. This application streams live webcam feed with detected objects, bounding boxes, confidence scores, and unique tracking IDs.

## ✨ Features

- **Real-time Object Detection**: Uses YOLOv8 (You Only Look Once) for fast and accurate object detection
- **Multi-Object Tracking**: Implements Deep SORT algorithm to track multiple objects with unique IDs
- **Live Video Streaming**: MJPEG streaming directly to web browser
- **Trajectory Visualization**: Shows movement paths of tracked objects
- **Web Interface**: Clean, responsive web interface with real-time controls
- **80+ Object Classes**: Supports all COCO dataset classes (person, car, bicycle, etc.)
- **Performance Monitoring**: Real-time statistics display

## 🏗️ Project Structure

```
yolo-v8-live-tracker/
├── app.py                 # Flask web application server
├── detect_and_track.py    # YOLOv8 + Deep SORT processing logic
├── requirements.txt       # Python dependencies
├── README.md             # This file
├── static/
│   └── style.css         # CSS styling for web interface
└── templates/
    ├── index.html        # Main web page template
    ├── 404.html          # 404 error page
    └── 500.html          # 500 error page
```

## 🚀 Installation & Setup

### Prerequisites

- Python 3.8 or higher
- Webcam/Camera connected to your computer
- Windows/Linux/macOS

### Step 1: Clone or Download

Download this project to your local machine or clone the repository.

### Step 2: Create Virtual Environment (Recommended)

```bash
# Create virtual environment
python -m venv venv

# Activate virtual environment
# On Windows:
venv\Scripts\activate
# On Linux/macOS:
source venv/bin/activate
```

### Step 3: Install Dependencies

```bash
pip install -r requirements.txt
```

**Note**: The first time you run the application, YOLOv8 will automatically download the model weights (~6MB for YOLOv8n).

### Step 4: Run the Application

```bash
python app.py
```

### Step 5: Open Web Browser

Navigate to: `http://localhost:5000`

## 🎮 Usage

1. **Start the Application**: Run `python app.py`
2. **Open Browser**: Go to `http://localhost:5000`
3. **Grant Camera Permission**: Allow browser to access your webcam
4. **View Live Detection**: See real-time object detection and tracking
5. **Control Interface**: Use the web interface buttons to start/stop detection

### Web Interface Controls

- **▶️ Start Detection**: Initialize camera and begin object detection
- **⏹️ Stop Detection**: Stop processing and release camera resources
- **🔄 Refresh Status**: Update connection and system status

## 🔧 Configuration

### Camera Settings

You can modify camera settings in `detect_and_track.py`:

```python
# Change camera index (0 for default, 1 for external camera, etc.)
detector.start_webcam(camera_index=0)

# Modify camera resolution and FPS
self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
self.cap.set(cv2.CAP_PROP_FPS, 30)
```

### Detection Settings

Adjust detection parameters in `detect_and_track.py`:

```python
# Change YOLOv8 model (yolov8n.pt, yolov8s.pt, yolov8m.pt, yolov8l.pt, yolov8x.pt)
detector = ObjectDetectorTracker(model_name='yolov8n.pt', confidence_threshold=0.5)

# Modify Deep SORT parameters
self.tracker = DeepSort(
    max_age=50,              # Frames to keep alive track without detections
    n_init=3,                # Detections needed before track confirmation
    nms_max_overlap=1.0,     # Non-maxima suppression threshold
    max_cosine_distance=0.4, # Cosine distance threshold for matching
)
```

## 📊 Supported Object Classes

The application can detect and track 80 different object classes from the COCO dataset:

- **People**: person
- **Vehicles**: bicycle, car, motorcycle, airplane, bus, train, truck, boat
- **Animals**: bird, cat, dog, horse, sheep, cow, elephant, bear, zebra, giraffe
- **Objects**: backpack, umbrella, handbag, tie, suitcase, frisbee, skis, snowboard, sports ball, kite, baseball bat, baseball glove, skateboard, surfboard, tennis racket
- **Food & Kitchen**: bottle, wine glass, cup, fork, knife, spoon, bowl, banana, apple, sandwich, orange, broccoli, carrot, hot dog, pizza, donut, cake
- **Furniture**: chair, couch, potted plant, bed, dining table, toilet
- **Electronics**: tv, laptop, mouse, remote, keyboard, cell phone, microwave, oven, toaster, sink, refrigerator
- **Other**: book, clock, vase, scissors, teddy bear, hair drier, toothbrush

## 🎨 Visual Features

### Bounding Boxes

- **Color-coded**: Each tracked object gets a unique color
- **Labels**: Show object class, confidence score, and track ID
- **Real-time**: Updated at 30 FPS for smooth tracking

### Trajectory Tracking

- **Movement Paths**: Colored lines showing object movement history
- **History Length**: Last 30 positions are displayed
- **Unique Colors**: Each track has its own color for easy identification

### Statistics Display

- **Object Count**: Number of currently detected objects
- **Active Tracks**: Number of confirmed tracking targets
- **Real-time Updates**: Statistics update with each frame

## 🛠️ Troubleshooting

### Common Issues

**Camera not working:**

- Ensure no other applications are using the camera
- Try different camera indices (0, 1, 2, etc.)
- Check camera permissions in your operating system

**Slow performance:**

- Use a smaller YOLOv8 model (yolov8n.pt instead of yolov8x.pt)
- Reduce camera resolution in the code
- Close other resource-intensive applications

**Module import errors:**

- Ensure all dependencies are installed: `pip install -r requirements.txt`
- Check Python version compatibility (3.8+)
- Try reinstalling PyTorch: `pip install torch torchvision --force-reinstall`

**Web page not loading:**

- Check if Flask server is running on port 5000
- Try accessing `http://127.0.0.1:5000` instead
- Check firewall settings

### Performance Optimization

1. **Model Selection**: Use appropriate YOLOv8 model for your hardware

   - `yolov8n.pt`: Fastest, lowest accuracy
   - `yolov8s.pt`: Balanced speed/accuracy
   - `yolov8m.pt`: Better accuracy, slower
   - `yolov8l.pt`: High accuracy, slow
   - `yolov8x.pt`: Best accuracy, slowest

2. **Hardware Acceleration**: If you have a CUDA-compatible GPU, PyTorch will automatically use it for faster inference.

3. **Camera Resolution**: Lower resolutions will process faster but may reduce detection accuracy.

## 🔒 Security Notes

- The application runs a web server accessible on your local network
- By default, it binds to `0.0.0.0:5000` (all interfaces)
- For production use, implement proper authentication and HTTPS
- Consider firewall rules if running on a shared network

## 📝 Technical Details

### Architecture

1. **Flask Server** (`app.py`): Handles web requests, streaming, and API endpoints
2. **Detection Engine** (`detect_and_track.py`): Processes video frames with YOLOv8 and Deep SORT
3. **Threading**: Separate threads for video processing and web serving
4. **MJPEG Streaming**: Efficient video streaming to web browsers

### Dependencies

- **Flask**: Web framework for the server
- **Ultralytics**: YOLOv8 implementation
- **OpenCV**: Computer vision and camera access
- **Deep SORT**: Multi-object tracking algorithm
- **NumPy**: Numerical computations
- **PyTorch**: Deep learning framework

### Performance Characteristics

- **Frame Rate**: ~30 FPS on modern hardware
- **Latency**: <100ms from camera to web display
- **Memory Usage**: ~500MB-1GB depending on model size
- **CPU Usage**: Moderate (can utilize GPU if available)

## 🤝 Contributing

Feel free to submit issues, feature requests, or pull requests to improve this application.

## 📄 License

This project is for educational and research purposes. Please respect the licenses of the underlying libraries (YOLOv8, Deep SORT, etc.).

## 🙏 Acknowledgments

- **Ultralytics**: For the excellent YOLOv8 implementation
- **Deep SORT**: For the multi-object tracking algorithm
- **OpenCV**: For computer vision capabilities
- **Flask**: For the web framework

---

**Happy Object Tracking! 🎯**
