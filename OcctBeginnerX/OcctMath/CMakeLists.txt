PROJECT(OcctMath)

INCLUDE_DIRECTORIES(
	${CASROOT}/inc
	.
    )
LINK_DIRECTORIES(${CASROOT}/win64/vc10/lib)

FILE(GLOB PROJECT_SOURCE_FILES *.txt)
FILE(GLOB PROJECT_SOURCE_FILES ${PROJECT_SOURCE_FILES}
	./*.h
    ./*.cpp
    )

ADD_DEFINITIONS(-D_UNICODE)

ADD_EXECUTABLE(OcctMath ${PROJECT_SOURCE_FILES})
SET(EXECUTABLE_OUTPUT_PATH ${OUTPUT_DIR})



SET(OCCT_LIBS  
    TKernel
    TKMath
)

target_link_libraries (OcctMath ${OCCT_LIBS})