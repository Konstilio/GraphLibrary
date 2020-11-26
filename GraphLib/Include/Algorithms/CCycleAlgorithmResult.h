#ifndef CCycleAlgorithmResult_h
#define CCycleAlgorithmResult_h

#include <vector>
#include "CPath.h"

class CCycleAlgorithmResult
{
public:
    CCycleAlgorithmResult(CCycleAlgorithmResult const &_Other) = default;
    CCycleAlgorithmResult& operator=(CCycleAlgorithmResult const &_Other) = default;
    CCycleAlgorithmResult(CCycleAlgorithmResult &&_Other) = default;
    CCycleAlgorithmResult& operator=(CCycleAlgorithmResult &&_Other) = default;
    
    
    bool Cycle() const;
    
    const CPath &Path() const;
    
    template <class Graph, class Is>
    friend class TCCycleAlgorithm;
    
private:
    CCycleAlgorithmResult(bool _bCycle, CPath &&_Path);
    
    bool mp_bCycle;
    CPath mp_Path;
};

#endif //CCycleAlgorithmResult_h
