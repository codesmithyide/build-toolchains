/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildToolchains/blob/master/LICENSE.txt
*/

#include "VisualStudioToolchain.h"
#include "BuildToolchainErrorCategory.h"
#include <Ishiko/Process/ChildProcessBuilder.h>

using namespace Ishiko;
using namespace Ishiko::Process;

namespace CodeSmithy
{

VisualStudioToolchain::VisualStudioToolchain()
    : m_devenvPath("C:/Program Files (x86)/Microsoft Visual Studio/2017/Community/Common7/IDE/devenv.exe")
{
}

void VisualStudioToolchain::build(const std::string& makefilePath) const
{
    std::string commandLine = m_devenvPath;
    commandLine.append(" ");
    commandLine.append(makefilePath);
    commandLine.append(" /build ");
    commandLine.append("Debug|x64");

    ChildProcess processHandle = ChildProcessBuilder::StartProcess(commandLine);
    processHandle.waitForExit();
    int exitCode = processHandle.exitCode();
    if (exitCode != 0)
    {
        Throw(BuildToolchainErrorCategory::eBuildError, "Process launched by " + commandLine + " exited with code "
            + std::to_string(exitCode), __FILE__, __LINE__);
    }
}

void VisualStudioToolchain::build(const std::string& makefilePath, Error& error) const noexcept
{
    std::string commandLine = m_devenvPath;
    commandLine.append(" ");
    commandLine.append(makefilePath);
    commandLine.append(" /build ");
    commandLine.append("Debug|x64");

    ChildProcess processHandle = ChildProcessBuilder::StartProcess(commandLine, error);
    if (!error)
    {
        processHandle.waitForExit();
        int exitCode = processHandle.exitCode();
        if (exitCode != 0)
        {
            Fail(error, BuildToolchainErrorCategory::eBuildError, "Process launched by " + commandLine
                + " exited with code " + std::to_string(exitCode), __FILE__, __LINE__);
        }
    }
}

void VisualStudioToolchain::build(const std::string& makefilePath, const Environment& environment) const
{
    std::string commandLine = m_devenvPath;
    commandLine.append(" ");
    commandLine.append(makefilePath);
    commandLine.append(" /build ");
    commandLine.append("Debug|x64");

    ChildProcess processHandle = ChildProcessBuilder::StartProcess(commandLine, environment);
    processHandle.waitForExit();
    int exitCode = processHandle.exitCode();
    if (exitCode != 0)
    {
        Throw(BuildToolchainErrorCategory::eBuildError, "Process launched by " + commandLine + " exited with code "
            + std::to_string(exitCode), __FILE__, __LINE__);
    }
}

}
