#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>

using namespace cv;
using namespace std;

int main() {
    string path = "Resources/lambo.png";
    Mat img = imread(path);

    imshow("Lambo", img);
    waitKey(0);
}
