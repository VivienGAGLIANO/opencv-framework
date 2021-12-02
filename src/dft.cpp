#include <opencv2/highgui.hpp>

#include "dft.h"

void forward_dft(Mat &src, Mat &dst)
{
    Mat complex[] = {src, Mat::zeros(src.size(), CV_32F)};
    Mat DFT;
    merge(complex, 2, DFT);

    dft(DFT, dst);
}

void inverse_dft(Mat &src, Mat &dst)
{
    dft(src, dst, DFT_INVERSE | DFT_REAL_OUTPUT | DFT_SCALE);
}

void real_imaginary(Mat &complex, Mat *dst)
{
    split(complex, dst);
}

void amplitude_phase(Mat &complex, Mat *dst)
{
    Mat reIm[] = {complex, Mat::zeros(complex.size(), CV_32F)};
    real_imaginary(complex, reIm);

    magnitude(reIm[0], reIm[1], dst[0]);
    phase(reIm[0], reIm[1], dst[1]);
}

void shift_image(Mat &src, Mat &dst)
{
    // rearrange the quadrants of Fourier image  so that the origin is at the image center
    int cx = src.cols/2;
    int cy = src.rows/2;

    Mat q0A(src, Rect(0, 0, cx, cy));   // Top-Left - Create a ROI per quadrant
    Mat q1A(src, Rect(cx, 0, cx, cy));  // Top-Right
    Mat q2A(src, Rect(0, cy, cx, cy));  // Bottom-Left
    Mat q3A(src, Rect(cx, cy, cx, cy)); // Bottom-Right

    Mat tmp;                           // swap quadrants (Top-Left with Bottom-Right)
    q0A.copyTo(tmp);
    q3A.copyTo(q0A);
    tmp.copyTo(q3A);

    q1A.copyTo(tmp);                    // swap quadrant (Top-Right with Bottom-Left)
    q2A.copyTo(q1A);
    tmp.copyTo(q2A);
}

void display_amplitude_phase(Mat amplitude, Mat phase, bool rescale)
{
    if (rescale) // switch to logarithmic scale
    {
        amplitude += Scalar::all(1);
        log(amplitude, amplitude);
    }

//    amplitude = amplitude(Rect(0, 0, amplitude.cols & -2, amplitude.rows & -2));
    shift_image(amplitude, amplitude);
    normalize(amplitude, amplitude, 0, 1, NORM_MINMAX);

//    phase = phase(Rect(0, 0, phase.cols & -2, phase.rows & -2));
    shift_image(phase, phase);
    normalize(phase, phase, 0, 1, NORM_MINMAX);

    imshow("Amplitude", amplitude);
    imshow("Phase", phase);
    waitKey();
}

void display_amplitude_phase(Mat &complex, bool rescale)
{
    Mat ampPha[] = {complex, Mat::zeros(complex.size(), CV_32F)};
    amplitude_phase(complex, ampPha);

    display_amplitude_phase(ampPha[0], ampPha[1], rescale);
}
