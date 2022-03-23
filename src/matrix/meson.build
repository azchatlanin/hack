headers = ['matrix.hpp']
sources = []

lib = library(
  'matrix',
  include_directories : inc,
  install : true,
  sources: [headers, sources]
)

matrix_dep = declare_dependency(
  include_directories: inc,
  link_with: lib
)
