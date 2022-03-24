headers = ['vector.hpp', 'matrix.hpp']
sources = []

lib = library(
  'math',
  include_directories : inc,
  install : true,
  sources: [headers, sources]
)

math_dep = declare_dependency(
  include_directories: inc,
  link_with: lib
)
