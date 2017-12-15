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
	
	printf( "Se crea la matriz \n");
	
	cv::Mat imageWithData = cv::Mat(480, 640, CV_8UC3, data);
	
	if(!imageWithData.data){
		printf( "No image data\n");
	}
	
	fclose(fd);

	printf( "generate filename\n");
	
	string filename;     
	ostringstream buffer;  
	buffer << argv[1] << ".png";      
	filename = buffer.str();
	
	printf( "trying to generate png\n");
	
	imwrite(filename, imageWithData);

	return 0;
}
