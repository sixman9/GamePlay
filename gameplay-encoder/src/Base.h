#ifndef BASE_H_
#define BASE_H_

// C++ includes
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <cmath>
#include <cfloat>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <sys/stat.h>

// PNG
#include <png.h>

// Collada includes
#include <dae.h>
#include <dae/daeSIDResolver.h>
#include <dae/domAny.h>
#include <dom/domCOLLADA.h>
#include <dom/domConstants.h>
#include <dom/domElements.h>
#include <dom/domCamera.h>
#include <dom/domProfile_COMMON.h>

// Defines
#ifndef M_1_PI        
#define M_1_PI                      0.31830988618379067154
#endif
#define MATH_FLOAT_SMALL            1.0e-37f
#define MATH_TOLERANCE              2e-37f
#define MATH_E                      2.71828182845904523536f
#define MATH_LOG10E                 0.4342944819032518f
#define MATH_LOG2E                  1.442695040888963387f
#define MATH_PI                     3.14159265358979323846f
#define MATH_PIOOVER2               1.57079632679489661923f
#define MATH_PIOOVER4               M_PI_4
#define MATH_PIX2                   6.28318530717958647693f
#define MATH_EPSILON                0.000001f
#define MATH_DEG_TO_RAD(x)          ((x) * 0.0174532925f)
#define MATH_RAD_TO_DEG(x)          ((x)* 57.29577951f)
#define MATH_RANDOM_MINUS1_1()      ((2.0f*((float)rand()/RAND_MAX))-1.0f) // Returns a random float between -1 and 1.
#define MATH_RANDOM_0_1()           ((float)rand()/RAND_MAX) // Returns a random float between 0 and 1.

namespace gameplay
{

enum VertexUsage
{
    UNKNOWN = 0,
    POSITION = 1,
    NORMAL = 2,
    COLOR = 3,
    TANGENT = 4,
    BINORMAL = 5,
    BLENDWEIGHTS = 6,
    BLENDINDICES = 7,
    TEXCOORD0 = 8,
    TEXCOORD1 = 9,
    TEXCOORD2 = 10,
    TEXCOORD3 = 11,
    TEXCOORD4 = 12,
    TEXCOORD5 = 13,
    TEXCOORD6 = 14,
    TEXCOORD7 = 15
};

void fillArray(float values[], float value, size_t length);

/**
 * Returns the base name of the given path.
 * Example: "c:/foo/bar/model.dae" returns "model.dae"
 * 
 * @param filepath File path.
 * 
 * @return Base file name.
 */
std::string getBaseName(const std::string& filepath);

#define ISZERO(x) (fabs(x) < 0.000001f)

// Object deletion macro
#define SAFE_DELETE(x) \
    if (x) \
    { \
        delete x; \
        x = NULL; \
    }

#ifdef NDEBUG
#define DEBUGPRINT(x)
#define DEBUGPRINT_VARG(x, ...)
#else
#define DEBUGPRINT(x)  printf(x)
#define DEBUGPRINT_VARG(x, ...) printf(x, __VA_ARGS__)
#endif

}

#endif
