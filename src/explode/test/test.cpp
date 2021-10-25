#include "tests.hpp"
#include "pklib.h"

auto esc = getExplodeSizeConstants();

ExplodeTestingContext::ExplodeTestingContext(): IPKLibTestingContext(esc.internal_struct_size, true){}

void ExplodeTestingContext::executeTestee(pseudospan &challenge_data_span, OutputBufferTester &outBuffTester){
	TestParamz p{
		.outBuffTester=outBuffTester,
		.input_span=challenge_data_span,
	};
	this->resultCode = explode(inf, outf, reinterpret_cast<char *>(workBuf.data()), (void*) &p);
}


TesteeSpecificContext* testeeSpecificContextFactory(){
	return new ExplodeTestingContext();
	//return new ImplodeTestingContext();
}
