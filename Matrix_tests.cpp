// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

// ADD YOUR TESTS HERE

//Matrix init
TEST(test_matrix_init) {
  Matrix *mat = new Matrix;

  Matrix_init(mat, 3, 5);
  ASSERT_TRUE(mat !=nullptr);
  ASSERT_TRUE(Matrix_width(mat) == 3);
  delete mat;
  }
TEST(test_matrix_init_2) {
  Matrix *mat = new Matrix;

  Matrix_init(mat, 3, 5);
  ASSERT_TRUE(mat !=nullptr);
  ASSERT_TRUE(Matrix_height(mat) == 5);
  delete mat;
}
//Matrix Print
TEST(test_matrix_print) {
  const int k = 12;
  Matrix *mat = new Matrix;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat,k);
  ostringstream output;
  output << "3 5\n"
  << "12 12 12 \n"
  << "12 12 12 \n"
  << "12 12 12 \n"
  << "12 12 12 \n"
  << "12 12 12 \n";
  ostringstream answer;
  Matrix_print(mat, answer);
  ASSERT_EQUAL(output.str(), answer.str());
  delete mat;
}
//width and height
TEST(test_matrix_width) {
  Matrix *mat = new Matrix;
  const int width = 5;
  const int height = 4;
  Matrix_init(mat,width,height);
  ASSERT_EQUAL(Matrix_width(mat),5);
  delete mat;
}

TEST(test_matrix_height) {
  Matrix *mat = new Matrix;
  const int k = 12;

  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, k);

  ASSERT_EQUAL(Matrix_height(mat),5);
  delete mat;
}
//row and column
TEST(test_matrix_row_col) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 3, 5);
   ASSERT_EQUAL(Matrix_row(mat,Matrix_at(mat,1,2)), 1);
   ASSERT_EQUAL(Matrix_column(mat,Matrix_at(mat,1,2)), 2);
  delete mat;
}

//fill tests
TEST(test_fill_2) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = -42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}
TEST(test_matrix_fill_border) {
  Matrix *mat = new Matrix; 

  const int width = 3;
  const int height = 5;
  const int value1 = -3;
  const int value2 = 12;

  Matrix_init(mat, width, height);
  Matrix_fill(mat, value1);
  Matrix_fill_border(mat,value2);

  ostringstream answer;
  answer << "3 5\n"
  << "12 12 12 \n"
  << "12 -3 12 \n"
  << "12 -3 12 \n"
  << "12 -3 12 \n"
  << "12 12 12 \n";

  ostringstream output;
  Matrix_print(mat,output);

  ASSERT_EQUAL(answer.str(), output.str());
  delete mat;
}
TEST(test_matrix_fill_border_2) {
  Matrix *mat = new Matrix; 

  const int width = 1;
  const int height = 2;
  const int value1 = -3;
  const int value2 = 12;

  Matrix_init(mat, width, height);
  Matrix_fill(mat, value1);
  Matrix_fill_border(mat,value2);

  ostringstream answer;
  answer << "1 2\n"
  << "12 \n"
  << "12 \n";
  ostringstream output;
  Matrix_print(mat,output);

  ASSERT_EQUAL(answer.str(), output.str());
  delete mat;
}
//max
TEST(test_matrix_max) {
  Matrix *mat = new Matrix; 

  const int width = 7;
  const int height = 4;
  const int value1 = -12;

  Matrix_init(mat, width, height);
  Matrix_fill(mat, value1);
  *Matrix_at(mat,3,2) = -33;
  *Matrix_at(mat,3,3) = - 3;

  ASSERT_EQUAL(Matrix_max(mat),-3);
  delete mat;

}
//column of min value in row
TEST(test_min_value_in_row) {
  Matrix *mat = new Matrix; 

  const int width = 7;
  const int height = 4;
  const int value1 = 12;

  Matrix_init(mat, width, height);
  Matrix_fill(mat, value1);
  *Matrix_at(mat,3,2) = -33;
  *Matrix_at(mat,6,3) = -3;
  *Matrix_at(mat,1,3) = 13;


  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 1, 0, 7), 12);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 3, 0, 7), -33);
    *Matrix_at(mat,2,4) = 22;

  ASSERT_EQUAL(Matrix_max(mat), 22);
  delete mat;
}

//min value in row
TEST(test_col_min_value_in_row) {
  Matrix *mat = new Matrix; 

  const int width = 7;
  const int height = 4;
  const int value1 = 20;

  Matrix_init(mat, width, height);
  Matrix_fill(mat, value1);
  *Matrix_at(mat,3,2) = -33;
  *Matrix_at(mat,6,3) = -3;
  *Matrix_at(mat,1,3) = 13;

  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,3,0,width),2);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,6,0,width),3);
  delete mat;
}





// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
