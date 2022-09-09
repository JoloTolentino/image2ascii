 //c+ implementation of a nuance of coding challenge 166 "https://www.youtube.com/watch?v=55iwMYv8tGI"
// September 8, 2022
// Written by Jolo Tolentino 
/// 
#include<iostream>
#include<thread>
#include <cmath>
#include"opencv2/opencv.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/core/matx.hpp"

using namespace std;
bool Stream = true;
const string window_name = "Display";


template <class pixel>
pixel logShift(pixel val){
	return log2(val); 
	
}

void pix2Ascii(cv::Mat img,int row,int col) {
	int current_gray_pix,prev_gray_pix,boundary;
	string val;
	for (int Y = 1; Y < row; Y++) {
		for (int X = 1; X < col; X++) {
			current_gray_pix = logShift((int)img.at<uchar>(Y, X));
			/*;
			prev_gray_pix = logShift((int)img.at<uchar>(Y - 1, X - 1));
			boundary = current_gray_pix - prev_gray_pix; can check boundaries and what not*/
			val = (current_gray_pix !=7) ? to_string(current_gray_pix) : " ";
			if (Y + 1 == row || Y - 1 == 0 ) {
				cout << "#";
			}
			if ( X - 1 == 0 ) {
				cout << "|";
			}
			if ( Y + 1 != row && Y - 1 != 0) {
				cout << val;
			}
			if (X + 1 == col) {
				cout << "|" << endl;
			}	
		}	
	}

	system("cls");
	
}



int main()
{
	
	cv::VideoCapture camera(0);
	cv::Mat img,gray,ascii; 
	
	while (Stream) {
		
		camera >> img;
		cv::imshow(window_name, img);
		cv::resize(img, img, cv::Size(70, 30));
		int row = img.rows;
		int col = img.cols;
		char key = cv::waitKey(10);
		cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);	
		
		pix2Ascii(gray, row, col);
		
		if (key == 'q') {


			Stream = false; 
			break;
		}

	}
	
};

