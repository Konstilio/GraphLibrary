#ifndef CPath_h
#define CPath_h

#include <vector>
#include <iostream>

class CPath {
    
public:
    CPath(std::vector<uint32_t> const &_Path);
    CPath(std::vector<uint32_t> &&_Path);
    CPath(std::initializer_list<uint32_t> _List);
    
    CPath(CPath const &_Other) = default;
    CPath& operator=(CPath const &_Other) = default;
    CPath(CPath &&_Other) = default;
    CPath& operator=(CPath &&_Other) = default;
    
    std::vector<uint32_t> const &Path() const;
    
private:
    std::vector<uint32_t> mp_Path;
};

std::ostream& operator<<(std::ostream& _Os, const CPath& _Path);

#endif /* CPath_h */
