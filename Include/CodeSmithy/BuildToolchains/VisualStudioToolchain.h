/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildToolchains/blob/master/LICENSE.txt
*/

#ifndef _CODESMITHYIDE_BUILDTOOLCHAINS_VISUALSTUDIOTOOLCHAIN_H_
#define _CODESMITHYIDE_BUILDTOOLCHAINS_VISUALSTUDIOTOOLCHAIN_H_

#include <Ishiko/Errors/Error.h>
#include <string>

namespace CodeSmithy
{

class VisualStudioToolchain
{
public:
    VisualStudioToolchain();

    void build(const std::string& makefilePath, Ishiko::Error& error) const;

private:
    std::string m_devenvPath;
};

}

#include "linkoptions.h"

#endif
