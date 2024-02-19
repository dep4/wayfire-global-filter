project(
	'dep4',
	'c',
	'cpp',
	version: '0.8.0',
	license: 'MIT',
	meson_version: '>=0.51.0',
	default_options: [
		'cpp_std=c++17',
		'c_std=c11',
		'warning_level=3',
		'werror=true',
	],
)

wayfire = dependency('wayfire')
add_project_link_arguments(['-rdynamic'], language:'cpp')

shared_module('global-filter', 'global-filter.cpp',
    dependencies: [wayfire],
    )
