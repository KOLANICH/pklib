#include "pklib.h"

//-----------------------------------------------------------------------------
// Export LUTs sizes
struct LUTSizeConstants getLUTSizeConstants(){
    struct LUTSizeConstants res;
    res.own_size = sizeof(struct LUTSizeConstants);
    res.DIST_SIZES = DIST_SIZES;
    res.CH_BITS_ASC_SIZE = CH_BITS_ASC_SIZE;
	res.LENS_SIZES = LENS_SIZES;
    return res;
}
