gtest_proj = subproject('gtest')
gtest_dep = gtest_proj.get_variable('gtest_main_dep')

test(
  'split_str',
  executable(
    'split_str',
    'string.cpp',
    dependencies: [ deps, gtest_dep ]
  )
)

test(
  'within',
  executable(
    'within',
    'range.cpp',
    dependencies: [ deps, gtest_dep ]
  )
)

test(
  'container',
  executable(
    'container',
    'container.cpp',
    dependencies: [ deps, gtest_dep ]
  )
)
