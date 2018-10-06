PROJECT(OcctBeginner)

INCLUDE_DIRECTORIES(
	${CASROOT}/inc
	.
    )
LINK_DIRECTORIES(${CASROOT}/win64/vc10/lib)

FILE(GLOB PROJECT_SOURCE_FILES *.txt)
FILE(GLOB PROJECT_SOURCE_FILES ${PROJECT_SOURCE_FILES}
	./*.h
	./*.rc
    ./*.cpp
	./*.reg
    )

ADD_DEFINITIONS(-D_AFXDLL -D_UNICODE)
SET(CMAKE_MFC_FLAG 2)

ADD_EXECUTABLE(OcctBeginner WIN32 ${PROJECT_SOURCE_FILES})
SET(EXECUTABLE_OUTPUT_PATH ${OUTPUT_DIR})



SET(OCCT_LIBS  TKernel
    TKMath
    TKG2d
    TKG3d
    TKGeomBase
    TKBRep
    TKGeomAlgo
    TKTopAlgo
    TKPrim
    TKShHealing
    TKBO
    TKBool
    TKFillet
    TKMesh
    TKFeat
    TKHLR
    TKOffset
    TKXMesh
    TKIGES
    TKSTEP
    TKXSBase
    TKSTL
    TKVRML
    TKService
    TKOpenGl
    TKV3d
)

target_link_libraries (OcctBeginner ${OCCT_LIBS})