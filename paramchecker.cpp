#include <algorithm>
#include "paramchecker.h"

// Create a lookup table with paramtype as key
// Add boundary values for all possible parameters
std::map<VitalCheckParamType, VitalBoundaryValues> vitalCheckBoundaryValues =
{
	{ C_BPM,{ 70,150 } },
	{ C_SPO2,{ 80,100 } },
	{ C_RESPRATE,{ 30,60 } }
};

VitalCheckResultType checkmin(float rcvValue, float min)
{
	// -0.1 for float comparison
	return (rcvValue < (min - 0.1) ? C_LESSER : C_NORMAL);
}

VitalCheckResultType checkmax(float rcvValue, float max)
{
	// +0.1 for float comparison
	return (rcvValue >(max + 0.1) ? C_HIGHER : C_NORMAL);
}

VitalCheckResult checkvitalParamRange(VitalCheckDetails vitaldetail)
{
	VitalCheckResultType checkresult;
	checkresult = checkmin(vitaldetail.value, vitalCheckBoundaryValues[vitaldetail.paramType].min);
	if (checkresult != C_LESSER)
	{
		checkresult = checkmax(vitaldetail.value, vitalCheckBoundaryValues[vitaldetail.paramType].max);
	}
	return (VitalCheckResult(vitaldetail.paramType, checkresult));
}

bool vitalsAreOk(std::vector<VitalCheckDetails> vitalDetails)
{
	std::vector<VitalCheckResult> result;
	for (auto vital : vitalDetails)
	{		
		result.emplace_back(checkvitalParamRange(vital));
	}
    return std::none_of(result.begin(), result.end(), [](VitalCheckResult result) {return result.result != false;});
}
