#include "etiss/IntegratedLibrary/MemMappedPeriph.h"

#ifndef ETISS_PLUGIN_VANILLAACCELERATOR_H
#define ETISS_PLUGIN_VANILLAACCELERATOR_H

namespace etiss
{

namespace plugin
{


class VanillaAccelerator: public etiss::plugin::MemMappedPeriph
{
    public:

        VanillaAccelerator(uint64_t addr=0x70000000) : regIf{}, base_addr{addr} {}

        void write32(uint64_t addr, uint32_t val);

        uint32 read32(uint64_t addr);

        MappedMemory getMappedMem() const {
            MappedMemory mm;
            mm.base = base_addr;
            mm.size = sizeof(RegIF);
            return mm;
        }

    private:

        typedef struct regs 
        {
            uint32_t ifmap;   
            uint32_t weights; 
            uint32_t result;  
            uint32_t oc;      
            uint32_t iw;      
            uint32_t ih;      
            uint32_t ic;      
            uint32_t kh;      
            uint32_t kw;  
            uint32_t control;
        } regs_t;

        union RegIF
        {
            regs_t regs;
            uint32_t arr[sizeof(regs_t)/sizeof(uint32_t)];
        };
        RegIF regIf;
        
    protected:
        uint64_t base_addr;
        std::string _getPluginName() const;

};

} // namespace plugin

} // namespace etiss

#endif