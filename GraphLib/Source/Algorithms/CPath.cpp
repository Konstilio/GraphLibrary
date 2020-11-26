//
//  CPath.cpp
//  Graphs
//
//  Created by Oleksandr Konstantinov on 11/25/20.
//

#include "../../Include/Algorithms/CPath.h"

CPath::CPath(std::vector<uint32_t> const &_Path) : mp_Path(_Path) {
}

CPath::CPath(std::vector<uint32_t> &&_Path) : mp_Path(std::move(_Path)) {
    
}

CPath::CPath(std::initializer_list<uint32_t> _List) : mp_Path(_List) {
}

std::vector<uint32_t> const &CPath::Path() const {
    return mp_Path;
}

std::ostream& operator<<(std::ostream &_Os, const CPath &_Path) {
    _Os << "Path:[";
    const auto Size = _Path.Path().size();
    for (int i = 0; i < Size - 1; ++i) {
        const auto v = _Path.Path()[i];
        _Os << v << ", ";
    }
    
    _Os << _Path.Path()[Size - 1];
    _Os << ']';
    return _Os;
}
