# https://pixorblog.wordpress.com/2019/07/27/a-meson-starter-script-for-c-projects
project(
  'hack', 
  'cpp', 
  version : '0.0.1', 
  default_options : ['cpp_std=c++2a']
)

add_project_arguments (
  '-Wpedantic',
  '-Wshadow', 
  '-Wno-comment',
  #'-Wno-gnu-zero-variadic-macro-arguments',
  '-Wunused-but-set-variable',
  language: 'cpp'
)

compiler = meson.get_compiler('cpp')
if compiler.get_id() == 'gcc'
  message('Compiler: GCC')
elif compiler.get_id() == 'clang'
  message('Compiler: LLVM/clang')
endif

args = []
deps = []

inc = []
inc += include_directories('.')

subdir('src')
subdir('index')
subdir('bin')
subdir('tests')
