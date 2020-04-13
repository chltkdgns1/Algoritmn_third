#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat img = imread("C:\\Users\\chltk\\1.png");
	if (img.empty()) return cout << "영상을 읽을 수 없음\n", -1;
	imshow("img", img);

	cout << "행의 수 = " << img.rows << "\n";
	cout << "열의 수 = " << img.cols << "\n";
	cout << "행렬의 크기 = " << img.size() << "\n";
	cout << "전체 화소 개수 = " << img.total() << "\n";
	cout << "한 화소 크기 = " << img.elemSize() << "\n";
	cout << "타입 = " << img.type() << "\n";
	cout << "채널 = " << img.channels() << "\n";

	waitKey(0);
}