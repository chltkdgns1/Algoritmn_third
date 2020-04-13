#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <map>
using namespace cv;
using namespace std;

Scalar color(255, 255, 255);
// 도형 내부 채울때 사용할 색 지정시 사용 ( 초기값은 흰색 )
Mat img;

void mouse_callback(int event, int x, int y, int flags, void *userdata) {
	if (event == 1) {
		rectangle(img, Point(x - 50, y - 50), Point(x + 50, y + 50), color, -1);
	}
	else if (event == 2) {
		circle(img, Point(x, y), 50, color, -1);
	}
}

int main() {
	cout << "1. 왼족 마우스 클릭시 사각형 생성\n";
	cout << "2. 오른쪽 마우스 클릭시 원 생성\n";
	cout << "3. x 버튼 클릭시 종료\n";
	img = Mat(Size(800, 600), CV_8UC3, Scalar(0, 0, 0));
	namedWindow("img");
	setMouseCallback("img", mouse_callback, 0);

	while (1) {
		imshow("img", img);
		int key = waitKey(1);
		if (key == 'x') break;
	}
	destroyAllWindows();
	waitKey(0);
}
