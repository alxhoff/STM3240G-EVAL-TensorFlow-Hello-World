SET(UTENSOR_SRC_PREFIX "src/uTensor")

SET(UTENSOR_CORE_PREFIX "core")
SET(UTENSOR_CORE_SRC_FILES
    context.cpp
    tensor.cpp
    uTensorBase.cpp
    vm.cpp
    )

SET(UTENSOR_CORE_HEADERS
    context.hpp
    sdtensor.hpp
    tensor.hpp
    uTensorBase.hpp
    vm.hpp
    )

SET(UTENSOR_LOADERS_PREFIX "loaders")
SET(UTENSOR_LOADERS_SRC_FILES
    tensorIdxImporter.cpp
    )

SET(UTENSOR_LOADERS_HEADERS
    tensorIdxImporter.hpp
    )

SET(UTENSOR_OPS_PREFIX "ops")
SET(UTENSOR_OPS_SRC_FILES
    MathOps.cpp
    NmOps.cpp
    )

SET(UTENSOR_CMSIS_OPS_HEADERS
    CmsisConvolution.hpp
    CmsisPoolingOps.hpp
    FullyConnectedOps.hpp
    activationOps.hpp
    softmax.hpp
    )

SET(UTENSOR_OPS_HEADERS
    ${UTENSOR_CMSIS_OPS_HEADERS}
    ArrayOps.hpp
    MathOps.hpp
    MatrixOps.hpp
    NnOps.hpp
    )

SET(UTENSOR_UTIL_PREFIX "util")
SET(UTENSOR_UTIL_SRC_FILES
    quantization_utils.cpp
    uTensor_util.cpp
    )

SET(UTENSOR_UTIL_HEADERS
    math_util.hpp
    quantization_utils.hpp
    uTensor_util.hpp
    utensor_string.hpp
    )

# SET(UTENSOR_SRC_FILES
#     ${UTENSOR_CORE_SRC_FILES}
#     ${UTENSOR_LOADERS_SRC_FILES}
#     ${UTENSOR_OPS_SRC_FILES}
#     ${UTENSOR_UTIL_SRC_FILES}
#     )
#
SET(UTENSOR_HEADERS
    ${UTENSOR_CORE_HEADERS}
    ${UTENSOR_LOADERS_HEADERS}
    ${UTENSOR_OPS_HEADERS}
    ${UTENSOR_UTIL_HEADERS}
    )

MESSAGE("uTensor headers: ${UTENSOR_HEADERS}")
MESSAGE("uTensor dir: ${uTensor_DIR}")

FOREACH(HEADER ${UTENSOR_HEADERS})
    MESSAGE("Finding: ${HEADER} in ${uTensor_DIR}/${UTENSOR_SRC_PREFIX}")
    FIND_PATH(FOUND_INC_DIR ${HEADER}
    # PATH_SUFFIXES ${UTENSOR_CORE_PREFIX}
    # PATH_SUFFIXES${UTENSOR_LOADERS_PREFIX} ${UTENSOR_OPS_PREFIX} ${UTENSOR_UTIL_PREFIX}
    PATHS ${uTensor_DIR}/${UTENSOR_SRC_PREFIX}
    CMAKE_FIND_ROOT_PATH_BOTH
    )
LIST(APPEND UTENSOR_COMMON_INC_DIR ${FOUND_INC_DIR})
MESSAGE("Found dir: ${FOUND_INC_DIR}")
ENDFOREACH()
LIST(REMOVE_DUPLICATES UTENSOR_COMMON_INC_DIR)

FOREACH(SRC ${FREERTOS_SRC_FILES})
    STRING(MAKE_C_IDENTIFIER "${SRC}" SRC_CLEAN)
    SET(UTENSOR_${SRC_CLEAN}_FILE UTENSOR_SRC_FILE-NOTFOUND)
    FIND_FILE(UTENSOR_${SRC_CLEAN}_FILE ${SRC}
        HINTS ${uTensor_DIR}/src/uTensor
        CMAKE_FIND_ROOT_PATH_BOTH
        )
    LIST(APPEND UTENSOR_SOURCES ${FREERTOS_${SRC_CLEAN}_FILE})
ENDFOREACH()

SET(uTensor_INCLUDE_DIRS
    ${UTENSOR_COMMON_INC_DIR}
    )

SET(uTensor_SOURCES
    ${UTENSOR_SOURCES}
    )

INCLUDE(FindPackageHandleStandardArgs)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(uTensor DEFAULT_MSG uTensor_INCLUDE_DIRS uTensor_SOURCES)
