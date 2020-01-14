# Define language
ENABLE_LANGUAGE ( CXX )

# Define includes
INCLUDE_DIRECTORIES (
  ${CMAKE_BINARY_DIR}/include
  ${EggPath}/include
  ${EggVariableIncludePath}
  )

# Version
CONFIGURE_FILE (
  ${CMAKE_CURRENT_SOURCE_DIR}/version.cpp.in
  ${CMAKE_CURRENT_BINARY_DIR}/version.cpp
  NEWLINE_STYLE UNIX )

# Sources
SET (
  Sources

  "value.cpp"
)

SET (
  SourcesFull

  ${CMAKE_CURRENT_BINARY_DIR}/version.cpp
  "value.cpp"
  "instance.cpp"
)

# Shared library
IF ( BUILD_SHARED_LIBS )

  ADD_LIBRARY (
    ${LibraryName} SHARED
    ${Sources}
    ${Public_Include} )

  SET_TARGET_PROPERTIES (
    ${LibraryName}		PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY	"${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY	"${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY	"${CMAKE_BINARY_DIR}/bin"
    COMPILE_FLAGS		"${EggCxxFlags}"
    LINK_FLAGS			"${EggLdFlags}"
    VERSION			"${ABIVersion}"
    SOVERSION			"${ABIMajor}" )

  ADD_LIBRARY (
    ${LibraryFullName} SHARED
    ${SourcesFull}
    ${Public_Include} )

  SET_TARGET_PROPERTIES (
    ${LibraryFullName}		PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY	"${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY	"${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY	"${CMAKE_BINARY_DIR}/bin"
    COMPILE_FLAGS		"${EggCxxFlags}"
    LINK_FLAGS			"${EggLdFlags}"
    VERSION			"${ABIVersion}"
    SOVERSION			"${ABIMajor}" )

ENDIF ()

# Static library
IF ( BUILD_STATIC_LIBS )

  ADD_LIBRARY (
    ${LibraryName}	STATIC
    ${Sources}
    ${PublicIncludes} )

  SET_TARGET_PROPERTIES (
    ${LibraryName}		PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY	"${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY	"${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY	"${CMAKE_BINARY_DIR}/bin"
    COMPILE_FLAGS		"${EggCxxFlags}" )

  ADD_LIBRARY (
    ${LibraryFullName}	STATIC
    ${SourcesFull}
    ${PublicIncludes} )

  SET_TARGET_PROPERTIES (
    ${LibraryFullName}		PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY	"${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY	"${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY	"${CMAKE_BINARY_DIR}/bin"
    COMPILE_FLAGS		"${EggCxxFlags}" )

ENDIF ()

# Libraries
TARGET_LINK_LIBRARIES ( ${LibraryName} "${VARIABLE_LIBRARY}" )
TARGET_LINK_LIBRARIES ( ${LibraryFullName} "${VARIABLE_LIBRARY}" )

# Install library
INSTALL (
  TARGETS     ${LibraryName} LIBRARY
  DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR} )

INSTALL (
  TARGETS     ${LibraryFullName} LIBRARY
  DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR} )

# End of file
