
#include <map>
#include <algorithm>
#include "paramchecker.h"

// Create a lookup table with paramtype as key
// Add boundary values for all possible parameters
std::map<VitalCheckParamType, VitalBoundaryValues> vitalCheckBoundaryValues=
{
	{C_BPM, { 70,150 }},
	{C_SPO2,{ 80,100 } },
	{C_RESPRATE,{ 30,60 } }
};

bool checkmin(float rcvValue, float min)
{
	// -0.1 for float comparison
	return (rcvValue < (min - 0.1));
}

bool checkmax(float rcvValue, float max)
{
	// +0.1 for float comparison
	return (rcvValue > (max + 0.1));
}

// Receive list of parameter and value to be checked
bool vitalsAreOk(std::vector<VitalCheckDetails> vitalDetails)
{
	std::vector<bool> result;
	for (auto vital : vitalDetails)
	{
		result.emplace_back(checkmin(vital.value, vitalCheckBoundaryValues[vital.paramType].min) && checkmax(vital.value, vitalCheckBoundaryValues[vital.paramType].max));
	}
    return std::none_of(result.begin(), result.end(), [](bool result) {return result != true;});
}
