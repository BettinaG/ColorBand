#include <videoprozessor.h>
#include <opencv2/opencv.hpp>
#include <vector>
#include <QDebug>

using namespace cv;
using namespace std;
using namespace drumstick::rt;

VideoProcessor::VideoProcessor(){

     midichannel = 1;

     QStringList connections = midiOutput.connections(true);
     midiOutput.open("LoopBe Internal MIDI");
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

       /*
        *   results[0] = size
        *   results[1] = x-coordinates
        *   results[2] = y-coordinates
        *   results[3] = color value
        */
       vector<int> results = getDominantColor(redResult, blueResult, greenResult, 3);


       qDebug() << "size: " << results[0] << "  x: " << results[1] << "y: " << results[2] << "color: " << results[3];

       Point xy(34,1);


       QByteArray data;

       data.resize(5);

       data[0] = 0xf0;	//start byte
       data[1] = (int)(results[1]/3);
       data[2] = (int)(results[2]/3);
       data[3] = results[3];

       data[4] = 0xf7; //end byte

       midiOutput.sendSysex(data);

    qDebug() << data;





        frame = getColorFromFrame(frame, results[3]);
        frame = getCleanArea(frame);

        flip(frame, frame, 1);



        imshow("camera",frame);
        if(waitKey(1) == 27){
            return 0;
        }
    }
}



std::vector<int> VideoProcessor::getColoredAreas(cv::Mat input, int color){

    vector<int> output(4);
    output[3] = color;                                          //last entry = color

    Mat hsv;
    cvtColor(input, hsv, CV_BGR2HSV);                           //convert input to hsv colorspace

    Mat coloredArea(input.rows, input.cols, CV_8UC1);


    // FIND ALL COLORED AREAS (input color)

    inRange(hsv, getLowerBorder(color), getUpperBorder(color), coloredArea);

    if(color == red){                                                           //special case red: red is around 0 in hsv colorspace
        Mat coloredArea2(input.rows, input.cols, CV_8UC1);
        Mat mask(input.rows, input.cols, CV_8UC1);
        inRange(hsv, getLowerBorder(10), getUpperBorder(10), coloredArea2);
        bitwise_and(coloredArea, coloredArea2, coloredArea, mask);
    }


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

    if(maxArea > minSize){
        Moments m = moments(coloredArea,true);
        Point centerOfMass(m.m10/m.m00, m.m01/m.m00);

        output[0] = maxArea;
        output[1] = (int)(centerOfMass.x/3);
        output[2] = (int)(centerOfMass.y/3);

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


Scalar VideoProcessor::getUpperBorder(int baseColor){

    Scalar upperBorder(baseColor/2+20, 255, 255);
    return upperBorder;
}

Scalar VideoProcessor::getLowerBorder(int baseColor){

    Scalar lowerBorder(baseColor/2-20, 140, 140);
    return lowerBorder;
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

    if(maxArea < minSize) drawContours(output, contours, maxAreaIndex, Scalar(0,0,0), CV_FILLED);

    for(int i = 0; i < contours.size(); i++){
        if (i != maxAreaIndex){
            drawContours(output, contours, i, Scalar(0,0,0),CV_FILLED);
        }
    }

    return output;
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
