#include "sound_utils.hpp"

using namespace std;

double utils::create_chord(double half_steps){
    const double a4_frequency = 440;

    return pow(2, half_steps/12) * a4_frequency;
}
