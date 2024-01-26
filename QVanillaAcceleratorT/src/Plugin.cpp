#define ETISS_LIBNAME QVanillaAcceleratorT

#include "etiss/helper/CPUArchLibrary.h"
#include "etiss/helper/JITLibrary.h"
#include "etiss/helper/PluginLibrary.h"

#include "etiss/LibraryInterface.h"



#include "QVanillaAcceleratorT.h"


extern "C"
{

    // implement version function
    ETISS_LIBRARYIF_VERSION_FUNC_IMPL

    unsigned QVanillaAcceleratorT_countJIT() { return 0; }

    unsigned QVanillaAcceleratorT_countCPUArch() { return 0; }

    unsigned QVanillaAcceleratorT_countPlugin() { return 1; }

    const char *QVanillaAcceleratorT_nameJIT(unsigned index) { return 0; }

    const char *QVanillaAcceleratorT_nameCPUArch(unsigned index) { return 0; }

    const char *QVanillaAcceleratorT_namePlugin(unsigned index)
    {
        switch (index)
        {
        case 0:
            return "QVanillaAcceleratorT";
        }
        return 0;
    }

    etiss::JIT *QVanillaAcceleratorT_createJIT(unsigned index, std::map<std::string, std::string> options) { return 0; }

    etiss::CPUArch *QVanillaAcceleratorT_createCPUArch(unsigned index, std::map<std::string, std::string> options)
    {
        return 0;
    }

    etiss::Plugin *QVanillaAcceleratorT_createPlugin(unsigned index, std::map<std::string, std::string> options)
    {
        switch (index)
        {
        case 0:
        {
            etiss::Configuration cfg;
                cfg.config() = options;
                return new etiss::plugin::QVanillaAcceleratorT(cfg.get<uint64_t>("plugin.QVanillaAcceleratorT.baseaddr", 0x70002000));

        }
        }
        return 0;
    }

    void QVanillaAcceleratorT_deleteJIT(etiss::JIT *o) { delete o; }

    void QVanillaAcceleratorT_deleteCPUArch(etiss::CPUArch *o) { delete o; }

    void QVanillaAcceleratorT_deletePlugin(etiss::Plugin *o) { delete o; }
}

// not part of the example implementation
unsigned etiss::LibraryInterface::getCurrentLibraryVersion()
{
    return QVanillaAcceleratorT_etissversion();
}
