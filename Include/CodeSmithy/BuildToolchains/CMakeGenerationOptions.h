/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildToolchains/blob/master/LICENSE.txt
*/

#ifndef _CODESMITHYIDE_BUILDTOOLCHAINS_CMAKEGENERATIONOPTIONS_H_
#define _CODESMITHYIDE_BUILDTOOLCHAINS_CMAKEGENERATIONOPTIONS_H_

#include <boost/optional/optional.hpp>
#include <map>
#include <string>

namespace CodeSmithy
{

class CMakeGenerationOptions
{
public:
    CMakeGenerationOptions();
    CMakeGenerationOptions(const std::string& generatorName, const std::map<std::string, std::string>& cacheEntries);

    const boost::optional<std::string>& generatorName() const;
    const std::map<std::string, std::string> cacheEntries() const;

private:
    boost::optional<std::string> m_generatorName;
    std::map<std::string, std::string> m_cacheEntries;
};

}

#endif
