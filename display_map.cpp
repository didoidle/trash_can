#include <opencv2/opencv.hpp>

using namespace cv;

#define point1_x 37.470023
#define point1_y 126.882420
#define point2_x 37.474518
#define point2_y 126.891336



int main(int argc, char **argv)
{
    const char* imageName = argc >=2 ? argv[1] : "img.jpg";
    Mat img = imread(imageName, IMREAD_COLOR);  
    Mat img2;
    double x = 37.472322, y = 126.886240;
    double width = point2_x - point1_x;
    double height = point2_y - point1_y;
    double map_width = img.cols, map_height = img.rows;
    double normal_x = (x - point1_x) / width;
    double normal_y = (y - point1_y) / height;

    int map_x = normal_x * map_width;
    int map_y = normal_y * map_height;

    img2 = img;
    circle(img2, Point(map_x, map_y), 10, Scalar(0,0,255), 1, -1, 0);

    imshow( "find", img2 );





    char c = (char)waitKey(500);
        if( c == 27 )
        { return 0; }

    return 0;
}