project('cars', 'cpp', version : '0.1')

cpp = meson.get_compiler('cpp')
inc_dirs = include_directories('include')

deps = [
  cpp.find_library('mysqlclient', required : true)
]

executable('cars', sources : [
    'src/main.cpp', 
    'src/controller.cpp', 
    'src/model.cpp', 
    'src/service.cpp'
  ],
  include_directories : inc_dirs,
  dependencies : deps,
  install : true)
