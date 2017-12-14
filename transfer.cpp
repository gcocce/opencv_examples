#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <memory>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
	unsigned char *data;

	if( argc != 2)
	{
	  printf( "No file name to open \n" );
	  return -1;
	}

	FILE * fd=fopen(argv[1],"rb");
	if(fd==NULL){
		printf( "Fail to open file\n" );
		return -1;
	}
	
	fseek(fd, 0L, SEEK_END);
	size_t sz = ftell(fd);

	fseek(fd, 0L, SEEK_SET);
	
	printf( "File size: %d\n", sz);
	
	data=(unsigned char*) malloc(sz+100);
	
	printf( "Se lee el archivo\n");
	
	int res=fread(data, sz, 1, fd);
	
	printf( "Se leyo el arhivo %d\n", res);
	
	printf( "Se intenta decodificar la imagen\n");
	Mat img = imdecode(*data,1);
	
	printf( "Se intenta escribir la imagen decodificada\n");
	
	imwrite("./bytes1.png", img);
	
	
	printf( "Se crea la matriz \n");
	
	//cv::Mat imageWithData = cv::Mat(sz, 1, CV_8UC4, data).clone();
	cv::Mat imageWithData = cv::Mat(640, 480, CV_8UC4, data);
	
	if(!imageWithData.data){
		printf( "No image data\n");
	}
	
	printf( "trying to generate png\n");
	
	imwrite("./bytes2.png", imageWithData);

	return 0;
}
