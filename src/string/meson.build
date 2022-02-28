headers = ['string.hpp']
sources = ['string.cpp']

lib = library(
  'string',
  include_directories : inc,
  install : true,
  sources: [headers, sources]
)

string_dep = declare_dependency(
  include_directories: inc,
  link_with: lib
)
