# Public headers

# Copy Egg::Registry library includes
FILE (
	COPY		"${CMAKE_CURRENT_SOURCE_DIR}/egg/registry/instance.hpp"
	DESTINATION	"${CMAKE_CURRENT_BINARY_DIR}/egg/registry" )

FILE (
	COPY		"${CMAKE_CURRENT_SOURCE_DIR}/egg/registry/value.hpp"
	DESTINATION	"${CMAKE_CURRENT_BINARY_DIR}/egg/registry" )

FILE (
	COPY		"${CMAKE_CURRENT_SOURCE_DIR}/egg/registry/version.hpp"
	DESTINATION	"${CMAKE_CURRENT_BINARY_DIR}/egg/registry" )

# Egg public includes
SET (
	Public_Include

	"${CMAKE_CURRENT_BINARY_DIR}/egg/registry/instance.hpp"
	"${CMAKE_CURRENT_BINARY_DIR}/egg/registry/value.hpp"
	"${CMAKE_CURRENT_BINARY_DIR}/egg/registry/version.hpp"

	CACHE INTERNAL "Common headers" )


# Install the Egg::Registry library
INSTALL(
	FILES		${Public_Include}
	DESTINATION	"${CMAKE_INSTALL_FULL_INCLUDEDIR}/egg/registry" )

# End of file
