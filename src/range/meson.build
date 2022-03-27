headers = ['range.hpp']
sources = ['range.cpp']

lib = library(
  'range',
  include_directories : inc,
  sources: [headers, sources]
)

range_dep = declare_dependency(
  include_directories: inc,
  link_with: lib
)
