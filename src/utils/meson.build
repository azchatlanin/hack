headers = ['utils.hpp']
sources = []

lib = library(
  'utils',
  include_directories : inc,
  install : true,
  sources: [headers, sources]
)

utils_dep = declare_dependency(
  include_directories: inc,
  link_with: lib
)
