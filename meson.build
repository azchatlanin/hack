# https://pixorblog.wordpress.com/2019/07/27/a-meson-starter-script-for-c-projects
project(
  'hack', 
  'cpp', 
  version : '0.0.1', 
  default_options : ['cpp_std=c++2a']
)

add_project_arguments (
  '-pedantic', 
  '-Wno-comment',
  '-Wno-gnu-zero-variadic-macro-arguments',
  '-Wunused-but-set-variable',
  language: 'cpp'
)

args = []
deps = []

inc = []
inc += include_directories('.')

subdir('src')
subdir('bin')
subdir('tests')
