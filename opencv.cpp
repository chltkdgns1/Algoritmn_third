#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	cout << "OpenCV Version : " << CV_VERSION << endl;
	namedWindow("img-raw", cv::WINDOW_AUTOSIZE);
	namedWindow("img-gray", cv::WINDOW_AUTOSIZE);
	namedWindow("img-canny", cv::WINDOW_AUTOSIZE);

	Mat rawimg, grayimg, cannyimg;
	rawimg = imread("d:\\WAD-A64U.png", IMREAD_COLOR);
	imshow("img-raw", rawimg);

	cvtColor(rawimg, grayimg, cv::COLOR_BGR2GRAY);
	Canny(grayimg, cannyimg, 10, 100, 3, true);
	imshow("img-gray", grayimg);
	imshow("img-canny", cannyimg);

	waitKey(0);
	destroyAllWindows();

	return 0;
}