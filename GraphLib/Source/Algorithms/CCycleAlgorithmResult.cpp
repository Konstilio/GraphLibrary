#include "../../Include/Algorithms/CCycleAlgorithmResult.h"

CCycleAlgorithmResult::CCycleAlgorithmResult(bool _bCycle, std::vector<uint32_t> && _Path)
    : mp_bCycle(_bCycle)
    , mp_Path(std::move(_Path))
{}

bool CCycleAlgorithmResult::Cycle() const
{
    return mp_bCycle;
}

std::vector<uint32_t> const &CCycleAlgorithmResult::Path() const
{
    return mp_Path;
}

