#include <string>
#include <iostream>
#include <memory>

#include <stdio.h>
#include <stdint.h>

#include <fileTestSuite/fileTestSuite.h>
#include <fileTestSuite/fileTestSuiteRunner.hpp>

//#include <fileTestSuite/fileTestSuite.h>

struct TestParamz {
	OutputBufferTester &outBuffTester;
	FTSSpanT &input_span;
	size_t readPos = 0;
};

struct IPKLibTestingContext: public TesteeSpecificContext{
	std::vector<uint8_t> workBuf;
	uint32_t resultCode = 0;

	IPKLibTestingContext(size_t internalStructSize, bool shouldSwapChallengeResponse);

	virtual ~IPKLibTestingContext() = default;
	virtual void verifyAxillaryResults(FTSTestToolkit* ctx) override;
};

struct ExplodeTestingContext: public IPKLibTestingContext{
	ExplodeTestingContext();

	virtual ~ExplodeTestingContext() = default;

	virtual void executeTestee(pseudospan &challenge_data_span, OutputBufferTester &outBuffTester) override;
};

struct ImplodeTestingContext: public IPKLibTestingContext{
	ImplodeTestingContext();

	virtual ~ImplodeTestingContext() = default;

	virtual void executeTestee(pseudospan &challenge_data_span, OutputBufferTester &outBuffTester) override;
};

unsigned int inf(char *buf, unsigned int *size, void *param);

void outf(char *buf, unsigned  int *size, void *param);
