headers = ['sequence_ostream_iterator.hpp', 'associative_ostream_iterator.hpp']
sources = []

lib = library(
  'iterators',
  include_directories : inc,
  sources: [headers, sources]
)

iterators_dep = declare_dependency(
  include_directories: inc,
  link_with: lib
)
