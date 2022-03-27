inc += include_directories('.')

subdir('string')
subdir('logger')

deps += string_dep
deps += logger_dep

lib = library(
  'hack',
  include_directories : inc,
)

hack_dep = declare_dependency(
  include_directories: inc,
  link_with: lib
)
