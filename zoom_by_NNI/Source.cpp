
//zooming an image using nearest neighbour interpolation
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
using namespace cv;

int main()
{
	//Reading an image
	Mat image = imread("C:\\Users\\HP\\Pictures\\Download\\p3.png");

	Mat grey_image(image.rows, image.cols, CV_8UC1);

	Mat zoom_image1(image.rows * 2, image.cols * 2, CV_8UC3);
	Mat zoom_image2(image.rows * 2, image.cols * 2, CV_8UC1);
	Mat zoom_image3(image.rows * 2, image.cols * 2, CV_8UC1);
	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols;j++)
		{
			grey_image.at<uchar>(i, j) = (image.at<Vec3b>(i, j)[0] + image.at<Vec3b>(i, j)[1] + image.at<Vec3b>(i, j)[2]) / 3;
		}
	}

	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols; j++)
		{
			int newRow = 2 * i;
			int newCol = 2 * j;

			zoom_image1.at<Vec3b>(newRow, newCol) = image.at<Vec3b>(i, j);
			zoom_image1.at<Vec3b>(newRow + 1, newCol) = image.at<Vec3b>(i, j);
			zoom_image1.at<Vec3b>(newRow, newCol + 1) = image.at<Vec3b>(i, j);
			zoom_image1.at<Vec3b>(newRow + 1, newCol + 1) = image.at<Vec3b>(i, j);
		}
	}

	//Displaying an image
	imshow("1", image);

	//displaying gray image
	imshow("2", grey_image);

	//Displaying zoom_image
	imshow("3", zoom_image1);
	waitKey(0);

	return 1;
}