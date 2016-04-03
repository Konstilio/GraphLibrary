#ifndef CCycleAlgorithmResult_h
#define CCycleAlgorithmResult_h

#include <vector>

class CCycleAlgorithmResult
{
public:
    CCycleAlgorithmResult(CCycleAlgorithmResult const &_Other) = default;
    CCycleAlgorithmResult& operator=(CCycleAlgorithmResult const &_Other) = default;
    CCycleAlgorithmResult(CCycleAlgorithmResult &&_Other) = default;
    CCycleAlgorithmResult& operator=(CCycleAlgorithmResult &&_Other) = default;
    
    
    bool Cycle() const;
    
    const std::vector<uint32_t> &Path() const;
    
    template <class Graph, class Is>
    friend class TCCycleAlgorithm;
    
private:
    CCycleAlgorithmResult(bool _bCycle, std::vector<uint32_t> && _Path);
    
    bool mp_bCycle;
    std::vector<uint32_t> mp_Path;
};

#endif //CCycleAlgorithmResult_h