#pragma once

#include "BaseEntity.h"

class ClientEntityList {
public:
    constexpr BaseEntity* getClientEntity(int index) noexcept
    {
        return callVirtualFunction<BaseEntity*(__thiscall*)(void*, int)>(this, 3)(this, index);
    }
};
