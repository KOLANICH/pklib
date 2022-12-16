#include "pklib.h"

//-----------------------------------------------------------------------------
// Export exploding struct sizes
struct ExplodeSizeConstants getExplodeSizeConstants(){
    struct ExplodeSizeConstants res;
    res.own_size = sizeof(struct ExplodeSizeConstants);
    res.internal_struct_size = EXP_BUFFER_SIZE;
    res.IN_BUFF_SIZE = IN_BUFF_SIZE;
    res.CODES_SIZE = CODES_SIZE;
    res.OFFSS_SIZE = OFFSS_SIZE;
    res.OFFSS_SIZE1 = OFFSS_SIZE1;
    res.CH_BITS_ASC_SIZE = CH_BITS_ASC_SIZE;
    res.LENS_SIZES = LENS_SIZES;
    return res;
}
