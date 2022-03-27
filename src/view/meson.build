headers = ['color.hpp']
sources = []

lib = library(
  'view',
  include_directories : inc,
  sources: [headers, sources]
)

view_dep = declare_dependency(
  include_directories: inc,
  link_with: lib
)
