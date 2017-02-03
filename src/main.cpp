#include "main.hpp"

using namespace std;

int main(){

    ofstream sound_file("test.wav", ios::binary);
 
    const int sample_rate = 44100;
    const int bit_rate = 16;
    const int volume = 32760;
    const int channels = 2;

    const double secs_per_chord = 1;

    sound_file << "RIFF----WAVEfmt ";
    utils::write_word(sound_file, 16, 4);
    utils::write_word(sound_file, 1, 2);
    utils::write_word(sound_file, channels, 2);
    utils::write_word(sound_file, sample_rate, 4);
    utils::write_word(sound_file, sample_rate * channels * bit_rate, 4);
    utils::write_word(sound_file, bit_rate * channels / 8, 2);
    utils::write_word(sound_file, bit_rate, 2);

    size_t data_chunks_pos = sound_file.tellp();
    sound_file << "data----";

    vector<double> doremi = { 3, 5, 7, 8, 10, 12, 14, 15, 14, 12, 10, 8, 7, 5, 3};

    int samples = sample_rate * secs_per_chord * 8;

    for( double a : doremi ){
        double chord_frequency = utils::create_chord(a);

        for(size_t i = 0; i < samples/doremi.size(); i++){
            double amplitude = (double)i / samples * volume;
            double value = sin((2*M_PI*i*chord_frequency) / sample_rate);
            utils::write_word(sound_file, int(amplitude * value), 2); // Crest
            utils::write_word(sound_file, int((volume - amplitude) * value), 2); //through
        }

    }

    size_t file_len = sound_file.tellp();

    sound_file.seekp( data_chunks_pos + 4 );
    utils::write_word(sound_file, file_len - data_chunks_pos + 8);

    sound_file.seekp(4);
    utils::write_word(sound_file, file_len - 8, 4);

    return 0;
}
