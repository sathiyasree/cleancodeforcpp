#pragma once
#include <map>
#include <vector>
// Update list of possible parameters

typedef enum VitalCheckParamType
{
	C_BPM = 0,
	C_SPO2,
	C_RESPRATE
};

// to store the min and max of each parameter
struct VitalBoundaryValues
{
	float min;
	float max;
};

// type of input and value to be checked
struct VitalCheckDetails
{
	VitalCheckParamType paramType;
	float value;
};

// vital check results
typedef enum VitalCheckResultType
{
	C_NORMAL = 0,
	C_LESSER,
	C_HIGHER
};

struct VitalCheckResult
{
	VitalCheckParamType paramType;
	VitalCheckResultType result;
	VitalCheckResult(VitalCheckParamType paramType, VitalCheckResultType result) :paramType(paramType), result(result) {}
};

bool vitalsAreOk(std::vector<VitalCheckDetails> vitalDetails);
