headers = ['vector.hpp']
sources = []

lib = library(
  'vector',
  include_directories : inc,
  install : true,
  sources: [headers, sources]
)

vector_dep = declare_dependency(
  include_directories: inc,
  link_with: lib
)
