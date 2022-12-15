#include "pklib/pklib.h"

//-----------------------------------------------------------------------------
// Export common struct sizes
struct CommonSizeConstants getCommonSizeConstants(){
    struct CommonSizeConstants res;
    res.own_size = sizeof(struct CommonSizeConstants);
    res.OUT_BUFF_SIZE = OUT_BUFF_SIZE;
	res.BUFF_SIZE = BUFF_SIZE;
    return res;
}
