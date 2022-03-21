headers = ['concepts.hpp']
sources = []

lib = library(
  'concepts',
  include_directories : inc,
  install : true,
  sources: [headers, sources]
)

concepts_dep = declare_dependency(
  include_directories: inc,
  link_with: lib
)
