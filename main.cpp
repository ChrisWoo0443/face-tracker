#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>

using namespace cv;
using namespace std;

int main() {
    VideoCapture cap(1);
    Mat img;

    //load haar cascade for frontal face
    CascadeClassifier faceCascade;
    faceCascade.load("Resources/haarcascade_frontalface_default.xml");

    if(faceCascade.empty()) {
        cout << "XML not properly loaded" << endl;
    }

    while(true) {
        cap.read(img);

        vector<Rect> faces;
        faceCascade.detectMultiScale(img, faces, 1.1, 10);

        //put rectangle with face label around face
        for(int i = 0; i < faces.size(); i++) {
            putText(img, "Face", {faces[i].x, faces[i].y-10}, FONT_HERSHEY_PLAIN, 2, Scalar(0,255,0), 1);
            rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
        }

        imshow("Webcam", img);

        //close video with esc key, ascii value of 27
        char escKey = (char) waitKey(1);
        if(escKey == 27) {
            break;
        }
    }
}
