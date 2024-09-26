// Project UID af1f95f547e44c8ea88730dfb185559d
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

#include "Image.h"
#include "processing.h"

using namespace std;


int main(int argc, char *argv[]) {

    if (argc > 5 || argc < 4) {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
     << "WIDTH and HEIGHT must be less than or equal to original" << endl;
     return 1;
    }

   
    Image *img = new Image;
    string first_in = argv[1];
    string first_out = argv[2];
    

    ifstream holder(first_in);
    Image_init(img, holder);
    int new_wdt = atoi(argv[3]);
    int new_hgt = Image_height(img);

    if(!holder.is_open()) {
        cout << "Error opening file: " << first_in << endl;
        return 1;
    }

    if(argc == 5) {
        new_hgt = atoi(argv[4]);
    }

     if (new_hgt < 0 || new_hgt > Image_height(img)) {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
     << "WIDTH and HEIGHT must be less than or equal to original" << endl;
     return 1;
    }

     if (new_wdt < 0 || new_wdt > Image_width(img)) {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
     << "WIDTH and HEIGHT must be less than or equal to original" << endl;
     return 1;
    }

    seam_carve_width(img, new_wdt);
    seam_carve_height(img, new_hgt);
    ofstream new_out(first_out);

    Image_print(img, new_out);
    delete img; 

}