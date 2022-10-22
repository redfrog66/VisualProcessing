/**
* OpenCV gyakorlat
* �ldetekt�l�s Sobel �s Canny oper�tor seg�ts�g�vel
*/

#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

///
/// �ldetekt�l�s Sobel oper�torral
///
void SobelElek(const Mat img, Mat& dest) {
	//Deriv�lt meghat�roz�sra
	Mat gx, gy, g;
	Sobel(img, gx, CV_16S, 1, 0);  // fuggoletes iranyu elek kiemelese
	Sobel(img, gy, CV_16S, 0, 1);  // vizszintes iranyu elek kiemelese 
	g = abs(gx) + abs(gy);  //a deriv�lt

	//B�jtra konvert�l
	convertScaleAbs(g, g);

	//Automatikus k�sz�b�l�s
	threshold(g, dest, 0, 255, THRESH_OTSU);
}


///
/// �ldetekt�l�s Canny oper�torral
///
void CannyElek(const Mat img, Mat& dest, int th1) {
	assert(th1 * 3 < 255);
	Canny(img, dest, th1, th1 * 3);
}

int main() {

	Mat img = imread("go2.png", IMREAD_GRAYSCALE);

	assert(!img.empty());

	//Sz�r�s (tomp�tja a zajokat)	
	cv::GaussianBlur(img, img, cv::Size(5, 5), 1.6, 1.6);

	Mat sobel, canny;
	SobelElek(img, sobel);
	CannyElek(img, canny, 25);

	imshow("Sobel elek", sobel);
	imshow("Canny elek", canny);
	waitKey(0);

	return 0;
}