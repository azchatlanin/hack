headers = ['container.hpp']
sources = ['container.cpp']

lib = library(
  'container',
  include_directories : inc,
  sources: [headers, sources]
)

container_dep = declare_dependency(
  include_directories: inc,
  link_with: lib
)
