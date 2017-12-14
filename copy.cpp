#include <opencv2/opencv.hpp>
#include <stdio.h>

using namespace cv;

int main( int argc, char** argv )
{

  Mat image;
  image = imread( argv[1], 1 );
  
  if( argc != 2 || !image.data )
    {
      printf( "No image data \n" );
      return -1;
    }

  imwrite("./copy.png", image);

  return 0;
}
