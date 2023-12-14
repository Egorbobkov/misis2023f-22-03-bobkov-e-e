//
// Created by egor on 14.12.2023.
//
#include<opencv2/opencv.hpp>
using namespace cv;
int main()
{
    std::string image_path = samples::findFile("/Users/egor/Documents/GitHub/misis2023f-22-03-bobkov-e-e/prj.cw/bird.jpg");
    Mat img = imread(image_path, IMREAD_COLOR);
    if(img.empty())
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return 1;
    }
    imshow("Display window", img);
    int k = waitKey(0); // Wait for a keystroke in the window
    if(k == 's')
    {
        imwrite("starry_night.png", img);
    }
    return 0;
}

