find_path(MySQL++_INCLUDE_DIR NAMES mysql++.h PATHS /usr/include/mysql++)

find_library(MySQL++_LIBRARY NAMES mysqlpp PATHS /usr/lib /usr/local/lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(MySQL++ DEFAULT_MSG
                                  MySQL++_LIBRARY MySQL++_INCLUDE_DIR)

if(MySQL++_FOUND)
  set(MySQL++_INCLUDE_DIRS ${MySQL++_INCLUDE_DIR})
  set(MySQL++_LIBRARIES ${MySQL++_LIBRARY})
endif()

mark_as_advanced(MySQL++_INCLUDE_DIR MySQL++_LIBRARY)
