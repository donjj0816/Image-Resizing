// Project UID af1f95f547e44c8ea88730dfb185559d

#include <cassert>
#include "Image.h"


// REQUIRES: img points to an Image
//           0 < width && width <= MAX_MATRIX_WIDTH
//           0 < height && height <= MAX_MATRIX_HEIGHT
// MODIFIES: *img
// EFFECTS:  Initializes the Image with the given width and height.
// NOTE:     Do NOT use new or delete here.
void Image_init(Image* img, int width, int height) {

  img->height = height;
  img->width = width;
  Matrix_init(&(img->red_channel), width, height);
  Matrix_init(&(img->green_channel), width, height);
  Matrix_init(&(img->blue_channel), width, height);

}
 
// REQUIRES: img points to an Image
//           is contains an image in PPM format without comments
//           (any kind of whitespace is ok)
// MODIFIES: *img
// EFFECTS:  Initializes the Image by reading in an image in PPM format
//           from the given input stream.
// NOTE:     See the project spec for a discussion of PPM format.
// NOTE:     Do NOT use new or delete here.
void Image_init(Image* img, std::istream& is) {
  std::string temp_img;
  is >> temp_img;
  int width, height;
  is >> width >> height;
  img->width = width;
  img->height = height;

  Matrix_init(&img->red_channel, width, height);
  Matrix_init(&img->green_channel, width, height);
  Matrix_init(&img->blue_channel, width, height);

  std::string next_temp_img;
  is >> next_temp_img;
  //height then width
  for(int k = 0; k < height; k++) {
    for(int j = 0; j < width; j++) {
      int red, green, blue;
      is >> red >> green >> blue;
      Pixel holeder_pix = {red, green, blue};
      Image_set_pixel(img, k, j, holeder_pix);
    }
  }
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Writes the image to the given output stream in PPM format.
//           You must use the kind of whitespace specified here.
//           First, prints out the header for the image like this:
//             P3 [newline]
//             WIDTH [space] HEIGHT [newline]
//             255 [newline]
//           Next, prints out the rows of the image, each followed by a
//           newline. Each pixel in a row is printed as three ints
//           for its red, green, and blue components, in that order. Each
//           int is followed by a space. This means that there will be an
//           "extra" space at the end of each line. See the project spec
//           for an example.
void Image_print(const Image* img, std::ostream& os) {
  assert(img != nullptr);

  os << "P3\n"; 
  os << img->width << " " << img->height << "\n"; 
  os << "255\n";

  for(int k = 0; k < Image_height(img); k++) {
      for(int j = 0; j < Image_width(img); j++) {
        os << *Matrix_at(&img->red_channel, k, j) << " "
        << *Matrix_at(&img->green_channel, k, j) << " "
        << *Matrix_at(&img->blue_channel, k, j) << " ";
      }
      os << "\n";
  }
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Returns the width of the Image.
int Image_width(const Image* img) {
  assert(img != nullptr);
  return img->width;
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Returns the height of the Image.
int Image_height(const Image* img) {
  assert(img != nullptr);
  return img->height;
}

// REQUIRES: img points to a valid Image
//           0 <= row && row < Image_height(img)
//           0 <= column && column < Image_width(img)
// EFFECTS:  Returns the pixel in the Image at the given row and column.
Pixel Image_get_pixel(const Image* img, int row, int column) {
  assert(img != nullptr);
  const int *redp; 
  const int *bluep; 
  const int *greenp; 

  redp = Matrix_at(&(img->red_channel), row, column);
  bluep = Matrix_at(&(img->blue_channel), row, column);
  greenp = Matrix_at(&(img->green_channel), row, column);
  
  Pixel point;
  point.r = *redp;
  point.b = *bluep;
  point.g = *greenp;
  
  return point;
}

// REQUIRES: img points to a valid Image
//           0 <= row && row < Image_height(img)
//           0 <= column && column < Image_width(img)
// MODIFIES: *img
// EFFECTS:  Sets the pixel in the Image at the given row and column
//           to the given color.
void Image_set_pixel(Image* img, int row, int column, Pixel color) {
  assert(img != nullptr);

   int *redp; 
   int *bluep; 
   int *greenp; 

  redp = Matrix_at(&(img->red_channel), row, column);
  bluep = Matrix_at(&(img->blue_channel), row, column);
  greenp = Matrix_at(&(img->green_channel), row, column);
  
  *redp = color.r;
  *bluep = color.b;
  *greenp = color.g;

  }

// REQUIRES: img points to a valid Image
// MODIFIES: *img
// EFFECTS:  Sets each pixel in the image to the given color.
void Image_fill(Image* img, Pixel color) {
  assert(img != nullptr);

  Matrix_fill(&(img->red_channel), color.r);
  Matrix_fill(&(img->blue_channel), color.b);
  Matrix_fill(&(img->green_channel), color.g);
}
