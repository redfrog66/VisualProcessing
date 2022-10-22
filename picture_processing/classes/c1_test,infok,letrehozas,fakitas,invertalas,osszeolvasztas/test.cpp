//
//  egy kep betoltese es megjelenitese 
//

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main() {

    // a .cpp allomany melle masolt kep.png eseten
    Mat img = imread("kep.png");

    // egy szinttel kintebb levo kep eseten
    //Mat img = imread("../kep.png");

    //abszolut utvonallal
    //Mat img = imread("c:/user/hallgato/kep.png");
    //Mat img = imread("c:\\user\\hallgato\\kep.png");

    imshow("kep", img);
    waitKey(0);

    return 0;
}