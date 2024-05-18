#define _AMD64_ 1
#define _KERNEL_MODE 1
extern "C" int _fltused = 0;

#include <ntifs.h>
#include <ntddk.h>
#include <intrin.h>
#include <ntimage.h>
#include <windef.h>
#include <ntstrsafe.h>
#include <ntdef.h>
#include <stdint.h>
#include <immintrin.h>
#include <cstdint>
#include <cstddef>
#include <utility>
#include <type_traits>

#include "globals.h"
#include "defines.h"
#include "utils.h"
