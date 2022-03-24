headers = ['index.hpp']
sources = []

lib = library(
  'hack',
  include_directories : inc,
  install : true,
  sources: [headers, sources]
)

hack_dep = declare_dependency(
  include_directories: inc,
  link_with: lib
)
