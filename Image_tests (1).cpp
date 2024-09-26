// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Image_test_helpers.h"
#include "unit_test_framework.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Sets various pixels in a 2x2 Image and checks
// that Image_print produces the correct output.
TEST(test_print_basic) {
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(img, 2, 2);
  Image_set_pixel(img, 0, 0, red);
  Image_set_pixel(img, 0, 1, green);
  Image_set_pixel(img, 1, 0, blue);
  Image_set_pixel(img, 1, 1, white);

  // Capture our output
  ostringstream s;
  Image_print(img, s);

  // Correct output
  ostringstream correct;
  correct << "P3\n2 2\n255\n";
  correct << "255 0 0 0 255 0 \n";
  correct << "0 0 255 255 255 255 \n";
  ASSERT_EQUAL(s.str(), correct.str());

  delete img; // delete the Image
}

// IMPLEMENT YOUR TEST FUNCTIONS HERE
// You are encouraged to use any functions from Image_test_helpers.h as needed.


// sets image width and height
// respectively to (12,12)
// makes sure init sets image with set vaules
TEST(test_init) {
Image *img = new Image;

// sets image to (12, 12)
Image_init(img, 15, 12);

ASSERT_EQUAL(Image_height(img), 12);
ASSERT_EQUAL(Image_width(img), 15);

delete img; // deletes the image
}

TEST(test_width) {
  Image *img = new Image;

  Image_init(img, 25, 10); // setting width to 25

  ASSERT_EQUAL(Image_width(img), 25);

  delete img;
}

TEST(test_height) {
  Image *img = new Image;

  Image_init(img, 15, 20); // setting height to 20

  ASSERT_EQUAL(Image_height(img), 20);

  delete img;
}

TEST(test_get_pixel) {
  Image *img = new Image;
  
  const Pixel black = {0,0,0};
  const Pixel red = {255, 0, 0};
  const Pixel white = {255, 255, 255};
  const Pixel blue = {0, 0, 255};

// setting image to height and width of 10
  Image_init(img, 10, 10);
  Image_set_pixel(img, 2, 5, black);
  Image_set_pixel(img, 4, 6, red);
  Image_set_pixel(img, 1, 4, white);
  Image_set_pixel(img, 6, 10, blue);

  // Making sure the images equate
  ASSERT_TRUE(Pixel_equal(Image_get_pixel(img,4,6), red));
  ASSERT_TRUE(Pixel_equal(Image_get_pixel(img,2,5), black));

  delete img;
}

TEST(test_set_pixel) {
  Image *img = new Image;
  
  const Pixel black = {0,0,0};
  const Pixel red = {255, 0, 0};
  const Pixel white = {255, 255, 255};
  const Pixel blue = {0, 0, 255};

  Image_init(img, 5, 5);
  Image_set_pixel(img, 1, 5, black);
  Image_set_pixel(img, 0, 0, red);
  Image_set_pixel(img, 2, 4, white);
  Image_set_pixel(img, 3, 3, blue);

  ASSERT_TRUE(Pixel_equal(Image_get_pixel(img,0,0), red));
  ASSERT_TRUE(Pixel_equal(Image_get_pixel(img,3,3), blue));

  delete img;
}

TEST(test_image_fill) {
  Image *img = new Image;

  const Pixel blue = {0, 0, 255};
  const int height = 3;
  const int width = 4;
  Image_init(img, width, height);
  Image_fill(img, blue);

  for (int i = 0; i < height; i++){
    for (int k = 0; k < width; k++){
      ASSERT_TRUE(Pixel_equal(Image_get_pixel(img,i,k), blue));
    }
  }
  delete img;
}

TEST(test_image_fill2){
  Image *img = new Image;

  const Pixel red = {255, 0, 0};
  const int height = 2;
  const int width = 5;
  Image_init(img, width, height);
  Image_fill(img, red);

  for (int i = 0; i < height; i++){
    for (int k = 0; k < width; k++){
      ASSERT_TRUE(Pixel_equal(Image_get_pixel(img,i,k), red));
    }
  }
  delete img;
}


// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
