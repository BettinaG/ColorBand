#include <videoprozessor.h>
#include <opencv2/opencv.hpp>
#include <vector>
#include <QDebug>

using namespace cv;
using namespace std;

VideoProcessor::VideoProcessor(){

}

int VideoProcessor::startCamera(){

    VideoCapture cap(0);
    if(!cap.isOpened()){
        cout<<"Error capturing camera.";
        return -1;
    }
    while(true){
        Mat frame;
        cap >> frame;

       redResult = getColoredAreas(frame, red);
       blueResult = getColoredAreas(frame, blue);
       greenResult = getColoredAreas(frame, green);

       vector<int> results = getDominantColor(redResult, blueResult, greenResult, 3);

       qDebug() << results[3];
        qDebug() << results[1];
         qDebug() << results[2];
        frame = getColorFromFrame(frame, results[3]);
        frame = getCleanArea(frame);

        imshow("camera",frame);
        if(waitKey(1) == 27){
            return 0;
        }
    }
}


int VideoProcessor::showTestImage(){
    Mat image;
        image = imread("../testDot.png", CV_LOAD_IMAGE_COLOR);

    if (!image.data){
        cout << "Could not open or find the image" << std::endl;
        return -1;
    }

        // Create a new matrix to hold the HSV image
            Mat HSV, output;

        // convert RGB image to HSV
            cvtColor(image, HSV, CV_BGR2HSV);

            namedWindow("Display window", CV_WINDOW_AUTOSIZE);
            imshow("Display window", image);


//            inRange(HSV,getLowerBorder(blue), getUpperBorder(blue), output);

            inRange(HSV, getLowerBorder(red), getUpperBorder(red), output);


            imshow("Result window", output);

            waitKey(0);
            return 0;

}

std::vector<int> VideoProcessor::getColoredAreas(cv::Mat input, int color){

    vector<int> output(4);
    output[3] = color;                                          //last entry = color

    Mat hsv;
    cvtColor(input, hsv, CV_BGR2HSV);

    Mat coloredArea(input.rows, input.cols, CV_8UC1);

    // FIND ALL COLORED AREAS (input color)

    inRange(hsv, getLowerBorder(color), getUpperBorder(color), coloredArea);

    //FIND BIGGEST AREA

    vector<vector<Point>> contours;
    findContours(coloredArea, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

    int maxArea = 0;
    int maxAreaIndex = 0;
    for(int i = 0; i < contours.size(); i++){
        vector<Point> contour = contours[i];
        int area = contourArea(contour);
        if(maxArea < area){
            maxArea = area;
            maxAreaIndex = i;
        }
    }

    // CHECK FOR MINIMUM SIZE

    if(maxArea > 10000){
        Moments m = moments(coloredArea,true);
        Point centerOfMass(m.m10/m.m00, m.m01/m.m00);

        output[0] = maxArea;
        output[1] = centerOfMass.x;
        output[2] = centerOfMass.y;

        return output;

    }
    else {
        for(int i = 0; i < 3; i++){
            output[i] = 0;
        }
        return output;
    }

}

std::vector<int> VideoProcessor::getDominantColor(vector<int> red, vector<int> blue, vector<int> green, int amountOfElements){

    vector<vector<int>> inputVecs(amountOfElements);

    inputVecs[0] = red;
    inputVecs[1] = blue;
    inputVecs[2] = green;

    vector<int> results(4);
    results[0] = 0;

    //FIND COLOR WITH LARGEST AREA

    for(int i = 0; i< amountOfElements; i++){
        if((inputVecs[i])[0] > results[0]){             //if inputVec[i] has biggest area
            for(int j = 0; j < 3; j++){                 //copy to results
                results = inputVecs[i];
            }
        }
    }

    return results;
}


cv::Mat VideoProcessor::getColorFromFrame(cv::Mat input, int color){


    Mat hsv;

    cvtColor(input, hsv, CV_BGR2HSV);

     Mat coloredArea(input.rows, input.cols, CV_8UC1);

     Mat output(input.rows, input.cols, CV_8UC1);

    inRange(hsv, getLowerBorder(color), getUpperBorder(color), coloredArea);


    //cvtColor(blueArea, blueArea2, CV_HSV2BGR);

    //absdiff(blueArea2, input, blueArea2);

    //target = cv2.bitwise_and(img,img, mask=mask)

//    bitwise_and(input, input, output, blueArea);


    return coloredArea;
}

cv::Mat VideoProcessor::getCleanArea(cv::Mat input){

    Mat output;
    input.copyTo(output);

    vector<vector<Point>> contours;
    findContours(input, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

    int maxArea = 0;
    int maxAreaIndex = 0;
    for(int i = 0; i < contours.size(); i++){
        vector<Point> contour = contours[i];
        int area = contourArea(contour);
        if(maxArea < area){
            maxArea = area;
            maxAreaIndex = i;
        }
    }

    for(int i = 0; i < contours.size(); i++){
        if (i != maxAreaIndex){
            drawContours(output, contours, i, Scalar(0,0,0),CV_FILLED);
        }
    }

    return output;
}

Scalar VideoProcessor::getUpperBorder(int baseColor){

    Scalar upperBorder(baseColor/2+10, 255, 255);
    return upperBorder;
}

Scalar VideoProcessor::getLowerBorder(int baseColor){

    Scalar lowerBorder(baseColor/2-10, 150, 150);
    return lowerBorder;
}
