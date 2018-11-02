#include <videoprozessor.h>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

VideoProcessor::VideoProcessor(){

}

int VideoProcessor::startCamera(){

    VideoCapture cap(0);
    if(!cap.isOpened()){
        std::cout<<"Error capturing camera.";
        return -1;
    }
    while(true){
        Mat frame;
        cap >> frame;
        imshow("camera",getColorFromFrame(frame));
        if(waitKey(1) == 27){
            return 0;
        }
    }

}


cv::Mat VideoProcessor::getColorFromFrame(cv::Mat input){

    Mat output, hsvFrame;


    return output;
}
