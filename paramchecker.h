#pragma once
#include <vector>
// Update list of possible parameters
typedef enum VitalCheckParamType
{
	C_BPM = 0,
	C_SPO2,
	C_RESPRATE,
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

bool vitalsAreOk(std::vector<VitalCheckDetails> vitalDetails);
