#define ETISS_LIBNAME VanillaAccelerator

#include "etiss/helper/CPUArchLibrary.h"
#include "etiss/helper/JITLibrary.h"
#include "etiss/helper/PluginLibrary.h"

#include "etiss/LibraryInterface.h"



#include "VanillaAccelerator.h"


extern "C"
{

    // implement version function
    ETISS_LIBRARYIF_VERSION_FUNC_IMPL

    unsigned VanillaAccelerator_countJIT() { return 0; }

    unsigned VanillaAccelerator_countCPUArch() { return 0; }

    unsigned VanillaAccelerator_countPlugin() { return 1; }

    const char *VanillaAccelerator_nameJIT(unsigned index) { return 0; }

    const char *VanillaAccelerator_nameCPUArch(unsigned index) { return 0; }

    const char *VanillaAccelerator_namePlugin(unsigned index)
    {
        switch (index)
        {
        case 0:
            return "VanillaAccelerator";
        }
        return 0;
    }

    etiss::JIT *VanillaAccelerator_createJIT(unsigned index, std::map<std::string, std::string> options) { return 0; }

    etiss::CPUArch *VanillaAccelerator_createCPUArch(unsigned index, std::map<std::string, std::string> options)
    {
        return 0;
    }

    etiss::Plugin *VanillaAccelerator_createPlugin(unsigned index, std::map<std::string, std::string> options)
    {
        switch (index)
        {
        case 0:
        {
            etiss::Configuration cfg;
                cfg.config() = options;
                return new etiss::plugin::VanillaAccelerator(cfg.get<uint64_t>("plugin.VanillaAccelerator.baseaddr", 0x70001000));
        }
        }
        return 0;
    }

    void VanillaAccelerator_deleteJIT(etiss::JIT *o) { delete o; }

    void VanillaAccelerator_deleteCPUArch(etiss::CPUArch *o) { delete o; }

    void VanillaAccelerator_deletePlugin(etiss::Plugin *o) { delete o; }
}

// not part of the example implementation
unsigned etiss::LibraryInterface::getCurrentLibraryVersion()
{
    return VanillaAccelerator_etissversion();
}
