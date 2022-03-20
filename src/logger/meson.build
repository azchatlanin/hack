headers = ['logger.hpp']
sources = ['logger.cpp']

lib = library(
  'logger',
  include_directories : inc,
  install : true,
  sources: [headers, sources]
)

logger_dep = declare_dependency(
  include_directories: inc,
  link_with: lib
)
