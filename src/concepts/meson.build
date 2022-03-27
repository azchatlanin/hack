headers = ['concepts.hpp']
sources = []

lib = library(
  'concepts',
  include_directories : inc,
  sources: [headers, sources]
)

concepts_dep = declare_dependency(
  include_directories: inc,
  link_with: lib
)
