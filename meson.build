project('cars', 'cpp', version : '0.1', default_options : ['cpp_std=c++17'])

cpp = meson.get_compiler('cpp')
inc_dirs = include_directories('include')

# Dependencies
mysqlclient_dep = cpp.find_library('mysqlclient', required : true)
cpprestsdk_dep = dependency('cpprestsdk', required : true, method : 'cmake', modules : ['cpprestsdk::cpprest'])
openssl_dep = dependency('openssl', required : true)

# Executable
executable('cars', 
  sources : [
    'src/main.cpp', 
    'src/controller.cpp', 
    'src/model.cpp', 
    'src/service.cpp'
  ],
  include_directories : inc_dirs,
  dependencies : [mysqlclient_dep, cpprestsdk_dep, openssl_dep],
  install : true
)
