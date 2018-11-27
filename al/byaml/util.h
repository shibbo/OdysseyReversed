#pragma once

#include "types.h"

bool verifiByaml(u8 const *srcByaml);
bool verifiByamlHeader(u8 const *srcByaml);
bool verifiByamlStringTable(u8 const *srcByaml, bool endianessSwap);