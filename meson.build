project('cars', 'cpp', version : '0.1', default_options : ['cpp_std=c++17'])

cpp = meson.get_compiler('cpp')
inc_dirs = include_directories('src/db_connection', 'src/controllers', 'src/services', 'src/models')

# Dependencies
mysqlclient_dep = cpp.find_library('mysqlclient', required : true)
cpprestsdk_dep = dependency('cpprestsdk', required : true, method : 'cmake', modules : ['cpprestsdk::cpprest'])
openssl_dep = dependency('openssl', required : true)

# Executable
executable('cars', 
  sources : [
    'src/main.cpp', 
    'src/db_connection/db_connection.cpp', 
    'src/controllers/car_controller.cpp', 
    'src/services/car_service.cpp', 
    'src/models/car_dto.cpp'
  ],
  include_directories : inc_dirs,  # Include directoarele cu fișiere .h
  dependencies : [mysqlclient_dep, cpprestsdk_dep, openssl_dep],
  install : true
)
