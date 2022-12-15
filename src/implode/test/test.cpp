#include <pklib/implode.h>

#include "tests.hpp"

auto isc = getImplodeSizeConstants();

ImplodeTestingContext::ImplodeTestingContext(): IPKLibTestingContext(isc.internal_struct_size, false){}

void ImplodeTestingContext::executeTestee(pseudospan &challenge_data_span, OutputBufferTester &outBuffTester){
	TestParamz p{
		.outBuffTester=outBuffTester,
		.input_span=challenge_data_span,
	};
	unsigned int ctype = CMP_BINARY;
	unsigned int dict_size = CMP_IMPLODE_DICT_SIZE3;
	this->resultCode = implode(inf, outf, reinterpret_cast<char *>(workBuf.data()), (void*) &p, &ctype, &dict_size);
}

TesteeSpecificContext* testeeSpecificContextFactory(){
	return new ImplodeTestingContext();
}
