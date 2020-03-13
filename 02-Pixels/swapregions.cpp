#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    Mat image;

    image = imread("square.jpg", IMREAD_GRAYSCALE);
    if (!image.data)
    {
        cout << "[ERROR] Could not open file square.png" << endl;
        return -1;
    }

    namedWindow("Swap Regions", WINDOW_AUTOSIZE);

    // Swap regions
    int xHalf = image.cols / 2;
    int yHalf = image.rows / 2;

    // Create four regions (A, B, C, and D)
    Mat A(image, Range(0, yHalf), Range(0, xHalf));
    Mat B(image, Range(0, yHalf), Range(xHalf, image.cols));
    Mat C(image, Range(yHalf, image.rows), Range(0, xHalf));
    Mat D(image, Range(yHalf, image.rows), Range(xHalf, image.cols));

    Mat result1;
    result1.push_back(D);
    result1.push_back(B);

    Mat result2;
    result2.push_back(C);
    result2.push_back(A);

    Mat result;
    hconcat(result1, result2, result);

    imshow("Swap Regions", result);
    waitKey();

    return 0;
}