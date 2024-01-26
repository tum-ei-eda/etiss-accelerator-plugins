#define ETISS_LIBNAME QVanillaAccelerator

#include "etiss/helper/CPUArchLibrary.h"
#include "etiss/helper/JITLibrary.h"
#include "etiss/helper/PluginLibrary.h"

#include "etiss/LibraryInterface.h"



#include "QVanillaAccelerator.h"


extern "C"
{

    // implement version function
    ETISS_LIBRARYIF_VERSION_FUNC_IMPL

    unsigned QVanillaAccelerator_countJIT() { return 0; }

    unsigned QVanillaAccelerator_countCPUArch() { return 0; }

    unsigned QVanillaAccelerator_countPlugin() { return 1; }

    const char *QVanillaAccelerator_nameJIT(unsigned index) { return 0; }

    const char *QVanillaAccelerator_nameCPUArch(unsigned index) { return 0; }

    const char *QVanillaAccelerator_namePlugin(unsigned index)
    {
        switch (index)
        {
        case 0:
            return "QVanillaAccelerator";
        }
        return 0;
    }

    etiss::JIT *QVanillaAccelerator_createJIT(unsigned index, std::map<std::string, std::string> options) { return 0; }

    etiss::CPUArch *QVanillaAccelerator_createCPUArch(unsigned index, std::map<std::string, std::string> options)
    {
        return 0;
    }

    etiss::Plugin *QVanillaAccelerator_createPlugin(unsigned index, std::map<std::string, std::string> options)
    {
        switch (index)
        {
        case 0:
        {
            etiss::Configuration cfg;
                cfg.config() = options;
                return new etiss::plugin::QVanillaAccelerator(cfg.get<uint64_t>("plugin.QVanillaAccelerator.baseaddr", 0x70000000));
        }
        }
        return 0;
    }

    void QVanillaAccelerator_deleteJIT(etiss::JIT *o) { delete o; }

    void QVanillaAccelerator_deleteCPUArch(etiss::CPUArch *o) { delete o; }

    void QVanillaAccelerator_deletePlugin(etiss::Plugin *o) { delete o; }
}

// not part of the example implementation
unsigned etiss::LibraryInterface::getCurrentLibraryVersion()
{
    return QVanillaAccelerator_etissversion();
}
