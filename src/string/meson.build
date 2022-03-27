headers = ['string.hpp', 'string_concat_helper.hpp']
sources = ['string.cpp']

lib = library(
  'string',
  include_directories : inc,
  sources: [headers, sources]
)

string_dep = declare_dependency(
  include_directories: inc,
  link_with: lib
)
