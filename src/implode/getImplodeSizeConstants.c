#include "pklib.h"

//-----------------------------------------------------------------------------
// Export imploding struct sizes
struct ImplodeSizeConstants getImplodeSizeConstants(){
    struct ImplodeSizeConstants res;
    res.own_size = sizeof(struct ImplodeSizeConstants);
    res.internal_struct_size = CMP_BUFFER_SIZE;
    res.OFFSS_SIZE2 = OFFSS_SIZE2;
    res.LITERALS_COUNT = LITERALS_COUNT;
    res.HASHTABLE_SIZE = HASHTABLE_SIZE;
    return res;
}
