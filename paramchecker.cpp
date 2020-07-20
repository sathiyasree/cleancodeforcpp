
bool checkBpm(float bpm)
{
  bool retVal = true;
   if(bpm < 70 || bpm > 150) {
    retVal = false;
  }
  return retVal;
}
bool checkSp02(float spo2)
{
  bool retVal = true;
  if(spo2 < 80) {
    retVal = false;
  }
  return retVal;
}
bool checkRespRate(float respRate)
{
  bool retVal = true;
  if(respRate < 30 || respRate > 60) {
    retVal = false;
  }
  return retVal;
}
bool vitalsAreOk(float bpm, float spo2, float respRate) {
  bool retVal = true;
  retVal = checkBpm(bpm)&& checkSp02(spo2) && checkRespRate(respRate);
  return retVal;
}
