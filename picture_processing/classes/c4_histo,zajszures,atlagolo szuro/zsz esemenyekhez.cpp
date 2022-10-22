#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

Mat img, dest;

void onChange(int value, void* user_data) {
	medianBlur(img, dest, max(2 * value + 1, 3));
	imshow("dest", dest);
}


int main_eskez() {  // _noise_filtering

	img = imread("../../kepek/szines.png");

	if (img.empty()) {
		cout << "Az kep nem olvashat�." << endl;
		exit(-1);
	}

	imshow("szines", img);

	namedWindow("szuro", WINDOW_NORMAL);
	resizeWindow("szuro", 500, 100);

	int radius = 1;
	createTrackbar("sugar", "szuro", &radius, 50, onChange);

	waitKey(0);

	return 0;
}