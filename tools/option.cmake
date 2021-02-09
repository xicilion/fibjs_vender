find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
	set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
	set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif(CCACHE_FOUND)

include(${CMAKE_CURRENT_LIST_DIR}/option_flags.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/option_config.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/option_libs.cmake)