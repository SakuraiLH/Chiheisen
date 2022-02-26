#pragma once
#include <iostream>

const unsigned short MinChiheisenSoftwareVersion = 100;
const std::string ChiheisenSoftwareDistributionCodename = "Alexanderite";
const std::string ChiheisenSoftwareName = "Chihensen";
inline const std::string ChiheisenSoftwareVersionMainline = "1.0.0";
const std::string FullChiheisenSoftwareVersion = ChiheisenSoftwareName + ' '
                                               + ChiheisenSoftwareDistributionCodename + ' '
                                               + ChiheisenSoftwareVersionMainline + '/'
                                               + std::to_string(MinChiheisenSoftwareVersion);
                                               // e.g. Chihensen Alexanderite 1.0.0/100