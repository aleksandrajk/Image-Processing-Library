# Image-Processing-Library
Image Processing Library is a C++ library designed for performing various image processing tasks on images.
This library provides functions to manipulate images, apply filters, perform edge detection, enhance image quality, and more. 

The algorithms and techniques have been implemented from scratch, serving as a platform to learn and grasp the core concepts of image processing. The main goal is to understand the fundamentals of image manipulation, feature extraction, noise reduction, and more.

## Example: Processed Images

<img width="255" alt="original_camera_image" src="https://github.com/aleksandrajk/Image-Processing-Library/assets/55165756/c4bc7ea9-21c7-41e4-be24-37dea6673cd3">

Negative Image | Brightness_up Image | Image with Robinson Mask:

<img width="255" alt="negative" src="https://github.com/aleksandrajk/Image-Processing-Library/assets/55165756/a901370b-a523-4cbd-af38-a3220c5a7bf7">
<img width="256" alt="brightness_up" src="https://github.com/aleksandrajk/Image-Processing-Library/assets/55165756/d972e391-df85-494d-a844-ef4e70a7f6ad">
<img width="255" alt="robinson_mask" src="https://github.com/aleksandrajk/Image-Processing-Library/assets/55165756/81ea3b65-be16-40c6-9026-fdf6b7964442">


## Features
The library offers the following features:
1. __2-D Discrete Convolution & Correlation__: Perform convolution operations on images using custom kernels for tasks like blurring, sharpening, and more.
2. __Edge-Detection__: Detect edges in images using Sobel, Prewitt, Kirsch, Robinson, Laplacian, and Ropert's Masks for edge detection.
3. __Filter Algorithms__: Apply spatial filters to images for noise reduction and enhancement. Filters available: Salt and Pepper Filter, High-Pass/Low-Pass Spatial Filter, Gaussian Noise Filter, Maximum/Minimum/Medium Filters.
4. __Image Histogram and Equalization__: Calculate image histograms and perform histogram equalization to enhance image contrast.
5. __Gray Level Transformation__: Perform gray-level transformations such as contrast stretching, thresholding, and gamma correction.
6. __Noise Suppression__: Apply filters and techniques to suppress noise in images, improving overall image quality.
7. __Other Utilities__: Additional utilities for basic image manipulation.


## Some concepts to review:

__Image processing__ is a field of computer science and engineering that involves manipulating digital images using algorithms and techniques. It aims to enhance, analyze, or manipulate images to extract useful information or improve visual quality. Image processing is used in various applications such as medical imaging, remote sensing, photography, video compression, etc.

Image processing involves the manipulation of digital images using algorithms, where images are composed of pixels arranged in arrays. Pixels are the smallest units of an image, and each pixel's color and properties are often represented using color models like RGB. These concepts are fundamental to understanding how images are represented and processed in the digital realm.

__Pixel:__
A pixel (short for "picture element") is the smallest unit of a digital image. It's a tiny square or dot that represents a single point in an image. Pixels are the building blocks of digital images and are used to display and represent visual information. Each pixel can have different properties, such as its color and intensity.

__Arrays for Pixels:__
In digital images, pixels are organized in a grid-like structure. This grid is often represented as a two-dimensional array, where each element of the array corresponds to a pixel at a specific position. The dimensions of the array correspond to the image's width and height, and the values in the array represent the properties of the pixels at those positions, such as color and intensity.

__Color in Images:__
Color in digital images is represented using various color models, with the most common one being the RGB (Red, Green, Blue) color model. In the RGB model, each pixel's color is specified by three values: the amount of red, green, and blue light that it contains. By combining different intensities of red, green, and blue light, a wide range of colors can be created.

For instance, if a pixel has maximum red intensity, no green intensity, and no blue intensity, it will appear as a shade of pure red. If it has equal intensities of red, green, and blue, it will appear as white, since it's a combination of all three primary colors. Black can be represented by pixels with minimal intensities in all three channels.

There are other color models as well, such as CMYK (Cyan, Magenta, Yellow, Key/Black) used in printing, and HSL/HSV (Hue, Saturation, Lightness/Value), which provide different ways to represent and manipulate colors based on different properties.


### Examples of arrays representing pixels in various color models:

```python
bw_pixel_black = [0]  # 0 represents black
```

```python
gray_pixel = [128]  # 128 represents a shade of grey
```

```python
rgb_pixel_red = [255, 0, 0]  # Red: 255, Green: 0, Blue: 0
```

```python
hsv_pixel_blue = [240, 255, 255]  # Hue: 240, Saturation: 255, Value: 255
```

```python
cmyk_pixel_yellow = [0, 0, 255, 0]  # Cyan: 0, Magenta: 0, Yellow: 255, Key: 0
```

These arrays represent the pixel values in different color models. The values provided here are simplified examples, and actual pixel values may vary based on the color model's specific range and conventions.

## Math behind Image Equalisation

__Image equalization__ is a technique used in image processing to enhance the contrast and improve the overall visual appearance of an image. It aims to adjust the pixel intensities of an image in a way that spreads out the intensity values over a wider range. This can help in making the details in dark or light regions of an image more distinguishable, thus enhancing the visibility of features.

Image equalization involves transforming the pixel intensity values of an image using a mathematical function. The basic idea is to redistribute the pixel values in a way that the resulting histogram becomes as uniform as possible. The steps involved in image equalization are as follows:

__1. Compute Histogram:__ Calculate the histogram of the original image, which is a distribution of the pixel intensity values.

__2. Calculate Cumulative Distribution Function (CDF):__ Calculate the cumulative distribution function of the histogram. The CDF represents the probability that a pixel has an intensity less than or equal to a given value.

__3. Normalize CDF:__ Normalize the CDF so that it spans the entire intensity range (typically 0 to 255 for an 8-bit image).

__4. Compute Equalization Mapping:__ Map the original intensity values to new values using the normalized CDF. This mapping redistributes the pixel values.

__5. Apply Mapping:__ Replace each pixel's intensity value in the original image with its corresponding value from the equalization mapping.

The equalized image should have a more balanced distribution of pixel intensities, resulting in enhanced contrast and better visualization of details.

Image equalization can be particularly useful when an image has a narrow range of pixel intensities, making it look flat or lacking contrast. However, it's important to note that equalization might not always produce visually pleasing results, especially if the original image already has a well-balanced distribution.

## Geometric Operations with Images

Geometric operations in image processing involve modifying the spatial arrangement of pixels in an image. These operations alter the image's geometric characteristics, such as position, orientation, and size, without changing the pixel values themselves. Here are explanations of some common geometric operations:

__1. Rotation:__
Rotation involves rotating the entire image by a specified angle around a fixed point. This can be clockwise or counterclockwise. During rotation, the pixel positions are changed, but the pixel values remain the same. To achieve this, mathematical transformations like rotation matrices or trigonometric calculations are used.

__2. Flipping:__
Flipping, also known as reflection, involves creating a mirror image of the original by reversing the order of pixel rows or columns. There are two types of flips: horizontal flip (left-to-right) and vertical flip (top-to-bottom). Flipping can be useful for certain image manipulations, such as creating symmetrical patterns.

__3. Cropping:__
Cropping involves selecting a rectangular region of interest from the original image while discarding the surrounding parts. This is achieved by specifying the coordinates of the top-left and bottom-right corners of the desired region. Cropping is commonly used to extract specific parts of an image for further analysis or to remove unwanted portions.

__4. Scaling:__
Scaling modifies the size of an image by either enlarging it (zooming in) or reducing it (zooming out). Scaling involves changing the pixel-to-pixel spacing while maintaining the relative arrangement of pixels. Various interpolation techniques are used to determine the new pixel values based on neighboring pixels.

__5. Shearing:__
Shearing involves shifting the rows or columns of an image in a linear manner, causing the image to be distorted along a particular axis. This operation is often used for special effects or to correct perspective distortion in images.

__6. Translation:__
A translation moves the entire image in a particular direction. It involves shifting all pixels by a certain amount along the horizontal and vertical axes. Translation can be used to reposition objects within an image.

__7. Affine Transformations:__
Affine transformations are a combination of rotation, scaling, shearing, and translation. They can perform more complex transformations that preserve straight lines and parallelism. Affine transformations are often used in computer vision applications like image registration and image rectification.

__8. Warping:__
Warping involves the nonlinear deformation of an image, which can result in complex transformations. This is used in applications like image morphing, where one image is gradually transformed into another, often creating smooth transitions between objects.

Geometric operations are fundamental in various image processing applications, from basic image adjustments to advanced computer vision tasks. These operations can be performed using various algorithms and techniques, and they play a crucial role in manipulating and transforming images for various purposes.



##  Edge Detection
Edge detection is a fundamental technique in image processing that focuses on identifying abrupt changes or transitions in pixel intensity values within an image. Edges represent the boundaries between different objects or regions in an image and are crucial for tasks like object detection, image segmentation, and feature extraction. Edge detection aims to locate the positions of these significant intensity changes, highlighting the outlines and shapes of objects.


### Common Edge Detection Masks:
These are various image processing masks (also known as kernels or filters) used for edge detection and other image enhancement tasks. Each mask represents a convolutional filter that is applied to an image to highlight edges or other features. Here's an explanation of each mask:

__1. Prewitt Mask:__
The Prewitt mask is a convolutional filter used for edge detection. It consists of two kernels—one for detecting vertical edges and another for detecting horizontal edges. The Prewitt mask emphasizes edges by calculating the gradient of the image in the horizontal and vertical directions.
```
/*Prewitt Operator - Vertical Edges*/
/*
   -1  0   1
   -1  0   1
   -1  0   1
*/

/*Prewitt Operator - Horizontal Edges*/
/*
   -1  -1  -1
    0   0   0
   -1   -1 -1
*/
```

__2. Sobel Mask:__
Similar to the Prewitt mask, the Sobel mask is another widely used filter for edge detection. It also has separate kernels for detecting vertical and horizontal edges. The Sobel mask is designed to be more sensitive to edges while reducing noise effects compared to the Prewitt mask.
```
/*Sobel Operator -  Vertical Edges*/
/* -1  0  1
   -2  0  2
   -1  0  1
*/

/*Sobele Operator -  Horizontal Edges*/
/*  -1  -2  -1
     0   0   0
     1   2   1
*/
```

__3. Robinson Mask:__
The Robinson mask is a set of eight kernels, each detecting edges in different directions (orthogonal and diagonal). It's less commonly used than Prewitt and Sobel masks, but it provides edge detection capabilities in various orientations.
* 8 Robinson Operators directions: north, south, west, east, northwest, northeast, southeast, southwest. 

```
static const int ROBINSON_NTH[] ={-1,0,1,-2,0,2,-1,0,1};
static const int ROBINSON_STH[] ={1,0,-1,2,0,-2,1,0,-1};
static const int ROBINSON_WST[] ={1,2,1,0,0,0,-1,-2,-1};
static const int ROBINSON_EST[] ={-1,-2,-1,0,0,0,1,2,1};

static const int ROBINSON_NWST[] = {0,1,2,-1,0,1,-2,-1,0};
static const int ROBINSON_NEST[] = {-2,-1,0,-1,0,1,0,1,2};
static const int ROBINSON_SWST[] = {2,1,0,1,0,-1,0,-1,-2};
static const int ROBINSON_SEST[] = {0,-1,-2,1,0,-1,2,1,0};
```

__4. Kirsch Mask:__
The Kirsch mask, like the Robinson mask, consists of eight kernels designed to detect edges in different directions. Kirsch masks are used for detecting edges at angles other than the usual horizontal and vertical directions.
* 8 Kirsch Operators directions: north, south, west, east, northwest, northeast, southeast, southwest. 
```
/*Kirsch Operator*/
static const int KIRSCH_NTH[]={5,5,5,-3,0,-3,-3,-3,-3};
static const int KIRSCH_STH[]={-3,-3,-3,-3,0,-3,5,5,5};
static const int KIRSCH_EST[]={-3,-3,5,-3,0,5,-3,-3,5};
static const int KIRSCH_WST[]={5,-3,-3,5,0,-3,5,-3,-3};

static const int KIRSCH_NWST[] = {0,1,2,-1,0,1,-2,-1,0};
static const int KIRSCH_NEST[] = {-2,-1,0,-1,0,1,0,1,2};
static const int KIRSCH_SWST[] = {2,1,0,1,0,-1,0,-1,-2};
static const int KIRSCH_SEST[] = {0,-1,-2,1,0,-1,2,1,0};
```

__5. Laplacian Mask:__
The Laplacian mask is used for detecting areas of rapid intensity change in all directions. It calculates the second derivative of the image and highlights regions with intensity variations, including both edges and corners. Laplacian of Gaussian (LoG) is a variant that combines Gaussian smoothing and Laplacian filtering for edge detection.

```
/*Laplacian Negative Mask*/
/* 
  0 -1 0
  -1 4 -1
  0 -1 0
*/

/*Laplacian Positive Mask*/
/* 
  0 1 0
  1 -4 1
  0 1 0
*/
```

__6. Robert's Mask:__
Robert's mask is used for detecting edges by calculating the gradient along the diagonals of the image. It uses two small 2x2 kernels—one for the 45-degree diagonal and another for the 135-degree diagonal.

```
/*Roberts Mask  Gx*/
/* 
  1 0
  0 -1
*/

/*Roberts Mask Gy*/
/*
  0  1
 -1  0
*/
```
These masks are convolved with the image using convolution operations to detect edges or other features. Convolution involves placing the center of the mask at each pixel of the image and calculating the weighted sum of the pixel values under the mask. The result of convolution highlights areas of the image where the mask aligns with edges or significant intensity changes.

Different masks have varying sensitivities to different edge orientations, noise, and fine details. The choice of mask depends on the specific task and the characteristics of the image being processed. Edge detection masks are fundamental tools in image processing for various applications, including computer vision, image segmentation, and feature extraction.


## 2-D Convolution and Correlation
2-D convolution and correlation are mathematical operations used in image processing to process images using filters or kernels. Both operations involve sliding a filter over an image and performing computations at each position. While they have similarities, they differ in how the filter values are combined with the image pixel values. Let's explore each operation:

__2-D Convolution:__
In 2-D convolution, a filter (also known as a kernel) is applied to an image by overlaying the filter onto the image and performing element-wise multiplication followed by summation. The filter's center (also known as the anchor point) is aligned with each pixel in the image, and the filter coefficients are multiplied with the corresponding pixel values within the filter's local region. The resulting values are summed up to determine the new pixel value.
Convolution can be used for various image-processing tasks, such as blurring, edge detection, and feature extraction. 

__2-D Correlation:__
2-D correlation is similar to convolution but doesn't involve flipping the filter. Instead, the filter is directly applied to the image without any changes to its coefficients. Correlation is often used in tasks like template matching, where a smaller image (template) is matched against a larger image to find instances of the template.

__Key Differences:__
The main difference between 2-D convolution and correlation lies in how the filter values are treated. In convolution, the filter is flipped before performing multiplication and summation, while in correlation, the filter is used directly without any flipping. This difference results in distinct behaviors and applications for each operation.

In both cases, the filter coefficients define the nature of the operation, and different filter designs lead to different image processing outcomes.

