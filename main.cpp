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
  };
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
  
  //let's try to access a key that is not there
  CityRecord &CairoData = cityMap["Cairo"]; // in this situation it will not find the key and it will insert it to the map
  
  //but that can not happen with constants, so in this case we need to check if the key is already there before we access
  
  const auto& cities = cityMap;
  if(cities.find("Cairo") != cities.end())
  {
   const &CairoData = cityMap["Cairo"]; 
  }
  
  //now we can iterate through the map using a C++ 17 feature in ranged-based for loop that returns array of key,value pairs
  for(auto&[name,city] : cityMap)
   {
        std::cout<<name<<"\n Population: "<<city.Population<<std::endl;
   }
      
   //the above iterating works exactly as the one below
   for(auto &kv:cityMap)
   {
     const string & name = kv.first; //the name is the key
     CityRecord& city = kv.second; //the values
   }
}
