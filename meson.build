project(
    'power-control', 
    'cpp',
    default_options: [
          'cpp_std=c++17'
        ],
    version: '0.1',
)

boost_args = [
        '-DBOOST_ASIO_DISABLE_THREADS',
        '-DBOOST_ALL_NO_LIB',
        '-DBOOST_SYSTEM_NO_DEPRECATED',
        '-DBOOST_ERROR_CODE_HEADER_ONLY',
        '-DBOOST_COROUTINES_NO_DEPRECATION_WARNING'
]

cpp = meson.get_compiler('cpp')

cppfs = cpp.find_library('stdc++fs')
boost_asio_dep = dependency('boost', modules : ['system', 'coroutine', 'date_time', 'thread'])
sdbusplus_dep = dependency('sdbusplus')
phosphor_logging = dependency('phosphor-logging')
phosphor_dbus_interfaces = dependency('phosphor-dbus-interfaces')
libsystemd_dep = dependency('libsystemd')
systemd = dependency('systemd')

deps = [
    cppfs,
    boost_asio_dep,
    sdbusplus_dep,
    phosphor_logging,
    libsystemd_dep,
]

systemd_system_unit_dir = systemd.get_pkgconfig_variable(
    'systemdsystemunitdir',
    define_variable: ['prefix', get_option('prefix')])

configure_file(
    copy: true,
    input: 'service_files/xyz.openbmc_project.Chassis.Control.Power.service',
    install: true,
    install_dir: systemd_system_unit_dir,
    output: 'xyz.openbmc_project.Chassis.Control.Power.service'
)

configure_file(
    copy: true,
    input: 'service_files/chassis-system-reset.service',
    install: true,
    install_dir: systemd_system_unit_dir,
    output: 'chassis-system-reset.service'
)

configure_file(
    copy: true,
    input: 'service_files/chassis-system-reset.target',
    install: true,
    install_dir: systemd_system_unit_dir,
    output: 'chassis-system-reset.target'
)

configure_file(
    copy: true,
    input: 'power-config-host0.json',
    install: true,
    install_dir: '/usr/share/power-control/',
    output: 'power-config-host0.json'
)

executable(
    'power-control', 
    'power_control.cpp','i2c.cpp','i2c.hpp',  
    cpp_args: boost_args,
    link_args: '-li2c',
    dependencies: deps,
    install:true,
    install_dir: get_option('bindir')
)