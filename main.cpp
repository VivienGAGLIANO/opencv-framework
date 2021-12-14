#include <iostream>
#include "opencv2/core.hpp"
#include <opencv2/highgui.hpp>

#include "dft.h"
#include "low_pass_filter.h"
#include "high_pass_filter.h"
#include "bandpass_filter.h"
#include "bandcut_filter.h"
#include "log_gabor_filter.h"
#include "gaussian_pyramid.h"
#include "laplacian_pyramid.h"

using namespace cv;

static void help(char ** argv)
{
    std::cout << std::endl
         <<  "This program demonstrated the use of the discrete Fourier transform (DFT). " << std::endl
         <<  "The dft of an image is taken and it's power spectrum is displayed."  << std::endl << std::endl
         <<  "Usage:"                                                                      << std::endl
         << argv[0] << " [image_name -- default lena.jpg]" << std::endl << std::endl;
}

static bool load_image(const char* filename, Mat& dest)
{
    Mat I = imread( samples::findFile( filename ), IMREAD_GRAYSCALE);
    if( I.empty()){
        std::cout << "Error opening image" << std::endl;
        return EXIT_FAILURE;
    }

    I.convertTo(I, CV_32FC1, 1.0 / 255.0);
    dest = I;
    return EXIT_SUCCESS;
}

int main(int argc, char ** argv)
{
    help(argv);

    // Load image
    Mat I;
    const char* filename = argc >=2 ? argv[1] : "../resource/lena.png";
    if (load_image(filename, I))
        return EXIT_FAILURE;

    // Take forward Fourier transform
    Mat ft;
    forward_dft(I, ft);

    // Do some filtering stuff
    LogGaborFilter lg(I.size(), 5, .3f);
//    lg.display();
    lg.filter(ft, ft);

//    display_amplitude_phase(ft);

    // Take invert Fourier transform
    Mat ift;
    inverse_dft(ft, ift);
//    imshow("Reconstructed image", ift);
//    waitKey(0);

    LaplacianPyramid pyramid(I, 3);
    pyramid.construct_pyramid();
    pyramid.display_layers_gauss();
    pyramid.display_layers_laplace();

    return EXIT_SUCCESS;
}