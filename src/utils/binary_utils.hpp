#include <fstream>

namespace utils{
    
    template <typename Word>
    void write_word( std::ostream& out_stream, Word value, unsigned size = sizeof(Word) ){

        unsigned char *byte_array = reinterpret_cast<unsigned char *>(&value);

        for(int i = 0; size > 0; size--, i++){
            out_stream.put(static_cast<char> (byte_array[i] & 0xFF));
        }

    }

};
