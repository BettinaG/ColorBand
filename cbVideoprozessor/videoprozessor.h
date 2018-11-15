#ifndef VIDEOPROZESSOR_H
#define VIDEOPROZESSOR_H

#include <opencv2/opencv.hpp>
#include <../drumstick/midioutput.h>
#include <../drumstick/midiinput.h>

class VideoProcessor
{
public:
    VideoProcessor();
    ~VideoProcessor();
    int startCamera();


    int showTestImage();
    std::vector<int> getColoredAreas(cv::Mat input, int color);
    std::vector<int> getDominantColor(std::vector<int> red, std::vector<int> blue, std::vector<int> green, int amountOfElements);

    cv::Mat getColorFromFrame(cv::Mat input, int color);
    cv::Mat getCleanArea(cv::Mat input);

    cv::Scalar getUpperBorder(int baseColor);
    cv::Scalar getLowerBorder(int baseColor);

private:
    const int minSize = 1000;
    const int red = 350;
    const int blue = 205;
    const int green = 135;

    std::vector<int> redResult, blueResult, greenResult;

    drumstick::rt::MIDIOutput midiOutput;
    int midichannel;
};

#endif // VIDEOPROZESSOR_H
