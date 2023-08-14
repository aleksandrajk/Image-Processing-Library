#include "ImageProcessing.h"

using namespace std;

int main()
{
//    float imgHist[NO_OF_GRAYLEVELS];

    int imgWidth, imgHeight, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char imgInBuffer[_512by512_IMG_SIZE];
    unsigned char imgOutBuffer[_512by512_IMG_SIZE];

    const char imgName[] ="images/camera.bmp";
    const char newImgName[] ="images/camera_negative.bmp";

    ImageProcessing *myImage  = new ImageProcessing(imgName,
                                                    newImgName,
                                                    &imgHeight,
                                                    &imgWidth,
                                                    &imgBitDepth,
                                                    &imgHeader[0],
                                                    &imgColorTable[0],
                                                    &imgInBuffer[0],
                                                    &imgOutBuffer[0] //Note: The result is put back into the input buffer for SaltAndPepper and Gaussian
    );


//    myImage->brigthnessDown(imgInBuffer, imgOutBuffer, _512by512_IMG_SIZE,50);
//
//    myImage->getImageNegative(imgInBuffer, imgOutBuffer, imgWidth, imgHeight);


    myImage->readImage();
    myImage->setMask(3,3,ROBINSON_NTH);
    myImage->Convolve2D(imgHeight, imgWidth, &myImage->myMask, imgInBuffer,imgOutBuffer);
    myImage->writeImage();

    cout<<"Success !"<<endl;
    cout<<"Image Height : "<<imgHeight<<endl;
    cout<<"Image Width  : "  <<imgWidth<<endl;

    return 0;

//    myImage->setMask(2,2,ROBERTS_MSK_GY);
//    myImage->Convolve2D(imgHeight, imgWidth, &myImage->myMask, imgInBuffer,imgOutBuffer);

//    myImage->getImageNegative(imgInBuffer, imgOutBuffer, imgWidth, imgHeight);

//    myImage->equalizeHistogram(imgInBuffer, imgOutBuffer, imgWidth,imgHeight);

//    //0.1 - probability
//    //change - outBuf -> &imgInBuffer[0],
//    myImage->saltAndPepper(imgInBuffer,imgWidth,imgHeight, 30);

//    myImage->generateGaussNoise(imgInBuffer,imgWidth,imgHeight, 50,40);

//    myImage->setMask(3,3,HP_3X3); //Sharpener
//    myImage->Convolve2D(imgHeight,imgWidth, &myImage->myMask, imgInBuffer, imgOutBuffer);

//    myImage->setMask(3,3,LP_3X3); //Sharpener
//    myImage->Convolve2D(imgHeight,imgWidth, &myImage->myMask, imgInBuffer, imgOutBuffer);

//    myImage->medianFilter(imgInBuffer,imgOutBuffer,imgWidth,imgHeight);

}
