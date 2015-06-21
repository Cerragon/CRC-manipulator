#include "CRCFactories.h"

std::unique_ptr<CRC> createCRC32()
{
    CRCSpecs specs   = {};
    specs.name       = "CRC32";
    specs.numBytes   = 4;
    specs.polynomial = 0x04C11DB7;
    specs.initialXOR = 0xFFFFFFFF;
    specs.finalXOR   = 0xFFFFFFFF;
    return std::unique_ptr<CRC>(new CRC(specs));
}

std::unique_ptr<CRC> createCRC16CCITT()
{
    CRCSpecs specs   = {};
    specs.name       = "CRC16CCITT";
    specs.numBytes   = 2;
    specs.polynomial = 0x1021;
    specs.initialXOR = 0x0000;
    specs.finalXOR   = 0x0000;
    return std::unique_ptr<CRC>(new CRC(specs));
}

std::unique_ptr<CRC> createCRC16IBM()
{
    CRCSpecs specs   = {};
    specs.name       = "CRC16IBM";
    specs.numBytes   = 2;
    specs.polynomial = 0x8005;
    specs.initialXOR = 0x0000;
    specs.finalXOR   = 0x0000;
    return std::unique_ptr<CRC>(new CRC(specs));
}

std::vector<std::shared_ptr<CRC>> createAllCRC()
{
    std::vector<std::shared_ptr<CRC>> crcs;
    crcs.push_back(createCRC32());
    crcs.push_back(createCRC16CCITT());
    crcs.push_back(createCRC16IBM());
    return crcs;
}
