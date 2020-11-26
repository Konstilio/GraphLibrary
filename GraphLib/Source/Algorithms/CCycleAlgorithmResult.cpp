#include "../../Include/Algorithms/CCycleAlgorithmResult.h"

CCycleAlgorithmResult::CCycleAlgorithmResult(bool _bCycle, CPath &&_Path)
    : mp_bCycle(_bCycle)
    , mp_Path(std::move(_Path))
{}

bool CCycleAlgorithmResult::Cycle() const
{
    return mp_bCycle;
}

CPath const &CCycleAlgorithmResult::Path() const
{
    return mp_Path;
}

