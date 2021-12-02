#ifndef RECHERCHE_DFT_H
#define RECHERCHE_DFT_H

#include "opencv2/core.hpp"

using namespace cv;

void forward_dft(Mat& src, Mat& dst);

void inverse_dft(Mat& src, Mat& dst);

void real_imaginary(Mat& complex, Mat* dst);

void amplitude_phase(Mat& complex, Mat* dst);

void shift_image(Mat& src, Mat& dst);

void display_amplitude_phase(Mat amplitude, Mat phase, bool rescale=true);

void display_amplitude_phase(Mat& complex, bool rescale=true);

#endif //RECHERCHE_DFT_H
