/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildToolchains/blob/master/LICENSE.txt
*/

#include "CMakeGenerationOptions.h"

namespace CodeSmithy
{

CMakeGenerationOptions::CMakeGenerationOptions()
{
}

CMakeGenerationOptions::CMakeGenerationOptions(const std::string& generatorName,
    const std::map<std::string, std::string>& cacheEntries)
    : m_generatorName(generatorName), m_cacheEntries(cacheEntries)
{
}

const boost::optional<std::string>& CMakeGenerationOptions::generatorName() const
{
    return m_generatorName;
}

const std::map<std::string, std::string> CMakeGenerationOptions::cacheEntries() const
{
    return m_cacheEntries;
}

}
