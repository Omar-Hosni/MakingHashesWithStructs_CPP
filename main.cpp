#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

struct CityRecord
{
  std::string Name;
  unit64_t Population;
  double Latitude, Longitude;
};

namespace std
{
  template<>
  struct hash<CityRecord>
  {
  size_t operator()(const CityRecord& key)
  {
    return hash<std::string>()(key.Name);
  }
  }
}


int main()
{
  //a map that uses a struct as a key, and year found as a value
  std::unordered_map<CityRecord, unit32_t> foundedMap;
  
  foundedMap[CityRecord {"Berlin", 500000, 2.5, 9.5}] = 1237;
  foundedMap[CityRecord {"Amsterdam", 500000, 2.5, 9.5}] = 1275;
  
  //now let's say you want to retrieve the year of when was Amsterdam founded
  unit32_t AmsterdamFounded = foundedMap[CityRecord{"Amsterdam",500000, 2.5, 9.5}];
  
  
  //normal map using string as key
  std::unordered_map<std::string, CityRecord> cityMap;
  cityMap["Berlin"] = CityRecord {"Berlin", 500000, 2.5, 9.5};
  cityMap["Paris"] = CityRecord {"Paris", 500000, 2.5, 9.5};
  cityMap["London"] = CityRecord {"London", 500000, 2.5, 9.5};
  
  CityRecord& berlinData = cityMap["Berlin"];
  berlinData.Population;
  
  
}
