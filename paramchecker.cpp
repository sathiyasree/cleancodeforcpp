
bool checkBpm(float bpm)
{
   if(bpm < 70 || bpm > 150) {
    return false;
  }
  return true;
}
bool checkSp02(float spo2)
{
  if(spo2 < 80) {
    return false;
  }
  return true;
}
bool checkRespRate(float respRate)
{
  if(respRate < 30 || respRate > 60) {
   return false;
  }
  return true;
}
bool vitalsAreOk(float bpm, float spo2, float respRate) {
  bool retVal = checkBpm(bpm)&& checkSp02(spo2) && checkRespRate(respRate);
  return retVal;
}
