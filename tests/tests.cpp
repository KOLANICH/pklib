#include <string>
#include <iostream>
#include <memory>
#include <filesystem>

#include <stdio.h>

#include <fileTestSuite/fileTestSuite.h>
#include <fileTestSuite/fileTestSuiteRunner.hpp>
#include <stdint.h>

//#include <fileTestSuite/fileTestSuite.h>

#include "tests.hpp"

unsigned int inf(char *buf, unsigned int *size, void *param){
	auto *paramz = static_cast<TestParamz *>(param);
	auto & input_span = paramz->input_span;
	auto sizeToRead = std::min(input_span.size() - paramz->readPos, static_cast<size_t>(*size));

	auto subSpan = input_span.subspan(paramz->readPos, sizeToRead);

	std::copy(begin(subSpan), end(subSpan), buf);
	paramz->readPos += sizeToRead;
	return static_cast<unsigned int>(sizeToRead);
}

void outf(char *buf, unsigned  int *size, void *param){
	auto *paramz = static_cast<TestParamz *>(param);
	paramz->outBuffTester.testChunkProcessing(reinterpret_cast<uint8_t*>(buf), *size);
}

IPKLibTestingContext::IPKLibTestingContext(size_t internalStructSize, bool shouldSwapChallengeResponse): TesteeSpecificContext(), workBuf(internalStructSize, 0){
	this->shouldSwapChallengeResponse = shouldSwapChallengeResponse;
	workBuf.reserve(internalStructSize);
	workBuf.resize(internalStructSize);
}

//~IPKLibTestingContext::IPKLibTestingContext() = default;
void IPKLibTestingContext::verifyAxillaryResults(FTSTestToolkit* ctx) {
	ctx->tk->expectEqual(this->resultCode, 0u);
	//ctx->tk->expectEqual(this->left, 0u);
}
