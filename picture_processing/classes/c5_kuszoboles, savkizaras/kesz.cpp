/**
* OpenCV gyakorlat
* K�sz�b�l�s: iterat�v m�don
* Annak a k�sz�b�rt�knek a meghat�roz�sa, ahol az el�t�r az eg�sz k�pnek valah�ny % lesz.
*/

#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

///
/// L�trehozunk egy hisztogrammot a vil�goss�g�rt�kek alapj�n
///
void createHisto(const cv::Mat img, cv::Mat& histo) {

	vector<Mat> kepek;
	kepek.push_back(img); // egy k�pet haszn�lunk

	vector<int> csatornak;
	csatornak.push_back(0); // annak az egy k�pnek a 0. csatorn�j�t haszn�ljuk

	vector<int> hiszto_meretek;
	hiszto_meretek.push_back(256);  //minden vil�goss�gk�dot k�l�n sz�molunk

	vector<float> hiszto_tartomanyok;
	hiszto_tartomanyok.push_back(0.0f); //hol kezd�dik a tartom�ny
	hiszto_tartomanyok.push_back(255);  //meddig tart	

	//accumlate: marad false (null�zza a hisztogrammot)
	calcHist(kepek, csatornak, noArray(), histo, hiszto_meretek, hiszto_tartomanyok, false);
}


int main() {

	//Input: sz�rkesk�l�s k�p (vagy eleve sz�rkesk�l�ban olvassuk be vagy a cvtColor-ral �talak�tunk egy szineset)
	Mat img = imread("scanned3.png", IMREAD_GRAYSCALE);

	assert(!img.empty());

	cv::Mat histo;
	createHisto(img, histo);

	//ha nem tudod mit ad vissza, k�rd le a m�retet
	//cout << histo.size() << endl;

	//ha nem tudod, hogy milyen k�p ker�l vissza, k�rd le a t�pust (interface.h-ban vannak a defek)
	//cout << histo.type() << endl;  

	float osszes = img.cols * img.rows; //�sszes k�ppont sz�ma
	float hatter = 0.10f;

	Mat dest;
	float s = 0;
	float th = 0;
	for (int i = 0; i < histo.rows; ++i) {
		s += histo.at<float>(i);
		if (s / osszes > hatter) {
			th = i;
			break;
		}
	}
	threshold(img, dest, th, 255, THRESH_BINARY_INV);

	imshow("arany", dest);
	waitKey();

	return 0;
}