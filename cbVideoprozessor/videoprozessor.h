#ifndef VIDEOPROZESSOR_H
#define VIDEOPROZESSOR_H

#include <opencv2/opencv.hpp>

class VideoProcessor
{
public:
    VideoProcessor();
    ~VideoProcessor();
    int startCamera();
    cv::Mat getColorFromFrame(cv::Mat input);

private:
    cv::Mat referenceFrame, hsvPlanes;

};

#endif // VIDEOPROZESSOR_H
