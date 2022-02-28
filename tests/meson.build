gtest_proj = subproject('gtest')
gtest_dep = gtest_proj.get_variable('gtest_main_dep')

test(
  'split_str',
  executable(
    'split_str',
    'split_str.cpp',
    dependencies: [ string_dep, gtest_dep ]
  )
)
